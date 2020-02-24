#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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

bitset<55> a[100005], res;

map<ll, int> vs;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(gen);
}

ll solve(int n, int m) {
    FOR (i, 1, n) {
        ll val = 0;
    
        FOR (j, 0, m - 1) {
            if (a[i][j] == 1) {
                val += (1LL << j);
            }
        }
        vs[val] = 1;
    }
    FOR (a, 0, (1LL << m) - 1) {
        if (!vs[a]) return a;
    }
    return -1;
}

string binary(ll x, int m) {
    string s;
    FOR (i, 1, m) {
        s += (char) ('0' + x % 2);
        x /= 2;
    }
    for (auto &i: s) {
        if (i == '0') i = '1';
        else i = '0';
    }
    return s;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
        string s;
        cin >> s;
        FOR (j, 0, m - 1) {
            a[i][j] = s[j] - '0';
        }
    }
    ll res = solve(n, m);
    if (res == -1) {
        cout << "LN\n";
    }
    else {
        cout << binary(res, m) << "\n";
    }
    return 0;
}