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


// remember n = s.length()
// LCP[i] = lcp(SA[i - 1], SA[i]); i = 1 -> n
// lcp(i, j) = min(LCP[i + 1],..., LCP[j])


const int MAXN = 100005;

int t, SA[MAXN], RA[MAXN], c[MAXN], tempRA[MAXN], tempSA[MAXN], n,
behind[MAXN], LCP[MAXN], PLCP[MAXN];
string s;

void countingSort(int k)
{
	int sum = 0, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	FOR(i,0,n-1)
	if (i+k < n) c[RA[i+k]]++;
	else c[0]++;
	FOR(i,0,maxi-1) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	} 
	FOR(i,0,n-1) {
		int a = 0;
		if (SA[i]+k < n) a = RA[SA[i]+k];
		tempSA[c[a]++] = SA[i];
	} 
	FOR(i,0,n-1) SA[i] = tempSA[i];
}

void suffixArray()
{
	int r;
	FOR(i,0,n-1) SA[i] = i;
	FOR(i,0,n-1) RA[i] = s[i];
	for (int k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		FOR(i,1,n-1) {
			if (RA[SA[i]] != RA[SA[i-1]]) {
				tempRA[SA[i]] = ++r;
				continue;
			} 
			int a, b;
			if (SA[i]+k >= n) a = 0;
			else a = RA[SA[i]+k];
			if (SA[i-1]+k >= n) b = 0;
			else b = RA[SA[i-1]+k];
			if (a == b) tempRA[SA[i]] = r;
			else tempRA[SA[i]] = ++r;
		}
		FOR(i,0,n-1) RA[i] = tempRA[i];
		if (r == n-1) break;
	}
} 
void buildLCP()
{
	behind[SA[0]] = -1;
	FOR(i,1,n-1) behind[SA[i]] = SA[i-1];
	int L = 0;
	FOR(i,0,n-1) {
		if (behind[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (s[i+L] == s[behind[i]+L]) L++;
		PLCP[i] = L;
		L = max(L-1,0);
	}
	FOR(i,0,n-1) LCP[i] = PLCP[SA[i]];
}

ll sum(ll l, ll r) {
	return r * (r + 1) / 2 - l * (l - 1) / 2;
}

void solve(string &tmp) {
	s = tmp;
	n = s.length();
	// cout << s << endl;
	suffixArray();
	buildLCP();

	ll res = 0;
	ll res1 = 0;

	// FOR (i, 0, n - 1) cout << SA[i] << " ";
	// cout << endl;

	// FOR (i, 1, n) cout << LCP[i] << " ";
	// cout << endl;

	FOR (i, 0, n - 1) {
		if (i) {
			res += n - SA[i] - LCP[i];
			res1 += sum(LCP[i] + 1, n - SA[i]);
		}
		else {
			res += n - SA[i];
			res1 += sum(1, n - SA[i]);
		}
	}
	cout << res << " " << res1 << endl;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string ss;
	cin >> ss;
	string tmp;
	for (int i = 0; i < ss.size(); i++) {
		tmp += ss[i];
		solve(tmp);
	}
	
	return 0;
}