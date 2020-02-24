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
int A, B;
int res; 
int c[15], a[15];
int S, C;

bool solveS(int S){
	FOR (i, 0, (1 << (2 * n)) - 1){
		FOR (j, 1, 2 * n){
			c[j] = (bool) (i & (1 << (j-1)));
		}		
		bool q = 0;
		FOR (j, 1, S){
			if (c[j] != a[j]){
				q = 1; break;
			} 
		}
		if (q) continue;

		int res1;
		int A1 = 0, B1 = 0;
		FOR (i, 1, n){
			A1 += c[i * 2 - 1];
			B1 += c[i * 2];
		}
		if (A1 > B1){
			res1 = 1;
		}
		else if (A1 == B1) res1 = 0;
		else res1 = -1;

		if (res == res1) continue;
		else return 0;		
	}
	return 1; 
}

bool solveC(int C){
	int cnt = 0;
	FOR (i, 0, (1 << S) - 1){
		FOR (j, 1, S){
			c[j] = (bool) (i & (1 << (j-1)));
		}		
		bool q = 0;
		FOR (j, 1, C){
			if (c[j] != a[j]){
				q = 1; break;
			} 
		}
		if (q) continue;
		int A1 = 0, B1 = 0;
		FOR (j, 1, S){
			if (j % 2 == 1) A1 += c[j];
			else B1 += c[j];
		} 
		//cout << A1 << " " << B1 << endl;
		if (A1 == A && B1 == B){
			cnt++;
		}
	}
	//cout << C << " " << cnt << endl; 
	if (cnt == 1) return 1;
	else return 0;
}

int main()
{IN;//OUT; 
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t){
    	A = B = C = S = 0;
		cin >> n;
		FOR(i, 1, 2*n){
			char c; 
			cin >> c;
			if (c == 'E'){
				a[i] = 1;
			}
			else a[i] = 0;
		}

		FOR (i, 1, n){
			A += a[i * 2 - 1];
			B += a[i * 2];
		}

		if (A > B){
			res = 1;
		}
		else if (A == B) res = 0;
		else res = -1;

		FOR (i, 1, 2*n){
			if (solveS(i)) {
				S = i;
				break;
			}
		}

		A = B = 0;

		FOR (i, 1, S) {
			if (i % 2 == 1) A += a[i];
			else B += a[i];
		}

		FOR (i, 0, S){
			if (solveC(i)){
				C = i; break;
			}
		}
		cout << S << " " << C << endl;
	}



         return 0;
}