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
};

ll area(const Point& a, const Point& b, const Point& c) {
    return abs((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x));
}



int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> p(n + 1);

    FOR (i, 1, n) {
        cin >> p[i].x >> p[i].y;
    }
    ll maxArea = 0;
    FOR (i, 1, n) {
        FOR (j, i + 2, n) {
            int lower = i + 1, upper = j - 1;
            
            while (lower < upper) {
                int mid = (lower + upper + 1) / 2;
                if (area(p[i], p[j], p[mid]) >= area(p[i], p[j], p[mid - 1])) {
                    lower = mid;
                }
                else {
                    upper = mid - 1;
                }
            }

            maxArea = max(maxArea, area(p[i], p[j], p[lower]));
        }
    }

    cout << (double) (maxArea / 2.0) << endl;

    return 0;
}