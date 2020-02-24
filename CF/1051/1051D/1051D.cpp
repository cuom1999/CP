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

ll d[1005][2][2][2005],vs[1005][2][2][2005];
ll K=998244353;
int calc(int n, int a1, int a2, int c){
	if (n==0 || c<=0){
		return 0;
	}
	if (n==1){
		if (a1==a2) {
			if (c==1) return 1;
		}
		else {
			if (c==2) return 1;
		} 
		return 0;
 	}
	if (vs[n][a1][a2][c]) return d[n][a1][a2][c];
	vs[n][a1][a2][c]=1;
	if (a1==a2){
		FOR (i,0,1){
			FOR (j,0,1){
				if (i==j && i!=a1){
					d[n][a1][a2][c]+=calc(n-1,i,j,c-1);
					d[n][a1][a2][c]%=K;
				}
				else{
					d[n][a1][a2][c]+=calc(n-1,i,j,c);d[n][a1][a2][c]%=K;
				}
			}
		}
	}
	else{
		FOR (i,0,1){
			FOR (j,0,1){
				if (i==a2 && j==a1){
					d[n][a1][a2][c]+=calc(n-1,i,j,c-2);d[n][a1][a2][c]%=K;
				}
				else if (i==a1 && j==a2){
					d[n][a1][a2][c]+=calc(n-1,i,j,c);d[n][a1][a2][c]%=K;	
				}
				else{
					d[n][a1][a2][c]+=calc(n-1,i,j,c-1);d[n][a1][a2][c]%=K;
				}
			}
		}
	}
	//cout<<n<<" "<<a1<<" "<<a2<<" "<<c<<" "<<d[n][a1][a2][c]<<endl;
	return d[n][a1][a2][c];
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,c;
    cin>>n>>c;
    ll res=0;
    FOR (i,0,1){
    	FOR (j,0,1){
    		res=(res+calc(n,i,j,c))%K;
    	}
    }
    cout<<res<<endl;
    
	
         return 0;
}