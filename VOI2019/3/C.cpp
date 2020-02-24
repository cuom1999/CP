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

bool check(string s) {
	int d[10];
	FOR (i, 0, 9) d[i] = 0;
	for (int i = 0; i < s.length(); i++) {
		d[s[i] - '0']++;
	}
	int s1 = 0, s2 = 0, s3 = 0;
	FOR (i, 0, 9) {
		if (d[i] % 4 == 1) {
			s1++;
		}
		else if (d[i] % 4 == 2) {
			s2++;
		}
		else if (d[i] % 4 == 3) {
			s3++;
		}
	}
	if (s1 + s2 + s3 <= 1) return 1;
	if (s1 == 1 && s2 == 1 && s3 == 0) return 1;
	return 0;
}

string toString(ll x) {
	string res; 
	while (x) {
		res += (char) ((x % 10) + '0');
		x /= 10;
	}
	reverse(all(res));
	return res;
}

int C = 0;
vector<int> v[3000];
int has[3000], invHash[100005];


int toNum(vector<int>&v) {
	int sum = 0;
	int prod = 1;
	FOR (i, 0, 3) {
		sum += prod * v[i];
		prod *= 11;
	}
	return invHash[sum];
}

void preHand(int index, vector<int> &s, int sum) {
	if (index == 4) {
		if (sum == 0) {
			v[++C] = s;
			int sum = 0;
			int prod = 1;
			FOR (i, 0, 3) {
				sum += prod * s[i];
				prod *= 11;
			}
			invHash[sum] = C;
		}
		return;
	}
	FOR (i, 0, sum) {
		s.pb(i);
		preHand(index + 1, s, sum - i);
		s.pop_back();
	}
}

string a;
int d[50005][300][2][2];
const ll K = 1e9 + 7;

int s[4];
int dd[50005][10];
int cnt[50005][10];
int CC = 0;
ll calc(int index, int bit, bool tight, bool zero) {
	if (index == a.length()) {
	    if (!zero) return 0;
		vector<int> V = v[bit];
		int val = 0;
		if (V[0] >= 9) val = 1;
		if (V[0] == 8 && V[1] == 1 && V[2] == 1) val = 1;
		
		return val;
	}

	if (d[index][bit][tight][zero] != -1) return d[index][bit][tight][zero];
	CC++;
	
	int curDigit = a[index] - '0';
	ll val = 0;
	vector<int> V = v[bit]; 

	if (!zero) {
		val = (val + calc(index + 1, bit, 0, 0)) % K;
		int en = 9;
		if (tight) en = curDigit - 1;
		vector<int> newV = V;
		newV[0]--;
		newV[1]++;
		int newBit = toNum(newV);

		val = (val + en * 1ll * calc(index + 1, newBit, 0, 1)) % K;

		if (tight) {
			val = (val + calc(index + 1, newBit, 1, 1)) % K;
		}
	}
	else if (tight) {
	    FOR (i, 0, curDigit - 1) {
			vector<int> newV = V;
			newV[cnt[index][i] % 4]--;
			newV[(cnt[index][i] + 1) % 4]++;
			int newBit = toNum(newV);
			val = (val + calc(index + 1, newBit, 0, 1)) % K;
		}
		V[cnt[index][curDigit] % 4]--;
		V[cnt[index + 1][curDigit] % 4]++;
		int newBit = toNum(V);
		val = (val + calc(index + 1, newBit, 1, 1)) % K;
	}
	else {
		FOR (i, 0, 3) {
			if (V[i]) {
				vector<int> newV = V;
				newV[i]--;
				newV[(i + 1) % 4]++;
				int newBit = toNum(newV);
				val = (val + V[i] * 1ll * calc(index + 1, newBit, 0, 1)) % K;
			}
		}
	}
	
	return d[index][bit][tight][zero] = val;
} 

vector<int> rong;

ll solve() {
	FOR (i, 0, 50000) {
		FOR (j, 0, 290) {
			FOR (k, 0, 1) FOR (u, 0, 1) d[i][j][k][u] = -1;
		}
	}
	cin >> a;
	//cout << a.length() << endl;
	FOR (i, 0, 50000) {
		FOR (j, 0, 9) cnt[i][j] = 0;
	}	
	cnt[1][a[0] - '0'] = 1;
	FOR (i, 2, a.length()) {
		FOR (j, 0, 9) cnt[i][j] = cnt[i - 1][j];
		cnt[i][a[i - 1] - '0'] = (cnt[i][a[i - 1] - '0'] + 1);
	}	
	return calc(0, C, 1, 0);
}

int main()
{IN;//OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	preHand(0, rong, 10);

    /*
	ll n;
	cin >> n;
	int res = 0;
	FOR (i, 1, n) {
		if (check(toString(i))) res++;
	}
	cout << res << endl;*/
	ll A = solve();
	if (check(a)) A--;
	ll B = solve();

	cout << (B - A + K) % K << endl;
	cout << CC << endl;
	/*
	ll u, v;
	cin >> u >> v;
	ll res = 0;
	FOR (i, u, v) {
		if (check(toString(i))) res++;
	}
	cout << res << endl;
	*/
	return 0;
}