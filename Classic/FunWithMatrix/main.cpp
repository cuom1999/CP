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

struct Matrix {

    vector< vector<long double> > coef;
    int numRows = 0, numCols = 0;

    Matrix (int m = 0, int n = 0) {
        coef.resize(m);
        for (int i = 0; i < m; i++) {
            coef[i].resize(n);
        }
        
        numRows = m;
        numCols = n;

    }

    Matrix ref() {

        Matrix res(numRows, numCols);

        vector<int> pivotRow(min(numRows, numCols));

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                res.coef[i][j] = coef[i][j];
            }

            for (int j = 0; j < numCols; j++) {

                if (res.coef[i][j]) {

                    if (pivotRow[j]) {
                        long double mul = res.coef[pivotRow[j]][j] / res.coef[i][j];
                        for (int k = 0; k < numCols; k++) {

                            res.coef[i][j] = res.coef[i][j] - res.coef[pivotRow[j]][j] * mul;

                        }
                    }
                    else {
                        pivotRow[j] = i;
                        
                        break;
                    }
                }
            }
        }

        return res;

    }

    void luFactor(Matrix &L, Matrix &U) {

    }

    friend operator
};

Matrix A(2, 2);

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    FOR (i, 0, 1) {
        FOR (j, 0, 1) {
            cin >> A.coef[i][j];
        }
    }


    
    return 0;
}