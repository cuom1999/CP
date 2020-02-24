#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

vector<II> F[1005];
vector<II> T;

int d[100005][3][30];
int ma[100005][3];

int solve(int m, int m1, int m2, int r, string s) {
    F[1].clear();
    F[2].clear();
    T.clear();

    FOR (i, 0, 100000) {
        FOR (j, 0, 2) {
            FOR (k, 0, 29) d[i][j][k] = 0;
            ma[i][j] = 0;
        }
    }

    FOR (i, 0, m1 - 1) {
        F[1].pb(II(i, 1));
    }
    FOR (i, 0, m2 - 1) {
        F[2].pb(II(i, 2));
    }

    FOR (i, 3, 100) {
        F[i].clear();
        for (auto j: F[i - 1]) F[i].pb(j);
        for (auto j: F[i - 2]) F[i].pb(j);
        if (F[i].size() >= m) {
            T = F[i];
            while (T.size() > m) T.pop_back();
            break;
        }
    }

    int res = 0;

    FOR (i, m1 + m2, s.size() - 1) {
        II u = T[i];
        d[u.first][u.second][s[i] - 'A']++;
        ma[u.first][u.second] = max(ma[u.first][u.second], d[u.first][u.second][s[i] - 'A']);
    }

    FOR (i, 0, m1 + m2 - 1) {
        res += d[T[i].first][T[i].second][s[i] - 'A'] + 1;
    }

    vector<int> pearl;

    FOR (i, 0, m1 + m2 - 1) {
        if (d[T[i].first][T[i].second][s[i] - 'A'] < ma[T[i].first][T[i].second]) pearl.pb(ma[T[i].first][T[i].second] - d[T[i].first][T[i].second][s[i] - 'A']);
    }
    sort(all(pearl));
    reverse(all(pearl));
    for (int i = 0; i < r && i < pearl.size(); i++) {
        res += pearl[i];
    }
    return m - res;
}

string s;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //int m, m1, m2, r; cin >> m >> m1 >> m2 >> r;
    
    ll m = Rand(10000, 100000);
    ll m1 = Rand(1, 10);
    ll m2 = Rand(1, 10);
    ll r = Rand(0, m1 + m2);
    string s;
    FOR (i, 1, m) {
        s += (char) (Rand(0, 25) + 'A');
    }
    cout << m << " " << m1 << " " << m2 << " " << r << endl;
    cout << s << endl;
    
    //cin >> s;
    
    cout << solve(m, m1, m2, r, s) << endl;
    cout << solve(m, m1, m2, 0, s) << endl;




	
    return 0;
}