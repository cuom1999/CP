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

struct Data {
	ll x, c;
}data[100005];

ll minLeft[100005], minRight[100005];

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n, k;
		cin >> k >> n;

		FOR (i, 1, n) {
			cin >> data[i].x;
		}

		FOR (i, 1, n) {
			cin >> data[i].c;
		}

		sort(data + 1, data + n + 1, [] (Data &a, Data &b) {
			return a.x < b.x;
		});

		int k1 = k / 2;
		int k2 = k - k1;

		FOR (i, 1, n) minLeft[i] = minRight[i] = 1e18;

		priority_queue<int, vector<int>> pq;

		ll sum = 0;

		FOR (i, 1, k1) {
			sum += data[i].c - data[i].x;
			pq.push(data[i].c - data[i].x);
		}
		FOR (i, k1 + 1, n) {
			minLeft[i] = sum;
			pq.push(data[i].c - data[i].x);
			sum += data[i].c - data[i].x;
			sum -= pq.top();
			pq.pop();
		}

		while (pq.size()) pq.pop();

		sum = 0;

		FORD (i, n, n - k2 + 1) {
			sum += data[i].c + data[i].x;
			pq.push(data[i].c + data[i].x);
		}
		FORD (i, n - k2, 1) {
			minRight[i] = sum;
			pq.push(data[i].c + data[i].x);
			sum += data[i].c + data[i].x;
			sum -= pq.top();
			pq.pop();
		}

		ll res = 1e18;
		FOR (i, 1, n) {
			ll cost = minLeft[i] + minRight[i] + (k1 - k2) * data[i].x + data[i].c;
			// cout << i << " " << cost << endl;
			res = min(res, cost);
		}

		while (pq.size()) pq.pop();
		cout << res << endl;
	}



	return 0;
}