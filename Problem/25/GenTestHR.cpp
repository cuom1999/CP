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

string test(int x) {
	if (x < 10) {
		string s = "input00";
		s += (char) (x + '0');
		return s;
	}
	string s = "input0";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

char c[1505][1505];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string cmd = "md dataHR";
    system(cmd.c_str());  

    FOR (iT, 9, 9) { 
    	
    	//cmd.clear();
    	ofstream inp("dataHR\\" + test(iT) + ".txt");
    	//gen test here
        ll m = Rand(1800, 2000);
        ll n = Rand(1800, 2000);
        inp << m << endl << n << endl;
        
        ll st = Rand(1, n), en = Rand(1, n);

        FOR (i, 1, m) {
            FOR (j, 1, n) {
                if (Rand(0, 800000) == 0) inp << "# ";
                else inp << ". "; 
            }
            inp << endl;
        } 
    }
	
    return 0;
}