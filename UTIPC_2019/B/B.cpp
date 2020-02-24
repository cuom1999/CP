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

const ll K = 998244353;
ll d[100005][2][2][2][2][2];


ll dp(int index, int oddSuf, int evenSuf, int scary, int notZero, int tight) {
	if (d[index][oddSuf][evenSuf][scary][notZero][tight] != -1) return d[index][oddSuf][evenSuf][scary][notZero][tight];
	// cout << index << " " << oddSuf << " " << scary << " " << notZero << " " << tight << endl;
		
	if (index == s.length()) {
		if (notZero && scary) return 1;
		return 0;
	}

	int startDig = 0;
	int endDig = 9;

	if (tight == 1) endDig = s[index] - '0';

	ll res = 0;

	FOR (i, startDig, endDig) {
		int newTight = (int) (i == endDig);
		if (tight == 0) newTight = 0;

		int newNotZero = (bool) (notZero | i);
		// cout << i << endl;
		if (i % 2) {
			int newOddSuf = (evenSuf + 1) % 2;
			int newEvenSuf = (oddSuf);
			res = (res + dp(index + 1, newOddSuf, newEvenSuf, (scary + newEvenSuf) % 2, newNotZero, newTight)) % K;
		}
		else {
			if (!newNotZero) {
				res = (res + dp(index + 1, 0, 0, 0, newNotZero, newTight)) % K;
			}
			else {
				int newOddSuf = oddSuf;
				int newEvenSuf = (evenSuf + 1) % 2;
				res = (res + dp(index + 1, newOddSuf, newEvenSuf, (scary + newEvenSuf) % 2, newNotZero, newTight)) % K;	
			}
		}
	}
	// cout << index << " " << oddSuf << " " << evenSuf << " " << scary << " " << notZero << " " << tight << " " << res << endl;
	
	return d[index][oddSuf][evenSuf][scary][notZero][tight] = res;
}

ll calc(string &a) {
	s = a;
	memset(d, -1, sizeof(d));
	return dp(0, 0, 0, 0, 0, 1);
}

bool check(string &s) {
	int odd = 0, even = 0;
	bool res = 0;

	for (int i = 0; i < s.length(); i++) {
		if ((s[i] - '0') % 2 == 0) {
			even ^= 1;
		}
		else {
			swap(odd, even);
			odd ^= 1;
		}
		res ^= even;
	}
	return res;
}

int main()
{IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	string l, r;
	cin >> l >> r;

	ll res = calc(r);
	res = (res - calc(l) + K) % K;
	if (check(l)) res = (res + 1) % K;

	cout << res << endl;
	
	// res = 0;


	// FOR (i, stoi(l), stoi(r)) {
	// 	string tmp = to_string(i);
	// 	if (check(tmp)) res++;
	// }
	// cout << res << endl;


	return 0;
}