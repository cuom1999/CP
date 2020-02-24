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

const ll K = 1e9 + 7;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int x;
        cin >> x;
        string s;
        cin >> s;

        ll len = s.size();
        FOR (i, 0, x - 1) {
            int val = s[i] - '0';
            if (s.size() < x) {
                string sub = s.substr(i + 1);
                FOR (j, 1, val - 1) {
                    s += sub;
                }
            }
            // cout << len << endl;
            len += (val - 1) * 1ll * (len - i - 1) % K;
            len %= K; 
        }
        cout << (len + K) % K << '\n';
    }   


    return 0;
}