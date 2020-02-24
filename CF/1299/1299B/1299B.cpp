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
    Point operator-(Point A) {
        return {x - A.x, y - A.y};
    }
};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> p(n + 1);
    FOR (i, 0, n - 1) {
        cin >> p[i].x >> p[i].y;
    }

    if (n % 2) {
        cout << "NO\n";
    }
    else {
        int m = n / 2;
        FOR (i, 0, m - 1) {
            Point C = p[i + 1] - p[i];
            Point D = p[(i + m + 1) % n] - p[(i + m) % n];
            if (C.x != -D.x || C.y != -D.y) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }

    return 0;
}