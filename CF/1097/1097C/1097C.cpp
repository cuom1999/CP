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

string s[100005];
int d[500005], e[500005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
    	cin >> s[i];
    	
    	int q = 0;
    	int sum = 0;
    	for (int j = 0; j < s[i].length(); j++) {
    		if (s[i][j] == '(') {
    			sum++;
    		} 
    		else sum--;
    		if (sum < 0) {
    			q = 1;
    		}
    	}
    	if (!q) {
    		//cout << i << " 0 " << sum << endl;
    		d[sum]++;
    		continue;
    	}

    	reverse(all(s[i]));
    	
    	q = sum = 0;

		for (int j = 0; j < s[i].length(); j++) {
    		if (s[i][j] == ')') {
    			sum++;
    		} 
    		else sum--;
    		if (sum < 0) {
    			q = 1;
    		}
    	}
    	if (!q) {
    		//cout << i << " 1 " << sum << endl;
    		e[sum]++;
    	}    	
    }
    ll res = d[0] / 2;
    FOR (i, 1, 500000) {
    	res += min(d[i], e[i]);
    }
    cout << res << endl;

	
    return 0;
}