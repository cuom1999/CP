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
string s1, s2;

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> s;

    int n = s.length();

    int last = -1;

    FORD(i, n - 1, 0) {
    	if (s[i] == 'a') {
    		last = i;
    		break;
    	}
    }

    if (last == -1) {
    	if (n % 2 != 0) {
    		cout << ":(";
    		return 0;
    	}
    	FOR (i, 0, n / 2 - 1) {
    		if (s[i] != s[i + n / 2]) {
    			cout << ":(";
    			return 0;
    		}
    	}
    	FOR (i, 0, n / 2 - 1) cout << s[i]; 
    }
    else {
    	FOR (i, 0, n - 1) {
    		if (s[i] != 'a') s1 += s[i];
    	}

    	n = s1.length();
    	
    	if (n % 2 != 0) {
    		cout << ":(";
    		return 0;
    	}

    	FOR (i, 0, n / 2 - 1) {
    		if (s1[i] != s1[i + n / 2]) {
    			cout << ":(";
    			return 0;
    		}
    	}

    	int m = n / 2;
    	s1.clear();
    	s2.clear();

    	FOR (i, 0, last) {
    		if (s[i] != 'a') {
    			s1 += s[i];
    		}
    	}

    	if (s1.length() > m) {
    		cout << ":(";
    		return 0;
    	}
    	n = s1.length();
    	s1.clear();

    	FOR (i, 0, last + m - n) {
    		s1 += s[i];
    	}

    	cout << s1 << endl;
    }

	
    return 0;
}