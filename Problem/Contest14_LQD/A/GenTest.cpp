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
{
    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    int a[15][15];
    int numTest = 0;
    while (cin >> n) {
        numTest++;
        FOR (i, 1, n) {
            FOR (j, 1, n) cin >> a[i][j];
        }
        ofstream inp("Data\\14A" + numToStr(numTest) + ".inp");
        inp << n << "\n";
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                inp << a[i][j] << " ";
            }
            inp << "\n";
        }
    }


    
	
    return 0;
}