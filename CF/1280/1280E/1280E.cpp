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

int r;
string s;
void input() {
    s.clear();
    cin >> r;
    string buffer;
    getline(cin, buffer);
    for (auto i: buffer) {
        if (!isspace(i)) s += i;
    }
}

struct Solver {
    vector<vector<int>> adj;
    vector<int> type;
    int NODE = 1;
    ll r;
    vector<ll> rc, c, child; // c is sqrt(c)
    string s;

    Solver(int r0, string& str) {
        r = r0;
        int n = str.size();
        adj.resize(n + 3);
        rc.resize(n + 3);
        c.resize(n + 3);
        child.resize(n + 3);
        type.resize(n + 3);
        s = str;
    }   
    void dfs1(int a) {
        if (adj[a].size() == 0) {
            c[a] = 1;
            return;
        }
        
        if (type[a] == 0) c[a] = INF;

        for (auto i: adj[a]) {
            dfs1(i);
            if (type[a] == 0) {
                if (c[a] > c[i]) {
                    c[a] = c[i];
                    child[a] = i;
                }
            }
            else {
                c[a] += c[i];
            }
        }
    }

    void dfs2(int a) {
        for (auto i: adj[a]) {
            if (type[a] == 0) {
                if (i == child[a]) rc[i] = rc[a];
                else rc[i] = 0;
            }
            else {
                rc[i] = rc[a];
            }
            dfs2(i);
        }
    }

    void solve() {


        vector<int> stack;
        vector<int> resistor;

        int cur = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                NODE++;
                stack.pb(NODE);
                adj[cur].pb(NODE);
                cur = NODE;
            }
            if (s[i] == '*') {
                NODE++;
                adj[cur].pb(NODE);
                resistor.pb(NODE);
            }
            if (s[i] == ')') {
                stack.pop_back();
                cur = stack.back();
            }
            if (s[i] == 'P') {
                type[cur] = 1;
            }
        }

        // FOR (i, 1, NODE) {
        //     for (auto j: adj[i]) cout << i << " " << j << endl;
        // }
        // FOR (i, 1, NODE) cout << type[i] << " "; cout << endl;

        dfs1(1);
        rc[1] = r * c[1];
        dfs2(1);
        cout << "REVOLTING ";
        for (auto i: resistor) cout << rc[i] << " ";
            cout << endl;
    }
};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        input();
        Solver(r, s).solve();
    }

    return 0;
}