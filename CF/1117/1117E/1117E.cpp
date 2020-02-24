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

const int N = 26;

bitset<N * N * N> bs[4][N + 2], ans[4][N + 2];
int a[18000][4];
int p[18000], rev[18000];


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 0, N * N * N - 1) {
    	bs[1][i / (N * N)][i] = 1;
    	bs[2][(i % (N * N)) / N][i] = 1;
    	bs[3][i % N][i] = 1;
    }

	FOR (i, 0, N - 1) {
		FOR (j, 0, N - 1) {
			FOR (k, 0, N - 1) {
				bitset<N * N * N> tmp = bs[1][i] & bs[2][j] & bs[3][k];
				if (tmp.count()) {
					a[tmp._Find_first()][1] = i;
					a[tmp._Find_first()][2] = j;
					a[tmp._Find_first()][3] = k;
				}
			}
		}
	}

	string original;

	cin >> original;

	int n = original.size();

	FOR (u, 1, 3) {
		string query;
		FOR (i, 0, n - 1) query += '0';

		FOR (i, 0, N - 1) {
	    	for (int j = bs[u][i]._Find_first(); j < bs[u][i].size(); j = bs[u][i]._Find_next(j)) {
	    		if (j < n) {
	    			query[j] = i + 'a';
	    		}
	    	}
	    }

	    cout << "? " << query << endl;
	    
	    string res;
	    cin >> res;

	    FOR (i, 0, n - 1) {
	    	ans[u][res[i] - 'a'][i] = 1;
	    }
	}

	FOR (i, 0, n - 1) {
		p[i] = (ans[1][a[i][1]] & ans[2][a[i][2]] & ans[3][a[i][3]])._Find_first();
		rev[p[i]] = i;
	}

	string res = original;

	FOR (i, 0, n - 1) {
		res[i] = original[p[i]];
	}

	cout << "! " << res << endl;
        
	return 0;
}