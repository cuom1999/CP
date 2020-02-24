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


int C = 0;
vector<int> v[3000];
int invHash[100005];


bool check(string s) {
	int d[10];
	FOR (i, 0, 9) d[i] = 0;
	for (int i = 1; i < s.length(); i++) {
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

vector<int> rong;

int f[50005][305], d[50005][302];
vector<II> V[305];
int chosen[305];
const ll K = 1e9 + 7;
int n;
string a;

vector<int> curV;
int cnt[50005][10];


int calc_f (int index, int bit) {
	if (index == n + 1) {
		return chosen[bit];
	}
	if (f[index][bit] != -1) return f[index][bit];
	int val = 0;
	for (auto j: V[bit]) {
		val = (val + j.second * 1ll * calc_f(index + 1, j.first)) % K;
	}

	return f[index][bit] = val;
}

int calc(int index, int bit) {
	if (index == n + 1) {
		return chosen[bit];
	}
	if (d[index][bit] != -1) return d[index][bit];
	int val = 0;
	int curDigit = a[index] - '0';
	vector<int> V = v[bit];

	FOR (i, 0, curDigit - 1) {
		V[cnt[index][i]]--;
		V[(cnt[index][i] + 1) % 4]++;

		int newBit = toNum(V); 
		val = (val + calc_f(index + 1, newBit)) % K;

		V[(cnt[index][i] + 1) % 4]--;
		V[cnt[index][i]]++;
	}

	vector<int> newV = V;
	newV[cnt[index][curDigit]]--;
	newV[cnt[index + 1][curDigit]]++;
	int newBit = toNum(newV);
	val = (val + calc(index + 1, newBit)) % K;

	return 	d[index][bit] = val;
}


int solve() {
	n = a.length();
	a = '0' + a;

	FOR (i, 0, n + 1) {
		FOR (j, 1, C) f[i][j] = -1, d[i][j] = -1;
	}
	FOR (i, 0, 50001) {
		FOR (j, 0, 9) cnt[i][j] = 0;
	}	
	cnt[2][a[1] - '0'] = 1;

	FOR (i, 3, n + 1) {
		FOR (j, 0, 9) cnt[i][j] = cnt[i - 1][j];
		cnt[i][a[i - 1] - '0'] = (cnt[i][a[i - 1] - '0'] + 1) % 4;
	}	

	int res = calc(1, C);

	vector<int> V(4);
	V[0] = 9, V[1] = 1;
	int C1 = toNum(V);


	FOR (i, 2, n + 1) {
		res = (res + calc_f(i, C) - calc_f(i, C1)) % K;
	}
	return (res + K) % K;
}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    preHand(0, rong, 10);

    
	FOR (i, 1, C) {
		FOR (j, 0, 3) {
			if (v[i][j]) {
				vector<int> newV = v[i];
				newV[j]--;
				newV[(j + 1) % 4]++;
				int newBit = toNum(newV);
				V[i].pb(II(newBit, v[i][j]));
			}
		}
	}

	FOR (bit, 1, C) {
		vector<int> V = v[bit];
		int val = 0;
		if (V[0] >= 9) val = 1;
		if (V[0] == 8 && V[1] == 1 && V[2] == 1) val = 1;
		chosen[bit] = val;
	}

	cin >> a;
	int A = solve();
	if (check(a)) A--;
	
	cin >> a;
	int B = solve();

	cout << (B - A + K) % K << endl;



    return 0;
}