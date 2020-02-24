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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n, k;
        cin >> n >> k;
        vector<char> s(n + 1);
        FOR (i, 1, n) {
            char c;
            cin >> c;
            s[i] = c;
        }    
        vector<II> res;

        FOR (i, 1, k - 1) {
            int u = i * 2 - 1;
            if (s[u] == ')') {
                int pos = 0;
                FOR (j, u + 1, n) {
                    if (s[j] == '(') {
                        pos = j;
                        break;
                    }
                }
                res.pb({u, pos});
                reverse(s.begin() + u, s.begin() + pos + 1);
            }
            if (s[u + 1] == '(') {
                int pos = 0;
                FOR (j, u + 2, n) {
                    if (s[j] == ')') {
                        pos = j;
                        break;
                    }
                }
                res.pb({u + 1, pos});
                reverse(s.begin() + u + 1, s.begin() + pos + 1);
            }
        }

        int remain = n / 2 - (k - 1);
        FOR (i, 0, remain - 1) {
            int u = 2 * k - 1 + i;
            if (s[u] == ')') {
                int pos = 0;
                FOR (j, u + 1, n) {
                    if (s[j] == '(') {
                        pos = j;
                        break;
                    }
                }
                res.pb({u, pos});
                reverse(s.begin() + u, s.begin() + pos + 1);
            } 
        }

        cout << res.size() << "\n";
        for (auto i: res) {
            cout << i.first << " " << i.second << "\n";
        }
    }
    
    return 0;
}