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

const string NAME = "LAMP";

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

string test(int x) {
	if (x < 10) {
		string s = "test0";
		s += (char) (x + '0');
		return s;
	}
	string s = "test";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (z, 20, 20) { 
    	string cmd = "md ";
    	cmd += test(z);
    	system(cmd.c_str());  

    	cmd.clear();
    	ofstream inp("" + test(z) + "\\" + NAME + ".inp");

    	//gen test here
        ll n = Rand(1000000000, 1000000000);
        ll q = Rand(300000, 300000);
        inp << n << " " << q << endl;
        FOR (i, 1, q) {
            ll k = Rand(0, 1);
            ll l = Rand(1, n);
            ll r = Rand(1, n);
            if (l > r) swap(l, r);
            inp << k << " " << l << " " << r << endl;
        }
    }
	
    return 0;
}