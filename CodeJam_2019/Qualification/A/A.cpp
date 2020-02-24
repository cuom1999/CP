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

string s;
string a, b;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    FOR (z, 1, t) {
    	cout << "Case #" << z << ": "; 
	    cin >> s;

	    a.clear(); b.clear();
	    a.resize(s.size());
	    b.resize(s.size());

	    FOR (i, 0, s.length() - 1) {
	    	if (s[i] == '4') {
	    		a[i] = '1';
	    		b[i] = '3';
	    	}
	    	else {
	    		a[i] = '0';
	    		b[i] = s[i];
	    	}
	    }

		reverse(all(a));
		while(a.back() == '0') a.pop_back();

		reverse(all(a));

		cout << a << " " << b << endl;    
	}
	
    return 0;
}