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

int cnt[105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    FOR (i, 1, n) {
    	int x;
    	cin >> x;
    	cnt[x % k]++;
    }

    int res = 0;

    for (int i = 1; i * 2 < k; i++) {
    	res += min(cnt[i], cnt[k - i]);
    }

    res += cnt[0] / 2;

    if (k % 2 == 0) {
    	res += cnt[k / 2] / 2;
    }

    cout << res * 2 << endl;
    
	
    return 0;
}