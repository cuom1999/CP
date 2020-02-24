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

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

const ll K = 1000000007; 
string s, t;
const ll U = 930000000;
const ll V = 730000000;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    string Y = "icpc-sg-2018-at-nus";
    ll n;
    cin >> n;
    while (1) {
    	s.clear();
    	t.clear();
	    FOR (i, 1, 50) {
	    	s += (char) ('a' + rand() % 26);
	    	t += (char) ('a' + rand() % 26);
	    }
	    //s = "charlie-pays-to-eve-9-sg-coins";
	    //t = "icpc-sg-2018-at-nus";
	    ll h = H(n, s, 0);
	    ll A = (K + U - h) % K;
	    h = H(U, t, 0);
	    ll B = (K + V - h) % K;
	    if (A < 1000000000 && B < 1000000000) {
	    	cout << s << " " << A << endl;
	    	cout << t << " " << B << endl;
	    	return 0;
	    }
	}
	
    return 0;
}