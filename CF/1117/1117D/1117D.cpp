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

const ll K = 1e9 + 7;

struct Matrix {
	ll coef[105][105];

	Matrix() {
		FOR (i, 0, 100) {
			FOR (j, 0, 100) coef[i][j] = 0;
		}
	}

	Matrix operator * (Matrix a) {
		Matrix res;

		FOR (i, 1, 100) {
			FOR (j, 1, 100) {
				FOR (k, 1, 100) {
					res.coef[i][j] = (res.coef[i][j] + coef[i][k] * a.coef[k][j] % K) % K;
				}
 			}
		}
		return res;
	}

};

Matrix mu(Matrix A, ll n) {
	if (n == 1) return A;
	Matrix Q = mu(A, n / 2);

	if (n % 2 == 0) return Q * Q;
	return Q * Q * A;
}

Matrix A, B;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    A.coef[1][1] = A.coef[1][m] = 1;

    FOR (i, 2, m) {
    	A.coef[i][i - 1] = 1;
    }

    FOR (i, 1, m) B.coef[i][1] = 1;

    if (n < m) {
    	cout << 1 << endl;
    	return 0;
    } 

    A = mu(A, n + 1 - m);
    Matrix res = A * B;

    cout << res.coef[1][1] << endl;
	
    return 0;
}