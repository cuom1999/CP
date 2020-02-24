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

int n;
 	
int d[805][2004][10];
int a[2005], b[2005];
int has[805], invHash[2000000];
int sum[805];

inline int abs(int x) {
	if (x < 0) return -x;
	return x;
}


void transformToArray(int x, int a[10]) {
	FOR (i, 0, 9) a[i] = 0;
	int stt = 0;
	x = has[x];
	while (x) {
		a[++stt] = x % 5;
		x /= 5;
	}
}

int transformToBit(int a[10]) {
	int val = 0;
	int p = 1;
	FOR (i, 1, 9) {
		val += p * a[i];
		p *= 5;
	}
	return invHash[val];
}


int C = 0;

void init(int i, vector<int> &v) {
	if (i == 10) {
		int s = 0;
		for (auto j: v) {
			s += j;
		}
		if (s <= 4) {
			int val = 0;
			int p = 1;
			int S = 0;
			FOR (j, 0, 8) {
				val += p * v[j];
				p *= 5;
				S += v[j];
			}
			has[C] = val;
			invHash[val] = C;
			sum[C] = S;
			C++;
		}
		return;
	}

	FOR (j, 0, 4) {
		v.pb(j);
		init(i + 1, v);
		v.pop_back();
	}
}
vector<int> rong;

int calc(int bit, int index, int floor) {
	if (index == n) {
		if (bit == 0) return 0;
	}
	if (d[bit][index][floor] != -1) return d[bit][index][floor];
	int s[10];
	transformToArray(bit, s);
	int val = INF;
	if (sum[bit] < 4 && index < n) {
		s[b[index + 1]]++;
		int newBit = transformToBit(s);
		val = min(val, calc(newBit, index + 1, a[index + 1]) + abs(a[index + 1] - floor));
		s[b[index + 1]]--;
	}
	FOR (i, 1, 9) {
		int u = s[i];
		if (s[i]) {
			s[i] = 0;
			int newBit = transformToBit(s);
			val = min(val, calc(newBit, index, i) + abs(i - floor));
		}
		s[i] = u;
	}
	/*
	transformToArray(bit, s);
	FOR (i, 1, 9) cout << s[i] << " ";
	cout << ": " << bit << " " ; 
 	cout << index << " " << floor << ": " << val << endl;*/
	return d[bit][index][floor] = val;
}


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	cin >> n;
 	FOR (i, 1, n) cin >> a[i] >> b[i];
 	init(1, rong);
 	FOR (i, 0, 800) {
 		FOR (j, 0, 2000) {
 			FOR (k, 0, 9) d[i][j][k] = -1;
 		}
 	}
 	cout << calc(0, 0, 1) + 2 * n << endl;

    return 0;
}