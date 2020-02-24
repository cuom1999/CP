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
#define eps (1e-12)
#define sq(x) (  (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

struct Point {
    long double x, y;
    Point (long double x = 0, long double y = 0): x(x), y(y){}
    Point operator+(const Point& a) const{
        return {x + a.x, y + a.y};
    }
    Point operator-(const Point& a) const{
        return {x - a.x, y - a.y};
    }
    long double operator*(const Point& a) const{
        return x * a.x + y * a.y;
    }
    Point operator*(long double c) const {
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
long double abs(const Point& A) {
    return sqrt(sq(A.x) + sq(A.y));
}
long double cross(const Point& A, const Point& B) {
    return (A.x * B.y - A.y * B.x) / (abs(A) + abs(B));
}
long double cross(const Point&A, const Point& B, const Point& C) {
    return cross(A - C, B - C);
}

bool onSegment(Point A, Point B, Point C) {
    if (A == B || A == C) return 0;
    return fabs(cross(A, B, C)) < eps && (A.x - B.x) * (A.x - C.x) < eps && (A.y - B.y) * (A.y - C.y) < eps;
}
struct Line {
    long double a, b, c;
    Line(long double a, long double b, long double c): a(a), b(b), c(c){}
    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }
};

bool areParallel(Line l1, Line l2) {
    return fabs(l1.a * l2.b - l1.b * l2.a) < eps;
}
bool areIntersect(Line l1, Line l2, Point& p) {
    if (areParallel(l1, l2)) return 0;
    long double dx = l1.b * l2.c - l2.b * l1.c;
    long double dy = l1.c * l2.a - l2.c * l1.a;
    long double d = l1.a * l2.b - l2.a * l1.b;
    p = {dx / d, dy / d};
    return 1;
}

bool inPolygon(vector<Point>& p, Point q) {
    if (p.size() == 0) return 0;
    int n = p.size();
    FOR (i, 0, n - 1) {
        int j = (i + 1) % n;
        if (onSegment(q, p[i], p[j])) return 1;
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if ((p[i].y < q.y + eps && q.y < p[j].y - eps || p[j].y < eps + q.y && q.y < p[i].y - eps) && q.x < -eps + p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
    }
    return c;
}

#ifndef DONLINE_JUDGE
#include "geodeb.h"
#endif

vector<Point> p;
ld res = 0;
int n;
void solve(Point A, Point B) {
    Point C = B - A;

    ld t = 1e-6;
    Point A1 = C * t + A;
    Point B1 = C * (1 - t) + A;

    if (!inPolygon(p, A1) || !inPolygon(p, B1)) return;

    Point A2 = C * -t + A;
    Point B2 = C * (1 + t) + A; 
    bool extendA = 0, extendB = 0;
    if (inPolygon(p, A2)) extendA = 1;
    if (inPolygon(p, B2)) extendB = 1;

    bool isValid = 1;
    vector<Point> intersections;
    Line AB = Line(A, B);
    FOR (k, 0, n - 1) {
        Point X = p[k], Y = p[(k + 1) % n];
        if (fabs(cross(A, B, X)) < eps && fabs(cross(A, B, Y)) < eps) continue;
        Line XY = Line(X, Y);
        Point Z;
        if (areIntersect(AB, XY, Z) && onSegment(Z, X, Y)) {
            intersections.pb(Z);
        }
    }

    ld maxExtendA = -1e18, minExtendB = 1e18;

    FOR (k, 0, n - 1) {
        Point X = p[k];
        Point Y = p[(k + n - 1) % n];
        Point Z = p[(k + 1) % n];
        if (fabs(cross(A, B, p[k])) < eps) {
            Point T;
            if (areIntersect(Line(A, B), Line(Y, Z), T) && onSegment(T, Y, Z)) {
                intersections.pb(X);
            }
        }        
    }

    for (auto I: intersections) {
        Point J = I - A;
        ld t;
        if (fabs(C.x) > eps) t = J.x / C.x;
        else t = J.y / C.y;
        if (eps < t && t < 1 - eps) {
            isValid = 0;
            break;
        }
        if (t < eps) {
            maxExtendA = max(maxExtendA, t);
        }
        else {
            minExtendB = min(minExtendB, t);
        }
    }

    if (maxExtendA < -1e17) maxExtendA = 0;
    if (minExtendB > 1e17) minExtendB = 1;
    if (extendA == 0) maxExtendA = 0;
    if (!extendB) minExtendB = 1;

    if (isValid) {
        Point U = C * maxExtendA + A;
        Point V = C * minExtendB + A;
        res = max(res, abs(U - V));
        if (abs(U - V) > 13.99) {
            // cout << i << " " << j << " " << abs(U - V) << endl;
            GD_POINT(A.x, A.y, "red");
            GD_POINT(B.x, B.y, "red");
            GD_PAUSE();
            GD_POINT(U.x, U.y, "gre@en");
            GD_POINT(V.x, V.y, "green");
            GD_SEGMENT(U.x, U.y, V.x, V.y, "green");
        }       
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    GD_INIT("geo.html");
    p.resize(n);
    FOR (i, 0, n - 1) {
        cin >> p[i].x >> p[i].y;
    }

    FOR (i, 0, n - 1) {
        GD_POINT(p[i].x, p[i].y);
        GD_SEGMENT(p[i].x, p[i].y, p[(i + 1) % n].x, p[(i + 1) % n].y);
    }

    FOR (i, 0, n - 1) {
        FOR (j, i + 1, n - 1) {
            Point A = p[i];
            Point B = p[j];
            B.x += 1e-8 * (1.3123197842);
            B.y += 1e-8 * (0.9898923899);
            solve(A, B);
            B.x -= 2e-8 * (1.3123197842);
            B.y -= 2e-8 * (0.9898923899);
            solve(A, B);
            B.x += 2e-8 * (1.3123197842);
            solve(A, B);
            B.x -= 2e-8 * -(1.3123197842);
            B.y += 2e-8 * -(0.9898923899);
            solve(A, B);
        }
    }

    cout << fixed << setprecision(8) << res << endl;
    return 0;
}