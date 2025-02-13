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

int a[29];

int calc(int l, int r) {
	if (l == r) return 1;
	bool isSorted = 1;
	FOR (i, l, r - 1) {
		if (a[i] > a[i + 1]) {
			isSorted = 0;
			break;
		}
	} 
	if (isSorted) return r - l + 1;
	int mid = (l + r) / 2;
	return max(calc(l, mid), calc(mid + 1, r));
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    cout << calc(1, n) << endl;
	
    return 0;
}