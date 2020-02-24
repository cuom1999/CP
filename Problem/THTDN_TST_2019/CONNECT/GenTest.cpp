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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

const string NAME = "CONNECT";

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

ofstream inp;

void genRand(ll MINN, ll MAXN) {
    ll m = Rand(MINN, MAXN);
    ll n = Rand(MINN, MAXN);

    inp << n << " " << m << "\n";
    FOR (i, 1, m) {
        ll u = Rand(1, n);
        ll v = Rand(1, n);
        while (u == v) v = Rand(1, n);
        inp << u << " " << v << "\n";
    }
}

void genRand2(ll MINN, ll MAXN) {
    ll m = Rand(MINN, MAXN);
    ll n = Rand(MINN, MAXN);
    while (m < n) m = Rand(MINN, MAXN);
    inp << n << " " << m << "\n";
    FOR (i, 1, m) {
        ll u = Rand(1, n);
        ll v = Rand(1, n);
        while (u == v) v = Rand(1, n);
        inp << u << " " << v << "\n";
    }
}


void genNo(ll MINN, ll MAXN) {
    ll m = Rand(MINN, MAXN);
    ll n = Rand(MINN, MAXN);
    while (m < n + 10000) m = Rand(MINN, MAXN), n = Rand(MINN, MAXN);
    vector<int> v;
    FOR (i, 1, n) {
        v.pb(i);
    }
    shuffle(all(v), gen);
    vector<II> edges;
    FOR (i, 0, n - 2) {
        edges.pb({v[i], v[i + 1]});
    }
    edges.pb({v.back(), v[0]});
    while (edges.size() < m) {
        ll u = Rand(1, n);
        ll v = Rand(1, n);
        while (u == v) v = Rand(1, n);
        edges.pb({u, v});
    }

    shuffle(all(edges), gen);
    inp << n << " " << m << "\n";
    for (auto i: edges) {
        inp << i.first << " " << i.second << "\n";
    }
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (z, 9, 10) { 
    	string cmd = "md ";
    	cmd += test(z);
    	system(cmd.c_str());  

    	cmd.clear();
    	inp = ofstream("" + test(z) + "\\" + NAME + ".inp");

    	//gen test here
        ll t = Rand(5, 5);
        inp << t << "\n";
        FOR (z, 1, t) {
            ll u = Rand(0, 2);
            if (u == 0) genRand(80000, 100000);
            if (u == 1) genRand2(80000, 100000);
            if (u == 2) genNo(80000, 100000);
        }
    }

    return 0;
}