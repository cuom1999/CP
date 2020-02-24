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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;


set<II> s;

bool check(int x, int y) {
	if (x >= 1 && x <= 8 && y >= 1 && y <= 8) return 1;
	return 0;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	string pos;
	cin >> pos;

	int x = pos[0] - 'a' + 1;
	int y = pos[1] - '0';

	for(int i = -1; i <= 1; i += 2){
		for(int j = -1; j <= 1; j += 2){
			s.insert(II(i * a + x, j * b + y));
			s.insert(II(i * b + x, j * a + y));
		}		
	}

	set<II> res;
	for (auto i: s) {
		if (check(i.first, i.second)) res.insert(i);
	}

	cout << res.size() << endl;

	for (auto j: res) {
		cout << (char) (j.first + 'a' - 1) << j.second << " ";
	}

	return 0;
}