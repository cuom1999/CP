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

multiset<int> a[35];
ll s[35];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    int cnt = 0;
    FOR (z, 1, t) {
    	char c;
    	cin >> c;
    	int x;
    	cin >> x;
    	int b = flog2(x) + 1;
    	if (c == '+') {
    		a[b].insert(x);
    		s[b] += x;
    		cnt++;
    	}
    	else {
    		a[b].erase(a[b].find(x));
    		s[b] -= x;
    		cnt--;
    	}
    	ll sum = 0;
    	int res = 0;
    	FOR (i, 1, 31) {
    		int mi = *a[i].begin();
    		//if (i == 2) cout << mi << " " << sum << endl;
    		if (mi > 2 * sum) {
    			res++;
    			//cout << mi << " " << sum << endl;
    		}
    		sum += s[i];
    	}
    	cout << cnt - res << endl;
    }
    
	
    return 0;
}