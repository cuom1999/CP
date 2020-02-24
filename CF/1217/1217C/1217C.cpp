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
        string s;
        cin >> s;

        int num0 = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                num0++;
            }
            else {
                int val = 0;
                for (int j = i; j <= i + 20 && j < s.size(); j++) {
                    val = val * 2 + (s[j] - '0');
                    if (num0 >= val - (j - i + 1)) {
                        res++;
                        // cout << i << " " << j << endl;
                    }
                }
                num0 = 0;
            }
        }

        cout << res << "\n";
    }

    return 0;
}