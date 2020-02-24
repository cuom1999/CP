#include <bits/stdc++.h>
#include "geodeb.h"

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
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    GD_INIT("geo.html");

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    drawSquare(x1, y1, x2, y2);

    int x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    drawTriangle(x1, y1, x2, y2, x3, y3);

    int x, y, r;
    cin >> x >> y >> r;
    drawCircle(x, y, r);
    return 0;
}