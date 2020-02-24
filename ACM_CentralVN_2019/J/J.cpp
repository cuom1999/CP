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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;


int L = 1, R = 0;

int n, S, q;
    
int a[50005], cnt[50005];
struct Query{
    int l, r, stt, x, y;
}Q[50005];

int cmp(Query a, Query b) {
    if(a.l / S != b.l / S) return (a.l < b.l);
    return ((a.l / S) & 1) ? (a.r < b.r) : (a.r > b.r);
}

int ans = 0;

int fen[50005];

void addFen(int u, int v) {
    if (!u) return;
    for (int i = u; i <= 50000; i += i & -i) {
        fen[i] += v;
    }
}

int getSum(int u) {
    int res = 0;
    for (int i = u; i; i -= i & -i) {
        res += fen[i];
    }
    return res;
}

int res[50005];
int tmp[50005];
bool vs[50005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    sf("%d", &n);
    FOR (i, 1, n) sf("%d", &a[i]);

    sf("%d", &q);
    FOR (i, 1, q) {
        sf("%d %d %d %d", &Q[i].l, &Q[i].r, &Q[i].x, &Q[i].y);
        Q[i].stt = i;
    }
    S = n / sqrt(q) + 1; // optimal when S = n/sqrt(q);
    
    sort(Q + 1, Q + q + 1, cmp);

    vector<II> v;
    FOR (i, 1, n) {
        v.pb({a[i], i});
    }
    sort(all(v));

    int curInd = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!i || v[i].first != v[i - 1].first) {
            curInd++;
        }
        a[v[i].second] = curInd;
    }


    FOR (i, 1, q) {
        vector<int> sub, add;
        
        for (int j = L; j < Q[i].l; j++) {
            sub.pb(a[j]);
            // cout << j << endl;
        }

        for (int j = L - 1; j >= Q[i].l; j--) {
            add.pb(a[j]);
            // cout << j << endl;
        }

        FOR (j, R + 1, Q[i].r) {
            add.pb(a[j]);
            // cout << j << endl;
        }

        FORD (j, R, Q[i].r + 1) {
            sub.pb(a[j]);
            // cout << j << endl;
        }

        L = Q[i].l;
        R = Q[i].r;

        for (auto j: add) {
            tmp[j]++;
        }
        for (auto j: sub) {
            tmp[j]--;
        }

        vector<int> allNum;
        for (auto j: add) {
            if (!vs[j]) {
                allNum.pb(j);
                vs[j] = 1;
            }
        }
    
        for (auto j: sub) {
            if (!vs[j]) {
                allNum.pb(j);
                vs[j] = 1;
            }
        }

        for (auto j: allNum) {
            // cout << j << " " << cnt[j] << " " << tmp[j] << endl;
            addFen(cnt[j], -1);
            cnt[j] += tmp[j];
            addFen(cnt[j], 1);
            tmp[j] = 0;
            vs[j] = 0;
        }
        res[Q[i].stt] = getSum(Q[i].y) - getSum(Q[i].x - 1);
    }

    FOR (i,1,q) pf("%d \n", res[i]);

    return 0;
}