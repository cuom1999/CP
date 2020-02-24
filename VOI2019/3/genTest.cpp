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

const string NAME = "ASPAL";

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

string test(int x) {
	if (x < 10) {
		string s = "ASPAL0";
		s += (char) (x + '0');
		return s;
	}
	string s = "ASPAL";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

bool cmp(string a, string b) {
    if (a.length() < b.length()) return 0;
    if (a.length() > b.length()) return 1;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] < b[i]) return 0;
        return 1;
    }
    return 0;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (z, 21, 21) { 
    	ofstream inp("data\\" + test(z) + ".inp");

    	//gen test here
        string a;
        ll u = Rand(49000, 50000);
        FOR (i, 1, u) {
            a += (char) (Rand(0, 9) + '0');
        }
        while (a[0] == '0') a[0] = (char) (Rand(0, 9) + '0');

        string b;
        u = Rand(49000, 50000);
        
        FOR (i, 1, u) {
            b += (char) (Rand(0, 9) + '0');
        }
        while (b[0] == '0') b[0] = (char) (Rand(0, 9) + '0');
        
        if (cmp(a, b)) swap(a, b);
        inp << a << " " << b << endl;

    }
	
    return 0;
}