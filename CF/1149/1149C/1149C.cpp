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

struct Node {
    int min, max, diameter, leftMinInd, rightMinInd, leftMax, rightMax, cenMax;
    int lazy;
} st[4 * 200005];

void merge(int id) {
    int l = id * 2, r = id * 2 + 1;
    st[id].min = min(st[l].min, st[r].min);
    st[id].max = max(st[l].max, st[r].max);
    if (st[l].min < st[r].min) {
        st[id].leftMinInd = st[l].leftMinInd;
        st[id].rightMinInd = st[l].rightMinInd;
        st[id].leftMax = st[l].leftMax;
        st[id].rightMax = max(st[l].rightMax, st[r].max);
        st[id].cenMax = st[l].cenMax;
        
        st[id].diameter = max(st[l].diameter, st[r].diameter);
        if (st[l].min == 0 || 1) {
            int val = max(st[l].cenMax, st[l].leftMax) + max(st[r].max, st[l].rightMax);
            st[id].diameter = max(st[id].diameter, val);
        }
    }
    else if (st[l].min > st[r].min) {
        st[id].leftMinInd = st[r].leftMinInd;
        st[id].rightMinInd = st[r].rightMinInd;
        st[id].leftMax = max(st[l].max, st[r].leftMax);
        st[id].rightMax = st[r].rightMax;
        st[id].cenMax = st[r].cenMax;

        st[id].diameter = max(st[l].diameter, st[r].diameter);
        if (st[r].min == 0 || 1) {
            int val = max(st[r].cenMax, st[r].rightMax) + max(st[l].max, st[r].leftMax);
            st[id].diameter = max(st[id].diameter, val);
        }
    }
    else {
        st[id].leftMinInd = st[l].leftMinInd;
        st[id].rightMinInd = st[r].rightMinInd;
        st[id].leftMax = st[l].leftMax;
        st[id].rightMax = st[r].rightMax;
        int tmp1 = max(st[l].rightMax, st[l].cenMax);
        int tmp2 = max(st[r].leftMax, st[l].cenMax);
        st[id].cenMax = max(tmp1, tmp2);

        st[id].diameter = max(st[l].diameter, st[r].diameter);
        if (st[l].min == 0 || 1) {
            vector<int> val;
            val.pb(max(st[l].leftMax, st[l].cenMax));
            val.pb(max(st[l].rightMax, st[r].leftMax));
            val.pb(max(st[r].cenMax, st[r].rightMax));
            sort(all(val));
            st[id].diameter = max(st[id].diameter, val[1] + val[2]);
        }
    }
}

int s[200005];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].min = st[id].max = st[id].leftMax = st[id].rightMax = st[id].cenMax = s[l];
        st[id].diameter = s[l];
        st[id].leftMinInd = st[id].rightMinInd = l;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(id);
}
 
void down(int id, int l, int r) {
    if (!st[id].lazy || l == r) return;
    int lz = st[id].lazy;
    FOR (r, 0, 1) {
        int i = id * 2 + r;
        st[i].min += lz;
        st[i].max += lz;
        st[i].leftMax += lz;
        st[i].cenMax += lz;
        st[i].rightMax += lz;
        st[i].diameter += lz;
        st[i].lazy += lz;
    }
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u || v < u) return;
    if (u <= l && r <= v) {
        st[id].min += k;
        st[id].max += k;
        st[id].leftMax += k;
        st[id].cenMax += k;
        st[id].rightMax += k;
        st[id].diameter += k;
        st[id].lazy += k;   
        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);

    merge(id); 
}

void get(int id, int l, int r) {
    if (l != r) {
        down(id, l, r);
        int mid = (l + r) / 2;
        get(id * 2, l, mid);
        get(id * 2 + 1, mid + 1, r);
    }
    cout << l << " " << r << " " << st[id].diameter << endl;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    n = 2 * (n - 1);

    string paren;
    cin >> paren;

    FOR (i, 0, n - 1) {
        if (paren[i] == '(') {
            s[i + 1] = s[i] + 1;
        }
        else {
            s[i + 1] = s[i] - 1;
        }
    }

    build(1, 1, n);
    paren = '0' + paren;

    get(1, 1, n);
    cout << st[1].diameter << "\n";
    FOR (z, 1, q) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        if (paren[l] != paren[r]) {
            if (paren[l] == '(') {
                update(1, 1, n, l, r - 1, -2);
            }
            else {
                update(1, 1, n, l, r - 1, 2);
            }
        }
        swap(paren[l], paren[r]);
        get(1, 1, n);
        cout << st[1].diameter << "\n";
    }


    return 0;
}