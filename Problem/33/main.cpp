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
typedef pair < ld, ld > II;

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    int n;
    cin >> n;
    // n = 8;
    vector<int> a(n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
        // a[i] = rand() % 20;
        // cout << a[i] << " ";
    }
    // cout << endl;

    vector<ld> opt(n + 1);

    vector<II> intersections;
    FOR (i, 1, n) {
        intersections.pb({1, a[i]});
        while (intersections.size() >= 2) {
            II p1 = intersections.back();
            II p2 = intersections[intersections.size() - 2];
            if (p1.second / p1.first < p2.second / p2.first) {
                p1.first += p2.first;
                p1.second += p2.second;
                intersections.pop_back();
                intersections.pop_back();
                intersections.pb(p1);
            }
            else break;
        }
        II u = intersections.back();
        opt[i] = u.second / u.first;
    }

    vector<ld> res(n + 1);
    ld cost = 0;
    res[n] = opt[n];
    FORD (i, n - 1, 1) {
        res[i] = min(res[i + 1], opt[i]);
    }

    FOR (i, 1, n) {
        cost += sq(res[i] - a[i]);
        cout << res[i] << " "; 
    }
    cout << endl;
    cout << fixed << setprecision(8) << cost << endl;
    return 0;
}