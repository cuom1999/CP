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

ld d[305][305][305]; 
int cnt[5];
int n;

ld calc (int i, int j, int k) {
	if (i < 0 || j < 0 || k < 0) return 0;

	if (d[i][j][k] != -1) return d[i][j][k];


	int sum = i + j + k;

	return d[i][j][k] = n * 1.0 / sum + calc(i, j + 1, k - 1) * k  * 1.0 / sum + calc(i + 1, j - 1, k) * j * 1.0 / sum + calc(i - 1, j, k) * i * 1.0 / sum;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;

    FOR (i, 1, n) {
    	int x;
    	cin >> x;
    	cnt[x]++;
    }


    FOR (i, 0, n) {
    	FOR (j, 0, n) {
    		FOR (k, 0, n) {
    			d[i][j][k] = -1;
    		}
    	}
    }

    d[0][0][0] = 0;

    cout << fixed << setprecision(11) <<  calc(cnt[1], cnt[2], cnt[3]) << endl;

    return 0;
}