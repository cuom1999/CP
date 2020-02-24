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

set<int> S;
int s[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m) {
    	int x;
    	cin >> x;
    	s[x]++;
    	if (s[x] == 1) S.insert(x);
    	if (S.size() == n) {
    		cout << 1;
    		S.clear();
    		FOR (i, 1, n) s[i]--;
    		FOR (i, 1, n) {
    			if (s[i]) S.insert(i);
    		}
    	}
    	else cout << 0;

    }
	
    return 0;
}