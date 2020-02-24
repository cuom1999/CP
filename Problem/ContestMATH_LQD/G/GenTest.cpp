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
	else {
		res += (char) (x / 10 + '0');
		res += (char) (x % 10 + '0'); 
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

    FOR (iTest, 41, 50) {
        ofstream inp("Data\\TSLQD" + numToStr(iTest) + ".inp");

        ll m = Rand(1000 - 10, 1000);
        ll n = Rand(1000 - 10, 1000);
        ll q = Rand(100000 - 10, 100000);
        inp << m << " " << n << " " << q << "\n";

        FOR (i, 1, m) {
            FOR (j, 1, n) {
                inp << Rand(-1e9, 1e9) << " ";
            } 
            inp << "\n";
        }

        FOR (z, 1, q) {
            ll x1 = Rand(1, m);
            ll y1 = Rand(1, n);
            ll x2 = Rand(1, m);
            ll y2 = Rand(1, n);

            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);

            inp << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        } 
    }


    

    return 0;
}