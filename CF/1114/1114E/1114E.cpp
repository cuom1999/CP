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


mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int a[1000005];
int M = 0;

void genT(int n) {
	int x1 = Rand(1, 10000);
	int d = Rand(0, (INF - n) / d / 2);
	cout << x1 << " " << d << endl;
	FOR (i, 1, n) a[i] = x1 + (i - 1) * d;
	M = a[n];
	random_shuffle(a + 1, a + n + 1);
}

int ask1(int i) {
	/*cout << "? " << i << endl;
	int x;
	cin >> x;
	return x;*/
	return a[i];
}

int ask2(int x) {
	/*cout << "> " << x << endl;
	int x;
	cin >> x;
	return x;
	*/
	if (M > x) return 1;
	return 0;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    genT(n);

    int L = 1, R = INF;

    while (L < R) {
    	int mid = (L + R) / 2;
    	int u = ask2(mid);
    	if (u == 0) {
    		R = mid;
    	}
    	else L = mid + 1;
    }

    int m = min(n, 29);
    set<int> v;
    while(v.size() < m) {
    	v.insert(Rand(1, n));
    }

    int d = 0;

    for (auto i: v) {
    	int u = ask1(i);
    	d = __gcd(d, L - u);
    }
    int x1 = L - (n - 1) * d;

    cout << "! " << x1 << " " << d << endl;
    
	
    return 0;
}