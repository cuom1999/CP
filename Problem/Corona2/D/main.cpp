#include <bits/stdc++.h>
#include "geodeb.h"

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output1.txt","w",stdout)
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
    int x, y;
};

int dist(Point A, Point B) {
    return sq(A.x - B.x) + sq(A.y - B.y);
}

int area(Point A, Point B, Point C) {
    B.x -= A.x;
    B.y -= A.y;
    C.x -= A.x;
    C.y -= A.y;
    return abs(B.x * C.y - B.y * C.x);
}

bool inCircle(Point A, Point O, int r) {
    return dist(O, A) <= sq(r);
}

bool inSquare(Point A, Point X, Point Y) {
    return (X.x <= A.x && A.x <= Y.x && X.y <= A.y && A.y <= Y.y);
}

bool inTriangle(Point X, Point A, Point B, Point C) {
    return area(A, B, C) == area(X, A, B) + area(X, A, C) + area(X, B, C);
}

void drawSquare(int x1, int y1, int x2, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    
    GD_SEGMENT(x1, y1, x1, y2);
    GD_SEGMENT(x1, y1, x2, y1);
    GD_SEGMENT(x1, y2, x2, y2);
    GD_SEGMENT(x2, y1, x2, y2);
}

void drawCircle(int x, int y, int r) {
    GD_CIRCLE(x, y, r);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    GD_SEGMENT(x1, y1, x2, y2);
    GD_SEGMENT(x1, y1, x3, y3);
    GD_SEGMENT(x3, y3, x2, y2);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    GD_INIT("geo.html");

    Point S1, S2;
    cin >> S1.x >> S1.y >> S2.x >> S2.y;
    if (S1.x > S2.x) swap(S1.x, S2.x);
    if (S1.y > S2.y) swap(S1.y, S2.y);

    drawSquare(S1.x, S1.y, S2.x, S2.y);

    // assert(S2.y - S1.y == S2.x - S1.x);

    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    assert(area(A, B, C) > 0);

    drawTriangle(A.x, A.y, B.x, B.y, C.x, C.y);

    Point O;
    int r;
    cin >> O.x >> O.y >> r;
    drawCircle(O.x, O.y, r);

    int res = 0;
    FOR (x, -1000, 1000) {
        FOR (y, -1000, 1000) {
            Point Z = {x, y};
            if (inCircle(Z, O, r) || inSquare(Z, S1, S2) || inTriangle(Z, A, B, C)) {
                res++;
                cout << x << " " << y << endl;
            }
        }
    }

    cout << res << endl;

    return 0;
}