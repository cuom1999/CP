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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<II> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int k, n;
 	cin >> n >> k;

 	FOR (i, 1, n) {
 		int t, b;
 		cin >> t >> b;
 		v.pb(II(-b, t));
 	}   	

 	sort(all(v));

 	ll res = 0;
 	ll sum = 0;
 	for (auto i: v) {
 		res = max(res, (sum + i.second) * 1ll * -i.first);

 		sum += i.second;
 		pq.push(i.second);

 		if (pq.size() > k - 1) {
 			sum -= pq.top();
 			pq.pop();
 		}
 	}

 	cout << res << endl;


	

    return 0;
}