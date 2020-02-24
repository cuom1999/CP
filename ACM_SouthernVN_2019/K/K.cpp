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

struct BIT {
    vector<int> fen;
    BIT() {
        fen.resize(1000001);
    }
    void add(int u, int v) {
        for (int i = u; i <= 1000000; i += i & -i) {
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
};

struct Solver {
    vector<int>a;
    int n;

    BIT fen;

    void setN(int n) {
        this->n = n;
        a.resize(n + 2);
    }

    ll solve() {
        vector<int> st, st2;
        vector<int> g(n + 1), f(n + 1);
        vector<int> queries[1000005];

        a[0] = INF;
        st.pb(0);

        FOR (i, 1, n) {
            while (a[i] > a[st.back()]) {
                st.pop_back();
            }
            g[i] = st.back() + 1; 
            st.pb(i);
            queries[g[i]].pb(i);
        }

        a[n + 1] = -INF;
        st2.pb(n + 1);
        FORD (i, n, 1) {
            while (a[i] < a[st2.back()]) {
                st2.pop_back();
            }
            f[i] = st2.back() - 1;
            st2.pb(i);
        }

        ll res = 0;
        FOR (i, 1, n) {
            for (auto j: queries[i]) {
                fen.add(j, 1);
            }

            res += fen.getSum(f[i]) - fen.getSum(i - 1);
        }

        return res;
    }
}s1, s2;

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    FOR (i, 1, n) cin >> a[i];

    a.resize(n + 1);
    s1.setN(n);
    s2.setN(n);

    FOR (i, 1, n) {
        s1.a[i] = a[i];
        s2.a[i] = -a[i];
    }

    cout << s1.solve() + s2.solve() - n << endl;

    return 0;
}