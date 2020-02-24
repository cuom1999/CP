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


string s;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin >> s;

    int l = 0, r = 0;
    for (int i = 0; i < s.length(); i++) {
    	if (s[i] != s[0]) {
    		break;
    	}
    	l++;
    }

    FORD (i, s.length() - 1, 0) {
    	if (s[i] != s[s.length() - 1]) {
    		break;
    	}
    	r++;
    }

    if (s[0] == s[s.length() - 1]) {
    	ll res = (l + 1) * 1ll * (r + 1);
    	res %= 998244353;
    	cout << res << endl;
    }
    else {
    	ll res = l + r + 1;
    	cout << res << endl;
    }

	
    return 0;
}