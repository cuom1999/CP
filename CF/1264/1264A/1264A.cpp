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


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        int last = -1;
        int cnt = 0;
        int cur = 1;

        vector<int> a(n + 1);

        FOR (i, 1, n) {
            int p;
            cin >> p;
            if (p != last) {
                if (cnt) {
                    a[cur] = cnt;
                    cur++;
                }
                cnt = 1;
            }
            else {
                cnt++;
            }
            last = p;
        }

        int sum = n;
        n = cur;
        vector<int> s(n + 1);
        FOR (i, 1, n) {
            s[i] = a[i] + s[i - 1];
        }
        int res = -1;
        int resG = 0, resB = 0, resC = 0;

        FOR (i, 1, n) {
            int g = s[i];
            int bPos = upper_bound(all(s), g * 2) - s.begin();
            if (bPos > n) continue;
            int b = s[bPos] - g;
            int cPos = upper_bound(all(s), g * 2 + b) - s.begin();
            if (cPos > n) continue;
            int c = s[cPos] - g - b;

            if (g + b + c <= sum / 2) {
                cPos = upper_bound(all(s), sum / 2) - s.begin() - 1;
                int c = s[cPos] - g - b;
                if (res < g + b + c) {
                    res = g + c + b;
                    resG = g;
                    resB = b;
                    resC = c;
                }
            } 
        }
        cout << resG << " " << resB << " " << resC << "\n";
    }

    return 0;
}