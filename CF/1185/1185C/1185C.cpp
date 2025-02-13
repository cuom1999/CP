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

int t[200005];
int cnt[105];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, M;
	cin >> n >> M;

	FOR (i, 1, n) {
		cin >> t[i];
	}

	FOR (i, 1, n) {
		int s = M - t[i];

		int sum = 0;
		int res = 0;
		FOR (j, 1, 100) {
			sum += cnt[j] * j;
			if (sum > s) {
				sum -= cnt[j] * j;
				res += (s - sum) / j;
				break;
			}
			else {
				res += cnt[j];
			}
		}
		cnt[t[i]]++;
		cout << i - 1 - res << " ";
	}



	return 0;
}