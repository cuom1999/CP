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
		string s = "input0";
		s += (char) (x + '0');
		return s;
	}
	string s = "input";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int MINN = 200000;
    int MAXN = 200000;
    FOR (i, 40, 40) { 
    	string cmd = "md dataHR\\input";
    	system(cmd.c_str());  

    	cmd.clear();
    	ofstream inp("dataHR\\input\\" + test(i) + ".txt");
    	//gen test here
    	ll m = Rand(MINN, MAXN);
        ll n = Rand(MINN, MAXN);
        ll q = Rand(MINN, MAXN);
        if (Rand(0, 1) == 0) swap(m, n);

        inp << m << " " << n << " " << q << endl;
        vector<ll> v;
        FOR (i, 0, min(m, n)) v.pb(i);
        while (v.size() < q) v.pb(Rand(0, m * n));
        shuffle(all(v), gen);
        while (v.size() > q) v.pop_back();
        for (auto i: v) inp << i << "\n";
    }
	
    return 0;
}