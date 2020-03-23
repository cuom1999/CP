#include <bits/stdc++.h>

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

struct Point {
    ll x, y;
    Point (ll x = 0, ll y = 0): x(x), y(y){}
    Point operator+(const Point& a) const{
        return {x + a.x, y + a.y};
    }
    Point operator-(const Point& a) const{
        return {x - a.x, y - a.y};
    }
    ll operator*(const Point& a) const{
        return x * a.x + y * a.y;
    }
    Point operator*(ll c) const {
        return {x * c, y * c};
    }
    bool operator<(const Point&a) {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
    bool operator==(const Point&a) {
        return (fabs(x - a.x) < eps && fabs(y - a.y) < eps);
    }
};

ll cross(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}

double area2(Point a, Point b, Point c) { return cross(a, b) + cross(b, c) + cross(c, a); }
vector<Point> convexHull(vector<Point> pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        // Note: If need maximum points on convex hull, need to change >= and <= to > and <.
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
    return pts;
}

bool smaller(pair<ll, ll> x, pair<ll, ll> y) {
    ll val = x.first * y.second - x.second * y.first;
    if (val > 0) return 0;
    if (val < 0) return 1;
    if (x.first > y.first) return 1;
    return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);

    FOR (i, 1, n) {
        cin >> a[i];
    }

    FOR (i, 1, n) {
        cin >> b[i];
    }

    vector<Point> pts;
    FOR (i, 1, n) {
        pts.pb({-a[i], -b[i]});
    }

    vector<Point> ch = convexHull(pts);
    for (auto p: ch) {
        cout << p.x << " " << p.y << endl;
    }
    int ind = 1;

    FOR (i, 2, n) {
        ll val = b[i] * a[ind] - a[i] * b[ind];
        // cout << i << " " << ind << " " << val << endl;
        if (val < 0) {
            ind = i;
        }
        else if (val == 0 && b[i] > b[ind]) {
            //cout << i << " " << ind << " " << b[i] << " " << b[ind] << endl;
            ind = i;
        }
    }

    pair<int, int> res;
    FOR (i, 1, n) {
        if (i == ind) continue;
        int firstRoot = 0;
        int secondRoot = 0;

        int lower = 0, upper = ch.size() - 1;

        while (lower < upper) {
            int mid = (lower + upper) / 2;
            ll val = (b[lower] - ch[mid].y) * (a[lower] - ch[mid + 1].x)
                - (b[lower] - ch[mid + 1].y) * (a[lower] - ch[mid].x);
            if (val > 0) {
                lower = mid + 1;
            }
            else {
                upper = mid;
            }
        }
        if (i == 1) {
            FOR (j, 0, ch.size() - 1) {
                cout << (double) (b[i] - ch[j].y) / (a[i] - ch[j].x) << " ";
            }
            cout << endl;
        }

        auto tryLower = [&](int lower) {
            if (!res.first) {
                res = {b[i] - ch[lower].y, a[i] - ch[lower].x};
                cout << i << " " << res.first << " " << res.second << endl;
            }
            else {
                pair<ll, ll> cur = {b[i] - ch[lower].y, a[i] - ch[lower].x};
                if (smaller(cur, res)) {
                    res = cur;
                }
                cout << i << " " << cur.first << " " << cur.second << endl;
            }
        };
        tryLower(lower);
        tryLower((lower + 1) % ch.size());
        tryLower((lower + ch.size() - 1) % ch.size());
    }
    cout << res.second << " " << res.first << endl;

    return 0;
}