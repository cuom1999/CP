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

string numToStr(int x) {
	string res;
	if (x < 10) {
		res = "0";
		res += (char) (x + '0');
	}
	else if (x < 100) {
		res += (char) (x / 10 + '0');
		res += (char) (x % 10 + '0'); 
	}
	else {
		while(x) {
			res += (char) (x % 10 + '0');
			x /= 10;
		}
		reverse(all(res));
	}

	return res;
}


mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	vector<int> val = {0, 1, 2};
    int cnt = 0;	

    FOR (i, 100, 100) {
    	ofstream inp("Data\\LIXI" + numToStr(i) + ".inp");
    	
    	cnt++;

    	if (cnt <= 5) {
	    	ll n = Rand(3, 100000);
	    	inp << n << endl;

	    	FOR (j, 1, n) {
	    		inp << 3 * Rand(0, INF / 3 - 1) + val[Rand(0, val.size() - 1)] << " ";
	    	}
	    }
	    else {
	    	ll n = Rand(90000, 100000);
	    	inp << n << endl;

	    	FOR (j, 1, n) {
	    		inp << 3 * Rand(INF / 3 - 10000, INF / 3 - 1) + val[Rand(0, val.size() - 1)] << " ";
	    	}

	    }
    }
    
	
    return 0;
}