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
	ll coef[51][51];

	Matrix() {
		FOR (i, 0, 50) {
			FOR (j, 0, 50) coef[i][j] = 0;
		}
	}

	Matrix operator * (const Matrix &a) {
		Matrix res;
		FOR (i, 1, 50) {
			FOR (j, 1, 50) {
				FOR (k, 1, 50) {
					res.coef[i][j] += coef[i][k] * a.coef[k][j] % K;
					res.coef[i][j] %= K;
				}
			}
		}
		return res;
	}

};

Matrix A;

Matrix mu(Matrix &A, ll n) {
	if (n == 1) {
		return A;
	}

	Matrix Q = mu(A, n / 2);

	if (n % 2 == 0) {
		return Q * Q;
	}
	return Q * Q * A;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    ll k;

    cin >> n >> k;
    FOR (i, 1, n) {
    	FOR (j, 1, n) {
    		cin >> A.coef[i][j];
    	}
    }

    A = mu(A, k);
   	//A = A * A;

    ll res = 0;

    FOR (i, 1, n) {
    	FOR (j, 1, n) {
    		res = (res + A.coef[i][j]) % K;
    		//cout << A.coef[i][j] << " ";
    	}
    	//cout << endl;
    }	

	cout << res << endl;
    return 0;
}