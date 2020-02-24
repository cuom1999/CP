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

vector<int> prime;
int comp[1000005];
int trace[1000005];

void sieve(int n) {
	FOR(i, 2, n){
		if (!comp[i]) {
			prime.pb(i);
			trace[i] = i;
		}
		for (int j = 0; j < prime.size() && prime[j] <= n / i; j++) {
			comp[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				trace[i * prime[j]] = trace[i];
				break;
			}
			else{
				trace[i * prime[j]] = prime[j];
			}
		}
	}
}
vector<int> divisor[1000005];

struct matrix {
	int a[2][2];
	matrix(){
		FOR (i, 0, 1) 
			FOR (j, 0, 1) a[i][j] = 0;
	}
};

matrix mul(matrix a, matrix b, int p){
	matrix res;
	FOR (i, 0, 1) {
		FOR (j, 0, 1) {
			FOR (k, 0, 1) {
				res.a[i][j] = (res.a[i][j] + a.a[i][k] * 1ll * b.a[k][j]) % p;
			}
		}
	}
	return res;
}

matrix mu(matrix a, ll n, int p) { 
	if (n == 1) return a;
	matrix q = mu(a, n / 2, p);
	if (n % 2 == 0) return mul(q, q, p);
	return mul(mul(q, q, p), a, p);
}
matrix A, B;

int fib(int n, ll p){
	B = mu(A, n, p);
	return B.a[0][1];
}

int f[1000005];

int calc(int p){
	if (p == 2) return f[2] = 3;
	if (p == 5) return f[5] = 20;
	if (f[p]) return f[p];
	for (int j = 0; j < divisor[p].size(); j++) {
		int i = divisor[p][j];
		if (fib(i, p) == 0 && fib(i + 1, p) == 1) return f[p] = i;
	}
	return 0;
}

inline int lcm (int a, int b) {
	return a / __gcd(a,b) * b;
}

void calc2(int n){
	int N = n;
	int res = 0;
	if (f[n]) return;
	while (n > 1) {
		int u = trace[n];
		int prod = f[u];
		n /= u;
		while (n % u == 0) {
			prod *= u;
			n /= u;
		}
		if (!res) res = prod;
		else {
			res = lcm(res, prod);
		}
	}
	f[N] = res;

	return;
}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    A.a[0][0] = 1; A.a[0][1] = 1;
    A.a[1][0] = 1;
    sieve(1000000);
    int cnt = 0;
    FOR (i, 2, 2000002) {
    	for (int j = 1; j <= 2000002 / i; j++) {
    		int u = i * j;
    		if (u % 2) continue;
    		int y = (u - 2) / 2;
    		if (comp[y] == 0 && ((y % 10 == 3) || (y % 10 == 7))){
    			divisor[y].pb(i);
    		}
    		
    		if (u >= 1000000) continue;
    		int x = u + 1;
    		if (comp[x] == 0 && ((x % 10 == 1) || (x % 10 == 9))){
    			divisor[x].pb(i);
    		}
    	}
    }
    for (int i = 0; i < prime.size(); i++){
    	calc(prime[i]);
    }
    
    FOR (i, 2, 1000000) {
    	calc2(i);
    }

    f[1] = 1;
    int t;
    cin >> t;
    FOR (z, 1, t) {
    	int p;
    	ll n, k;
    	cin >> n >> k >> p;
    	while (p > 1 && k > 1) {
    		//cout << k << " " << n << " " << p << endl;
    		k--;
    		n %= f[p];
    		p = f[p];
    	}
    	if (k == 1) {
    		cout << fib(n, p) << endl;
    	}
    	else {
    		cout << 1 << endl;
    	}
    }





}