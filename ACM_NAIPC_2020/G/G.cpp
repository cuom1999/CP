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

int a[200005], b[200005];
int n, p, q, s;
    
bool solve(int d) {
    vector<int> l(p + 1), r(p + 1);
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> v[200005];
    FOR (i, 1, p) {
        int minVal = a[i] - d;
        int maxVal = min(s - a[i], a[i] + d);
        l[i] = lower_bound(b + 1, b + q + 1, minVal) - b;
        r[i] = upper_bound(b + 1, b + q + 1, maxVal) - b - 1;
        if (l[i] <= r[i]) {
            v[l[i]].pb(r[i]);
        }
    }

    int res = 0;
    FOR (i, 1, q) {
        for (auto j: v[i]) {
            pq.push(j);
        }
        while (pq.size() && pq.top() < i) {
            pq.pop();
        }

        if (pq.size()) {
            res++;
            pq.pop();
        }
    }   

    return (res >= n);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> p >> q >> s;

    FOR (i, 1, p) {
        cin >> a[i];
    }

    FOR (i, 1, q) {
        cin >> b[i];
    }

    sort(a + 1, a + p + 1);
    sort(b + 1, b + q + 1);

    int lower = 0, upper = INF + 1;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (solve(mid)) {
            upper = mid;
        }
        else {
            lower = mid + 1;
        }
    }

    if (lower == INF + 1) {
        cout << -1;
    }
    else {
        cout << lower << endl;
    }
    return 0;
}