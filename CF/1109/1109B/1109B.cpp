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
string t;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;

    int n = s.length();
    s = '0' + s;

    int qq = 0;
    FOR (i, 1, n) {
    	if (s[i] != s[1]) qq++;
    }

    if (qq <= 1) {
    	cout << "Impossible";
    	return 0;
    }

    FOR (i, 2, n) {
    	t.clear();
    	t = '0';
    	FOR (j, i, n) t += s[j];
    	FOR (j, 1, i - 1) t += s[j];

    	bool q = 1;
    	FOR (j, 1, n / 2) {
    		if (t[j] != t[n + 1 - j]) {
    			q = 0;
    			break;
    		}
    	}

    	if (q == 0) {
    		continue;
    	}
    	q = 0;

    	FOR (j, 1, n) {
    		if (t[j] != s[j]) {
    			q = 1; break;
    		}
    	}

    	if (q) {
    		cout << 1 << endl;
    		return 0;
    	} 
    }

    cout << 2 << endl;
	
    return 0;
}