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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n + 1), s(n + 1);
    vector<Point> pts;

    FOR (i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    FOR (i, 0, n) {
        pts.pb({i, s[i]});
    }

    vector<Point> ch = convexHull(pts);

    vector<int> index;
    for (auto i: ch) {
        index.pb(i.x);
        if (i.x == n) {
            break;
        }
    }

    vector<long double> res(n + 1);
    for (int i = 0; i + 1 < index.size(); i++) {
        FOR (j, index[i] + 1, index[i + 1]) {
            res[j] = (s[index[i + 1]] - s[index[i]]) * 1.0 / (index[i + 1] - index[i]);
        }
    }
    FOR (i, 1, n) {
        cout << fixed << setprecision(12) << res[i] << "\n";
    }
    return 0;
}