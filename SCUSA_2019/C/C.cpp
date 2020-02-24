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

string s[505];

bool check(string& a, string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        cnt += (a[i] != b[i]);
    }
    return (cnt == 2);
}

const int MAXN = 505;
// everything is 1-index
// v[i]: adj set of right vertex i
// match[i]: adj of left vertex i

int match[MAXN], vs[MAXN];
vector<int> v[MAXN];

// find an augmenting path
bool findPath(int u, int t) { // u: a right vertex, t: time
    if (vs[u] != t){
        vs[u] = t;
    }
    else return 0;

    for (auto i: v[u]){
        if (!match[i] || findPath(match[i], t)) {
            match[i] = u;
            return 1;
        }
    }
    return 0;
}

int biMatching (int m, int n) {
    FOR (i, 1, max(m,n)) match[i] = vs[i] = 0;

    int cnt=0;

    FOR (i, 1, m) {
        cnt += findPath(i,i);
    }

    return cnt;
}

vector<int> adj[505];
int part[505];

void dfs(int a, int par) {
    for (auto i: adj[a]) {
        if (!part[i]) {
            part[i] = 3 - part[a];
            dfs(i, a);
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> s[i];
    }

    FOR (i, 1, n) {
        FOR (j, i + 1, n) {
            if (check(s[i], s[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    FOR (i, 1, n) {
        if (!part[i]) {
            part[i] = 1;
            dfs(i, 0);
        }
    }


    FOR (i, 1, n) {
        if (part[i] == 1) {
            for (auto j: adj[i]) {
                v[i].pb(j);
            }
        }
    }

    cout << n - biMatching(n, n) << endl;

    return 0;
}