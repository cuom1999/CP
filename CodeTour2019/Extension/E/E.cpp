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

string s;

int cnt[500];

vector<char> tetrix = {'J', 'L', 'S', 'Z', 'O', 'I', 'T'};

bool check(int x) {
	x *= 7;
	int n = s.length();
	multiset<int> se[2005];

	for (int i = 0; i < s.length(); i++) {
		se[i / x].insert(s[i]); 
	}

	FOR (i, 0, (n - 1) / x) {
		if (i != (n - 1) / x)  {
			for (auto j: tetrix) {
				if (se[i].count(j) != x / 7) {
					return 0;
				}
			}
		}
		else {
			for (auto j: tetrix) {
				if (se[i].count(j) > x / 7) return 0;
			}
		}
	}

	return 1;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	// int L = 1, R = s.length() / 7 + 2;

	// while (L < R) {
	// 	int mid = (L + R) / 2;
	// 	if (check(mid)) R = mid;
	// 	else {
	// 		L = mid + 1;
	// 	} 
	// }

	int res = 1;
	while (1) {
		if (check(res)) {
			cout << res * 7 << endl;
			return 0;
		}
		res++;
	}
	// cout << L * 7 << endl;


	return 0;	
}