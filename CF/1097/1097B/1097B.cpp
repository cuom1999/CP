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

int a[105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
    	cin >> a[i];
    }
	FOR (i, 0, (1 << n) - 1) {
		int sum = 0;
		FOR (j, 0, n - 1) {
			if ((1 << j) & i) {
				sum = (sum + a[j + 1]) % 360;
			}
			else {
				sum = (sum - a[j + 1]) % 360;
			}
		}
		sum %= 360;
		if (sum < 0) {
			sum = (sum + 360) % 360;
		}
		if (sum == 0){
			cout << "YES";
			return 0;
		}
	}    
	
	cout << "NO";

    return 0;
}