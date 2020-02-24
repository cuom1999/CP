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

const int MAXN = 100005;
int maxVal[4 * MAXN], lz[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        maxVal[id] = -l;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    maxVal[id] = max(maxVal[id * 2], maxVal[id * 2 + 1]);
}

void down(int id, int l, int r) {
    if (l == r || !lz[id]) return;
    maxVal[id * 2] += lz[id];
    maxVal[id * 2 + 1] += lz[id];
    lz[id * 2] += lz[id];
    lz[id * 2 + 1] += lz[id];
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        maxVal[id] += k;
        lz[id] += k;
        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);

    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);
    maxVal[id] = max(maxVal[id * 2], maxVal[id * 2 + 1]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);  

    int n;
    cin >> n;

    int N = 100000;

    build(1, 1, N);

    FOR (i, 1, n) {
        int d, t;
        cin >> d >> t;
        update(1, 1, N, d, N, t);
        cout << max(0, maxVal[1]) << "\n";
    }   


    return 0;
}