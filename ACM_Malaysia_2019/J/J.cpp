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

vector<int> adj[10];
int vs[10];
vector<int> st;

void dfs(int a) {
    vs[a] = 1;
    for (auto i: adj[a]) {
        if (vs[i] == 1) {
            cout << "impossible";
            exit(0);
        }
        if (!vs[i]) dfs(i);
    }
    st.pb(a);
    vs[a] = 2;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i, 1, 5) {
        string s;
        cin >> s;
        if (s[1] == '>') reverse(all(s));
        adj[s[0] - 'A'].pb(s[2] - 'A');
    }
    FOR (i, 0, 4) {
        if (!vs[i]) dfs(i);
    }
    reverse(all(st));
    for (auto i: st) {
        cout << (char) (i + 'A');
    }
    return 0;
}