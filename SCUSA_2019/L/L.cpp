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

typedef pair<double, double> point;
typedef pair<point, double> circle;
#define X first
#define Y second

point operator + (point a, point b) { return point(a.X+b.X, a.Y+b.Y); }
point operator - (point a, point b) { return point(a.X-b.X, a.Y-b.Y); }
point operator / (point a, double x) { return point(a.X/x, a.Y/x); }
double abs(point a) { return sqrt(a.X*a.X+a.Y*a.Y); }

point center_from(double bx, double by, double cx, double cy) {
    double B=bx*bx+by*by, C=cx*cx+cy*cy, D=bx*cy-by*cx;
    return point((cy*B-by*C)/(2*D), (bx*C-cx*B)/(2*D));
}

circle circle_from(point A, point B, point C) {
    point I = center_from(B.X-A.X, B.Y-A.Y, C.X-A.X, C.Y-A.Y);
    return circle(I+A, abs(I));
}

const int N = 5005;
point a[N];

circle f(int n, vector<point> T) {
    if (T.size()==3 || n==0) {
        if (T.size()==0) return circle(point(0, 0), -1);
        if (T.size()==1) return circle(T[0], 0);
        if (T.size()==2) return circle((T[0]+T[1])/2, abs(T[0]-T[1])/2);
        return circle_from(T[0], T[1], T[2]);
    }
    random_shuffle(a+1, a+n+1);
    circle Result = f(0, T);
    for (int i=1; i<=n; i++)
    if (abs(Result.X - a[i]) > Result.Y+1e-9) {
        T.push_back(a[i]);
        Result = f(i-1, T);
        T.pop_back();
    }
    return Result;
}

ld x[3][5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        FOR (j, 0, 2) cin >> x[j][i];
    }
    ld res = 1e18;
    FOR (z, 0, 2) {
        vector<int> v;
        FOR (j, 0, 2) {
            if (z != j) v.pb(j);
        }   
        vector<point> points;

        FOR (i, 1, n) {
            point p;
            p.first = x[v[0]][i];
            p.second = x[v[1]][i];
            a[i] = p;
        }

        circle c = f(n, points);
        res = min(res, (ld) c.second);
    }
    cout << fixed << setprecision(8) << res * 2 << endl;


    return 0;
}