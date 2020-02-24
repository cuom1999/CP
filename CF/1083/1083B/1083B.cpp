#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

string s, t;

ll d[500005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    cin >> s;
    cin >> t;

    if (s[0] == t[0]) d[0] = 1;
    else d[0] = 2;

    FOR (i, 1, n - 1) {
    	d[i] = 2 * (d[i - 1] - 1) + 1;
    	if (s[i] > t[i]) d[i]--;
    	if (s[i] < t[i]) d[i]++;
    	if (d[i] > k) d[i] = k + 1;
    }
    ll res = 0;

    FOR (i, 0, n - 1) {
    	res += min(k, d[i]);
    }

    cout << res << endl;
	
    return 0;
}