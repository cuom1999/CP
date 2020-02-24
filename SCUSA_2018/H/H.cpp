#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

const ld PI = acos(-1.0);
struct Point {
    ld x, y;
};

bool ccw(Point a, Point b) {
    if (!a.y && !b.y) return a.x < b.x;
    return a.x * b.y < b.x * a.y;
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

Point orc[100005];

vector<ld> rootEq2(ld a, ld b, ld c) {
    ld delta = sq(b) - 4 * a * c;
    if (delta < 0) return {};
    delta = sqrt(delta);
    return {(-b - delta) / (2 * a), (-b + delta) / (2 * a)};
}

vector<Point> intersection(Point A, ld r) {
    ld a = A.x, b = A.y;
    ld c = sq(a) + sq(b);
    bool swapped = 0;
    if (!b) {
        swapped = 1;
        swap(a, b);
    }
    vector<ld> xVals = rootEq2(4 * c, -4 * a * c, sq(c) - sq(r) * 4 * sq(b));
    vector<Point> res;
    for (auto x: xVals) {
        ld y = (c - 2 * a * x) / (2 * b);
        if (!swapped) res.pb({x, y});
        else res.pb({y, x});
    }
    return res;
}

int n, k;

void normal(Point& p, ld r) {
    p.x /= r;
    p.y /= r;
}

bool solve(ld r) {
    vector<pair<Point, int>> pts;
    vector<pair<Point, Point>> pairs;
    int cntPts = 0;
    FOR (i, 1, n) {
        vector<Point> v = intersection(orc[i], r);
        if (v.size()) {
            normal(v[0], r);
            normal(v[1], r);
            if (!ccw(v[0], v[1])) {
                swap(v[0], v[1]);
            }

            cntPts++;
            pts.pb({v[0], cntPts});
            pts.pb({v[1], -cntPts});
            pairs.pb({v[0], v[1]});
        }
    }
    if (pts.size() == 0) return 0;

    // cout << ccw(pairs[0].first, pairs[0].second) << endl;
    sort(all(pts), [](pair<Point, int> A, pair<Point, int> B) {
        return cmp(A.first, B.first);
    });

    Point st = pts[0].first;
    int cnt = 1;

    FOR (i, 1, cntPts) {
        if (i == abs(pts[0].second)) continue;
        if (ccw(pairs[i - 1].first, st) && ccw(st, pairs[i - 1].second)) {
            cnt++;
        }
    }
    if (pts[0].second > 0) cnt--;
    int res = cnt;
    for (auto p: pts) {
        // cout << p.first.x << " " << p.first.y << " of " << p.second << endl;
        
        if (p.second > 0) cnt++;
        // cout << cnt << endl;
        res = max(res, cnt);
        if (p.second < 0) cnt--;
    }
    return res >= k;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    FOR (i, 1, n) {
        cin >> orc[i].x >> orc[i].y;
    }
    ld lower = 0, upper = 1e9;
    // cout << solve(1.59) << endl;
    // return 0;
    FOR (i, 1, 200) {
        ld mid = (lower + upper) / 2;
        // cout << mid << " " << solve(mid) << endl;
        if (solve(mid)) {
            upper = mid;
        }
        else {
            lower = mid;
        }
    }
    if (upper > 9e8) {
        cout << -1 << endl;
    }
    else {
        cout << fixed << setprecision(8) << lower << endl;
    }
    return 0;
}