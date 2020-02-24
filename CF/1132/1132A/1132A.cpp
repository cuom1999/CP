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

int cnt[56];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    FOR (i, 1, 4) {
    	cin >> cnt[i];
    }

    if (cnt[1] == cnt[4]) {
    	if (cnt[1] == 0 && cnt[3]) {
    		cout << 0;
    	}
    	else {
    		cout << 1;
    	}
    }
    else {
    	cout << 0;
    }
	
    return 0;
}