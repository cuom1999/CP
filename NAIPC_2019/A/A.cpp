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

int n;

ld gt[2505];
ld logCombi(int n, int k) {
	if (n < k || k < 0) return -1;
	return gt[n] - gt[n - k] - gt[k];
}

ld x[2505], y[2505];

ll combi(int n, int k) {
	if (n < k || k < 0) return 0;
	ll res = 1;
	FOR (i, n - k + 1, n) {
		res *= i;
	}
	FOR (i, 1, k) res /= i;
	return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0] = 0;

    FOR (i, 1, 2500) {
    	gt[i] = gt[i - 1] + log2(i);
    }

   	int k;
   	cin >> n >> k;

   	FOR (i, 1, n) {
   		cin >> x[i] >> y[i];
   	}

    ld res = 0;

    FOR (i, 1, n) {
    	FOR (j, 1, n) {
    		if (i == j) continue;
    		int t = 0;
    		if (i > j) {
    			t = n - 2 - (i - j - 1);
    		}
    		else {
    			t = j - i - 1;
    		}

    		ld val = x[i] * y[j] - x[j] * y[i];

    		if (t < k - 2) continue;

    		ld logVal = gt[t] - gt[k - 2] - gt[t - k + 2] - gt[n] + gt[k] + gt[n - k];
    		
    		val = val * pow(2, logVal) / 2.0;

    		//val = val * combi(t, k - 2) * 1.0 / combi(n, k) / 2.0;

    		res += val;

    		//cout << val << " " << val1 << endl;

    		//cout << i << " " << j << " " << " " << t << " " << val << endl;

    		//cout << gt[t] - gt[k - 2] - gt[t - k + 2] << " " << combi(t, k - 2) << endl;

    	}
    }

    cout << fixed << setprecision(8) << res << endl;	





    
	
    return 0;
}