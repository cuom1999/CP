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
typedef pair < ll, ll > II;

struct Tarot {
    ll x, y, a, b, cost;
} tarot[1005];

// i can go to j
bool check(int i, int j) {
    ll x = tarot[j].x - tarot[i].x;
    ll y = tarot[j].y - tarot[i].y;

    ll a = tarot[i].a;
    ll b = tarot[i].b;

    ll d = __gcd(abs(a), abs(b));
    
    if (x % d || y % d) return 0;

    x /= d;
    y /= d;

    ll a1 = a / d, b1 = b / d;
    if ((a1 + b1) % 2 == 0) {
        return ((x + y) % 2 == 0);
    }
    else {
        return 1;
    }
}

vector<int> adj[1005];
ll d[1005], c[1005][1005];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> tarot[i].x >> tarot[i].y >> tarot[i].a >> tarot[i].b >> tarot[i].cost;
    }
    n++;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            c[i][j] = 1e15;
        }
    }

    int root = n;
    vector<II> adj;

    FOR (i, 1, root - 1) {
        FOR (j, 1, root - 1) {
            if (i == j) continue;
            if (check(i, j)) {
                adj[j].pb({i, tarot[i].cost});
            }
        } 
        for (int u = -1; u <= 1; u += 2) {
            for (int v = -1; v <= 1; v += 2) {
                n++;
                data[n] = data[i];
                data[n].x += u * data[n].a;
                data[n].y *= v * data[n].a;
            }
        }
    }

   
    return 0;
}