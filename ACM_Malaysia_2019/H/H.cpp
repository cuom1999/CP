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

struct Point {
    ll x, y;
    Point operator+(const Point& a) const{
        return {x + a.x, y + a.y};
    }
    Point operator-(const Point& a) const{
        return {x - a.x, y - a.y};
    }
    bool operator==(const Point& p) {
        return x == p.x && y == p.x;
    }
    bool operator< (const Point& p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

long long cross(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}
long long cross(const Point&A, const Point& B, const Point& C) {
    return cross(A - C, B - C);
}
bool onSegment(Point A, Point B, Point C) {
    return fabs(cross(A, B, C)) < eps && (A.x - B.x) * (A.x - C.x) < eps && (A.y - B.y) * (A.y - C.y) < eps;
}

#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
bool inConvex(vector<Point>& l, Point p){
    int a = 1, b = l.size()-1, c;
    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
    // Allow on edge --> if (Det... > 0 || Det ... < 0)
    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(l[0], l[c], p) > 0) b = c; else a = c;
    }
    // Alow on edge --> return Det... <= 0
    return Det(l[a], l[b], p) < 0;
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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n, m;
        cin >> n >> m;
        vector<Point> p;
        FOR (i, 1, n) {
            Point a;
            cin >> a.x >> a.y;
            p.pb(a);
        }
        cout << "Case " << z << "\n";
        vector<Point> hull = convexHull(p);
        
        for (auto i: hull) {
            cout << i.x << " " << i.y << "\n";
        }
        cout << hull[0].x << " " << hull[0].y << "\n";
        FOR (i, 1, m) {
            Point A;
            cin >> A.x >> A.y;
            cout << A.x << " " << A.y << " is ";
            if (inConvex(hull, A)) {
                cout << "unsafe!\n";
            }
            else {
                cout << "safe!\n";
            }
        }
        cout << '\n';
    }


    return 0;
}