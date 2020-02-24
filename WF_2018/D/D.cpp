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

ld loggt[5005];
ld l2 = log(2);
ld logCombi(int n, int k) {
	return loggt[n] - loggt[n - k] - loggt[k];
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 1, 1500) {
    	loggt[i] = loggt[i - 1] + log2(i);
    }

	int n, d, r;
	cin >> n >> d >> r;

	ld S = logCombi(n + d - 1, n - 1);
	ld res = 0;
	ld M = 0;
	ld M1 = 1e18;
	FOR (k, 1, n) {
		for (int y = 1; y <= n + d && k * (y - 1) <= d; y++) {
			ld U = 0;
			for (int i = 0; i <= n - k && d - (k + i) * (y - 1) >= 0; i++) {
				ld V = logCombi(n, k) + logCombi(n - k, i) + logCombi(n + d - (k + i) * (y - 1) - 1, n - 1);
				V -= S;
				M = max(M, V);
				M1 = min(M1, V);
				V = pow(2, V) * min(k, r);

				if (i % 2 == 0) {
					U += V;
				}	
				else U -= V;
			}
			res += U;
		}
	}    
	
	cout << M << " " << M1 << endl;

	//cout << fixed << setprecision(8) << res << endl;
    return 0;
}