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
const ll K = 1e9 + 7;

ll mu[100005];
int a[100005];
int s[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    mu[0] = 1;
    FOR (i, 1, 100000){
    	mu[i] = mu[i - 1] * 2ll % K;
    }
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n){
    	char c;
    	cin >> c;
    	if (c == '1') a[i] = 1;
    	else a[i] = 0;
    	s[i] = s[i - 1] + a[i];
    }
    FOR (i, 1, q){
    	int l, r;
    	cin >> l >> r;
    	int a = s[r] - s[l - 1];
    	int b = r - l + 1 - a;
    	ll res = mu[b] * (mu[a] + K - 1) % K;
    	cout << res << endl;
    }
	
         return 0;
}