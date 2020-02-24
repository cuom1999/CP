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

int a[305][305];
int cnt[605];
int C[605];
int B[605];

inline int abs(int x){
	if (x<0) return -x;
	return x;
}

inline int dist(int x, int y, int u, int v){
	return abs(x-u)+abs(y-v);
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
		int n,m;
		cin>>n>>m;
		FOR (i,1,n){
			FOR (j,1,m){
				char c;
				cin>>c;
				if (c=='0'){
					a[i][j]=0;
				}
				else a[i][j]=1;
			}
		}
		FOR (i,1,n+m-2) cnt[i]=B[i]=C[i]=0;


		FOR (i,1,n){
			FOR (j,1,m){
				FOR (k,j+1,m){
					if (a[i][j]==1 && a[i][k]==1){
						cnt[k-j]++;
					}
				}
			}
			FOR (j,1,n+m-2) B[j]=C[j]=0;

			FOR (j,1,i-1){
				FOR (k,1,m){
					if (a[j][k]) C[dist(j,k,i,1)]++;
				}
			}
			if (a[i][1]){
				FOR (j,1,n+m-2){
					cnt[j]+=C[j];
				}
			}
			/*if (i==3){
				FOR (i,1,n+m-2) cout<<B[i]<<" "; cout<<" B"<<endl;
				FOR (i,1,n+m-2) cout<<C[i]<<" "; cout<<" C"<<endl;
			}*/

			FOR (j,2,m){
				FOR (k,1,i-1){
					C[dist(k,j-1,i,1)]-=a[k][j-1];
					B[dist(k,j-1,i,m)]+=a[k][j-1];
				}
				/*if (i==3){
					cout<<j<<endl;
					FOR (i,1,n+m-2) cout<<B[i]<<" "; cout<<" B"<<endl;
					FOR (i,1,n+m-2) cout<<C[i]<<" "; cout<<" C"<<endl;
				}*/
				if (a[i][j]){
					FOR (k,1,n+m-2-j+1){
						cnt[k]+=C[k+j-1];
					}
					FOR (k,1,n+m-2-(m-j)){
						cnt[k]+=B[k+(m-j)];
					}
				}
			}
		}
		FOR (i,1,n+m-2) cout<<cnt[i]<<" "; cout<<endl;
	}

	
         return 0;
}