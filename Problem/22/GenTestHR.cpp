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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i, 7, 7) { 
    	string cmd = "md dataHR";
    	system(cmd.c_str());  

    	cmd.clear();
    	ofstream inp("dataHR\\" + test(i) + ".txt");
    	//gen test here
        ll t = Rand(190, 200);
        inp << t << endl;
        inp << t << endl;
        FOR (z, 1, t) {
            ll n = Rand(100, 500);
                
            if (z < 100) {
                FOR (j, 1, n) {
                    if (Rand(0, 1) == 0) inp << "(";
                    else inp << ")";
                }
                inp << endl;
            }
            else {
                ll m = Rand (1, n);
                FOR (i, 1, n) {
                    if (i < m) {
                        if (Rand(0, 10) == 0) {
                            inp << "(";
                        }
                        else inp << ")";
                    }
                    else {
                        if (Rand(0, 10) == 0) {
                            inp << ")";
                        }
                        else inp << "(";   
                    }
                }
                inp << endl;
            }
        }

        inp << t << endl << 6 << endl;

        FOR (z, 1, t) {
            FOR (j, 1, 6) {
                if (z % 20) inp << Rand(0, 1e9) << " ";
                else inp << Rand(0, 100) << " ";
            }
            inp << endl;
        }
        /*
        FOR (z, 1, t) {
            ll n = Rand (4, 8);
            ll m = Rand (1, n);
            FOR (i, 1, n) {
                if (i < m) {
                    if (Rand(0, 10) == 0) {
                        inp << "(";
                    }
                    else inp << ")";
                }
                else {
                    if (Rand(0, 10) == 0) {
                        inp << ")";
                    }
                    else inp << "(";   
                }
            }
            inp << endl;

            FOR (i, 1, 6) {
                inp << Rand(0, 1000000000) << " ";
            }
            inp << endl;    
        }
        */
    }
	
    return 0;
}