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

int d[10005], e[10005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int q;
    cin >> q;

    FOR (z, 1, q) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        FOR (i, 1, s.size()) {
            set<int> s;
            FOR (j, 0, i - a) {
                s.insert(e[j] ^ e[i - a - j]);
            }
            FOR (j, 0, i - a + 1) {
                if (s.find(j) == s.end()) {
                    d[i] = j;
                    break;
                }
            }

            s.clear();
            FOR (j, 0, i - b) {
                s.insert(d[j] ^ d[i - b - j]);
            }

            FOR (j, 0, i - b + 1) {
                if (s.find(j) == s.end()) {
                    e[i] = j;
                    break;
                }
            } 
        }

        FOR (i, 0, s.size()) {
            cout << d[i] << " ";
        }
        cout << endl;

        int res = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                cnt++;
            }
            else {
                res ^= d[cnt];
                cnt = 0;
            }
        }
        res ^= d[cnt];
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }




    return 0;
}