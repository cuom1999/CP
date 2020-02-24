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


struct TwoSat {
    int numVer;
    int cnt;
    vector<int> * a; //
    int *color, *num, *low; // color 1=False, 2=True
    stack<int> st;
    bool Invalid = false;

    #define SetLength2(a, n, t) a=((t*) calloc(n, sizeof(t))) + (n)/2

    bool minimize(int &a, int b){
        if (a>b) a=b; else return false; return true;
    }

    void init(int n){
        numVer = n;
        SetLength2(a, n*2+5, vector<int>);
        SetLength2(color, n*2+5, int);
        SetLength2(num, n*2+5, int);
        SetLength2(low, n*2+5, int);
    }

    void set_color(int u, int x){
        if (color[u]==(x^3)) Invalid=true; else color[u]=x;
        if (color[-u]==x) Invalid=true; else color[-u]=(x^3);
    }

    void tarzan(int u){
        num[u]=low[u]=++cnt; st.push(u);

        for (int i=0,v; v=a[u][i]; i++){
            if (num[v]) minimize(low[u], num[v]);
            else tarzan(v), minimize(low[u], low[v]);
            if (color[v]==1) set_color(u, 1); // False
        }
        if (low[u]==num[u]){
            int v=0;
            if (color[u]==0) set_color(u, 2); // True
            do {
                v=st.top(); st.pop();
                set_color(v, color[u]);
                num[v]=low[v]=0x33334444;
            } while (u!=v);
        }
    }


    void add(int p, int q) {
        a[-p].push_back(q);
        a[-q].push_back(p);
    }

    bool solve() {
        FOR (i, 1, numVer) {
            a[i].pb(0);
            a[-i].pb(0);
        }

        FOR (i, 1, numVer) {
            if (!num[i]) tarzan(i);
            if (!num[-i]) tarzan(-i);
        }
        return !Invalid;
    }
} ts;

int lessEqual(int x) {
    return x; 
}

int chosen(int x) {
    return x + (4e5);
}

int l[400005], r[400005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, p, M, m;
    cin >> n >> p >> M >> m;

    ts.init(8e5);

    vector<II> complains, req;
    FOR (i, 1, n) {
        int x, y;
        cin >> x >> y;
        complains.pb({x, y});
    }

    FOR (i, 1, p) {
        cin >> l[i] >> r[i];
    }

    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y;
        req.pb({x, y});
    }

    for (auto ii: complains) {
        int u = ii.first;
        int v = ii.second;

        ts.add(chosen(u), chosen(v));
    }

    for (auto ii: req) {
        ts.add(-chosen(ii.first), -chosen(ii.second));
    }

    FOR (i, 1, p) {
        ts.add(-chosen(i), -lessEqual(l[i] - 1));
        ts.add(-chosen(i), lessEqual(r[i]));
    }

    FOR (i, 1, M - 1) {
        ts.add(-lessEqual(i), lessEqual(i + 1));
    }

    // cout << solve() << endl;
    if (!ts.solve()) {
        cout << "-1";
    }
    else {
        vector<int> res;
        int pow = -1;
        // FOR (i, 1, 4) cout << Color[lessEqual(i)] << " ";
        // return 0;
        FOR (i, 1, p) {
            if (ts.color[chosen(i)] == 2) {
                res.pb(i);
                pow = max(pow, l[i]);
            }
        }
        cout << res.size() << " " << pow << endl;
        for (auto i: res) cout << i << " ";
    }
    return 0;
}