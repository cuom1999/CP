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

vector<II> valX, valY, sweepLine;

int x[5][1000005], y[5][1000005];
int fen[2000005];

void add(int u, int v) {
	for (int i = u; i <= 1000002; i += i & -i) {
		fen[i] += v;
	}
}

int getSum(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}


int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;

    cin >> n;

    FOR (i, 1, n) {
    	cin >> x[1][i] >> y[1][i] >> x[2][i] >> y[2][i];
    	x[1][i]++;
    	y[1][i]++;
    	x[2][i]++;
    	y[2][i]++;
    }


	FOR (i, 1, n) {
		sweepLine.pb(II(x[1][i], i));
		sweepLine.pb(II(x[2][i], -i));
	}    	

	sort(all(sweepLine));

	int res = 0;

	for (auto i: sweepLine) {
		if (i.second > 0) {
			int val = getSum(y[2][i.second]) + getSum(y[1][i.second]);
			if (!val) res++;

			add(y[1][i.second], 1);
			add(y[2][i.second] + 1, -1);
		}
		else {
			add(y[1][-i.second], -1);
			add(y[2][-i.second] + 1, 1);
		}

		//FOR (i, 1, 11) cout << getSum(i) << " "; cout << endl;
	}

	cout << res << endl;
	
    return 0;
}