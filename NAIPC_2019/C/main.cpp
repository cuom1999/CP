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



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ifstream out("output.txt");
    ifstream ans("ans.txt");

    vector<ld> outData, ansData;

    ld x;

    while (out >> x) {
    	outData.pb(x);
    }

    while(ans >> x) {
    	ansData.pb(x);
    }

    for (int i = 0; i < outData.size(); i++) {
    	if (abs(outData[i] - ansData[i]) / max((ld) 1, ansData[i]) > 1e-4) {
    		cout << i + 1 << endl;
    		return 0;
    	}
    } 

    cout << "AC";

    
	
    return 0;
}