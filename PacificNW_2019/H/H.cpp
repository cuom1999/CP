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

// to sort all points about the origin
// only works if no 2 points lie on the same ray from O

struct Point {
    ll x, y;
}p[2005];

bool ccw(Point a, Point b) {
    if (!a.y && !b.y) return a.x < b.x;
    return a.x * b.y < a.y * b.x;
}
bool cmp(Point p1, Point p2) {
    if (p1.y >= 0 && p2.y >= 0) {
        return ccw(p1, p2);
    }
    else if (p1.y < 0 && p2.y < 0) {
        return ccw(p1, p2);
    }
    else {
        return p1.y > p2.y;
    }
}


int n;

int solve(int pos) {
    vector<pair<Point, int>> pts;
    FOR (i, 1, n) {
        if (i != pos) {
            pts.pb({{p[i].x - p[pos].x, p[i].y - p[pos].y}, i});
            pts.pb({{-p[i].x + p[pos].x, -p[i].y + p[pos].y}, -i});
        }
    }

    sort(all(pts), [](pair<Point, int> a, pair<Point, int> b) {
        return cmp(a.first, b.first);
    });
    vector<int> cnt(n + 1);
    int val = 0;
    for (auto i: pts) {
        if (i.second > 0) {
            if (i.first.y > 0 || (i.first.y == 0 && i.first.x < 0)) {
                val++;
            }
        }
    }
    // cout << pos << "_" << endl;
    cnt[val]++;
    // cout << val << endl;
    FOR (i, 0, 2 * n - 4) {
        if (pts[i].second > 0) {
            val--;
        }
        else {
            val++;
        }
        // cout << val << endl;
        cnt[val]++;
    } 
    int res = 0;
    for (auto i: cnt) res = max(res, i);
    return res;
}


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    FOR (i, 1, n) {
        cin >> p[i].x >> p[i].y;
    }

    int res = 0;
    FOR (i, 1, n) res = max(res, solve(i));
    cout << res << endl;

    return 0;
}