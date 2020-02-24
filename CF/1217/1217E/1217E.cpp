#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int MAXN = 200005;

int pw10[10], n;
int single[4 * MAXN][10], pairSum[4 * MAXN][10];
int a[MAXN];

int calcDigit(int x, int pos) {
    return x / pw10[pos] % 10;
}

void merge(int _single[], int _pairSum[], int _lSingle[], int _rSingle[], int _lPairSum[], int _rPairSum[]) {
    FOR (i, 0, 8) {
        _single[i] = min(_lSingle[i], _rSingle[i]);
        _pairSum[i] = min(_lPairSum[i], _rPairSum[i]);
        if (max(_lSingle[i], _rSingle[i]) < INF) {
            _pairSum[i] = min(_pairSum[i], _lSingle[i] + _rSingle[i]);
        }
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        FOR (i, 0, 8) {
            if (calcDigit(a[l], i)) single[id][i] = a[l];
            else single[id][i] = INF; 
            pairSum[id][i] = INT_MAX; 
        }
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(single[id], pairSum[id], single[id * 2], single[id * 2 + 1], pairSum[id * 2], pairSum[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v) {
    if (l == r) {
        FOR (i, 0, 8) {
            if (calcDigit(v, i)) {
                single[id][i] = v;
            }
            else single[id][i] = INF;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) update(id * 2, l, mid, u, v);
    else update(id * 2 + 1, mid + 1, r, u, v);

    merge(single[id], pairSum[id], single[id * 2], single[id * 2 + 1], pairSum[id * 2], pairSum[id * 2 + 1]);
}

void getAns(int id, int l, int r, int u, int v, int _single[], int _pairSum[]) {
    if (v < l || r < u) {
        FOR (i, 0, 8) _single[i] = INF;
        FOR (i, 0, 8) _pairSum[i] = INT_MAX;
        return;
    }
    if (u <= l && r <= v) {
        FOR (i, 0, 8) {
            _single[i] = single[id][i];
            _pairSum[i] = pairSum[id][i];
        }
        // cout << l << " " << r << ": \n";
        // FOR (i, 0, 8) {
        //     cout << _single[i] << " ";
        // }
        // cout << endl;
        // FOR (i, 0, 8) {
        //     cout << _pairSum[i] << " ";
        // }
        // cout << endl;
        return;
    } 

    int mid = (l + r) / 2;
    int _lSingle[9], _rSingle[9], _lPairSum[9], _rPairSum[9]; 

    getAns(id * 2, l, mid, u, v, _lSingle, _lPairSum);
    getAns(id * 2 + 1, mid + 1, r, u, v, _rSingle, _rPairSum);
    merge(_single, _pairSum, _lSingle, _rSingle, _lPairSum, _rPairSum);

    // cout << l << " " << r << ": \n";
    // FOR (i, 0, 8) {
    //     cout << _single[i] << " ";
    // }
    // cout << endl;
    // FOR (i, 0, 8) {
    //     cout << _pairSum[i] << " ";
    // }
    // cout << endl;

}

int getAns(int l, int r) {
    int _single[9], _pairSum[9];
    getAns(1, 1, n, l, r, _single, _pairSum);
    int res = INT_MAX;
    FOR (i, 0, 8) {
        res = min(res, _pairSum[i]);
    }
    if (res < INT_MAX) return res;
    return -1;
}
int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    pw10[0] = 1;
    FOR (i, 1, 8) pw10[i] = pw10[i - 1] * 10;

    int m;
    cin >> n >> m;

    FOR (i, 1, n) {
        int x;
        cin >> a[i];
    }

    build(1, 1, n);

    FOR (z, 1, m) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << getAns(l, r) << "\n";
        }
    }

    return 0;
}