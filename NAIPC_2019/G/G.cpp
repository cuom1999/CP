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

int x[5][100005], y[5][100005];
int fen[200005];

void add(int u, int v) {
	for (int i = u; i <= 200000; i += i & -i) {
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
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;

    cin >> n;

    FOR (i, 1, n) {
    	int x1, y1, x2, y2;

    	cin >> x1 >> y1 >> x2 >> y2;

    	valX.pb(II(x1, i));
    	valX.pb(II(x2, i));

    	valY.pb(II(y1, i));
    	valY.pb(II(y2, i));
    }

    sort(all(valX));
    sort(all(valY));



    FOR (i, 0, 2 * n - 1) {
    	if (!x[1][valX[i].second]) {
    		x[1][valX[i].second] = i + 1;
     	}
     	else {
     		x[2][valX[i].second] = i + 1;
     	}

     	if (!y[1][valY[i].second]) {
    		y[1][valY[i].second] = i + 1;
     	}
     	else {
     		y[2][valY[i].second] = i + 1;
     	}
    }

	FOR (i, 1, n) {
		sweepLine.pb(II(x[1][i], i));
		sweepLine.pb(II(x[2][i], -i));
	}    	

	sort(all(sweepLine));

	for (auto i: sweepLine) {
		if (i.second > 0) {
			add(y[1][i.second], 1);
			add(y[2][i.second], 1);
		}
		else {
			int val = getSum(y[2][-i.second] - 1) - getSum(y[1][-i.second]);
			if (val > 0) {
				cout << 1 << endl;
				return 0;
			}
			add(y[1][-i.second], -1);
			add(y[2][-i.second], -1);
		}

		//FOR (i, 1, 2 * n) cout << getSum(i) - getSum(i - 1) << " "; cout << endl;
	}

	cout << 0 << endl;
	
    return 0;
}