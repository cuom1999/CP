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

int n;

struct Solver {
    int a[100005];
    
    struct Node {
        int maxVal, minVal, maxDiff;
    } st[400005];

    Node merge(Node& a, Node& b) {
        Node res;
        res.maxVal = max(a.maxVal, b.maxVal);
        res.minVal = min(a.minVal, b.minVal);
        res.maxDiff = max(a.maxDiff, b.maxDiff);
        res.maxDiff = max(res.maxDiff, b.maxVal - a.minVal);
        return res;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id].maxVal = a[l];
            st[id].minVal = a[l];
            st[id].maxDiff = 0;
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        st[id] = merge(st[id * 2], st[id * 2 + 1]);
    }

    Node getAns(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return {-INF, INF, -INF};
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        Node a = getAns(id * 2, l, mid, u, v);
        Node b = getAns(id * 2 + 1, mid + 1, r, u, v);

        return merge(a, b);
    }

    int getAns(int l, int r) {
        return getAns(1, 1, n, l, r).maxDiff;
    }
} solver[2][7];

// solver[0][i]: solver for x < y and day at 1 is i
// solver[1][i]: x > y and day at n is i

int v[100005], d[100005];

int coefDay(int d) {
    d %= 7;
    if (d == 0 || d == 6) return 0;
    if (d == 1 || d == 5) return 1;
    if (d == 2 || d == 4) return 2;
    return 3;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    FOR (i, 1, n) {
        cin >> v[i] >> d[i];
    }

    FOR (day, 0, 6) {
        FOR (i, 1, n) {
            solver[0][day].a[i] = v[i] + coefDay(day + i - 1) * d[i];
        }
        FORD (i, n, 1) {
            solver[1][day].a[n + 1 - i] = v[i] + coefDay(day + n - i) * d[i];
        }
        FOR (i, 0, 1) {
            solver[i][day].build(1, 1, n);
        }
    }

    int q;
    cin >> q;

    FOR (z, 1, q) {
        int l, r;
        cin >> l >> r;
        int t = 0;
        if (l > r) {
            t = 1;
            l = n + 1 - l;
            r = n + 1 - r;
        }
        int dayAt1 = ((1 - l) % 7 + 7) % 7;
        cout << solver[t][dayAt1].getAns(l, r) << "\n";
    }


    return 0;
}