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
int dd[1005];
vector<char> v = {'a', 'i', 'e', 'u', 'o'};

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    cin >> t;
    if (s.length() != t.length()) {
    	cout << "No";
    	return 0;
    }
    for (auto i: v) dd[i] = 1;

    FOR (i, 0, s.length() - 1) {
    	if (dd[s[i]] != dd[t[i]]) {
    		cout << "No";
    		return 0;
    	}
    }
    cout << "Yes";


	
    return 0;
}