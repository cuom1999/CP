#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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

ll W, cnt[10];

ll solve(ll W, ll index) {
	if (index == 8) {
		ll val = min(cnt[8], W / 8);
		return val * 8;
	}

	ll res = 0;

	FOR (i, 0, cnt[index]) {
		if (index * i <= W) {
			res = max(res, solve(W - index * i, index + 1) + index * i); 
		}
	}
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> W;

    FOR (i, 1, 8) cin >> cnt[i];

    
    FOR (i, 1, 4) {
    	if (cnt[i] == 0) continue;

    	cnt[i * 2] += cnt[i] / 2;
    	cnt[i] %= 2;
    	if (cnt[i] == 0) {
    		cnt[i] += 2;
    		cnt[i * 2]--;
    	}
    }

    FOR (i, 5, 7) {
    	ll old = cnt[i];
    	if (cnt[i] <= 96) continue;

	   	cnt[8] += i * (cnt[i] / 8);
	   	cnt[i] %= 8;

  		cnt[i] += 88;
   		cnt[8] -= i * 11;
    }

    //FOR (i, 1, 8) cout << cnt[i] << " "; cout << endl;


	cout << solve(W, 1) << endl;
	

    return 0;
}