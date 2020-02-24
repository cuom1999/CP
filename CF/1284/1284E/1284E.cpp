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
} p[2505];

ll c3(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}

ll cnt[2505][2505];

void add(int i, int j, ll u) {
    if (i > j) swap(i, j);
    cnt[i][j] += u;
}

bool ccw(Point a, Point b) {
    if (!a.y && !b.y) return a.x < b.x;
    return a.x * b.y < a.y * b.x;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> p[i].x >> p[i].y;
    }
    FOR (i, 1, n) {
        vector<pair<Point, int>> v;
        FOR (j, 1, n) {
            if (j != i) {
                v.pb({{p[j].x - p[i].x, p[j].y - p[i].y}, j});
                v.pb({{-p[j].x + p[i].x, -p[j].y + p[i].y}, -j});
            }
        }
        sort(all(v), [](pair<Point, int> a, pair<Point, int> b) {
            Point p1 = a.first;
            Point p2 = b.first;
            // cout << p1.x << " " << p1.y << " | " << p2.x << " " << p2.y << " " << ccw(p1, p2) << endl;
            if ((p1.y >= 0) ^ (p2.y >= 0)) {
                return p1.y > p2.y;
            }
            else {
                return ccw(p1, p2);
            }
        });

        int startPoint = 0;
        FOR (i, 0, 2 * n - 3) {
            if (v[i].second > 0) {
                startPoint = i;
                break;
            }
        }
        int k = startPoint;
        int cnt = 1;
        FOR (j, 0, 2 * n - 3) {
            int ind = v[(j + startPoint) % (2 * n - 2)].second;
            if (ind < 0) continue;
            cnt--;
            while (v[k].second != -ind) {
                k++;
                if (k == 2 * n - 2) k = 0;
                if (v[k].second > 0) cnt++;
                // cout << ind << " " << v[k].second << " " << cnt << endl;
            }
            add(i, ind, c3(cnt) + c3(n - 2 - cnt));
            // cout << i << " " << ind << " " << v[k].second << " " << cnt << endl;
        }
    }

    ll hull = 0;
    FOR (i, 1, n) {
        FOR (j, i + 1, n) {
            cnt[i][j] /= 2;
            // cout << i << " " << j << " " << cnt[i][j] << endl;
            hull += cnt[i][j];
        }
    }

    ll sum = 1;
    FORD (i, n, n - 4) {
        sum *= i;
    }
    FOR (i, 1, 4) sum /= i;
    // cout << hull << " " << sum << endl;
    cout << sum - hull << endl;

    return 0;
}