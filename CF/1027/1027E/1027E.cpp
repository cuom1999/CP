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

const ll K=998244353;

const ll N=505;

ll d[N][N],g[N][N];
ll S[N][N];
ll T[N], T1[N];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,kk;
    cin>>n>>kk;
    d[1][1]=1;
    S[1][1]=1;
    FOR (i,2,n){ 
    	FOR (m,1,i-1){ 
    		FOR (k,1,m) g[m][k]=d[m][k];
    	}
    	FOR (m,1,i){ 
    		FOR (k,1,m){ 
    			if (k==1){ 
    				d[m][k]=S[m][i-1];
    			}
    			else{ 
    				if (m==k){ 
    					d[m][k]=(g[m-1][k-1]+g[m][k-1])%K;
    				}
    				else{ 
    					d[m][k]=g[m][k-1];
    				}
    			}
    			S[m][i]=(S[m][i]+d[m][k])%K;
    		}
    	}		
    }
    FOR (m,1,n){ 
    	FOR (k,1,m) T[m]=(T[m]+d[m][k])%K;
    	//cout<<m<<" "<<T[m]<<endl;
    }

    FOR (i,1,n){ 
    	T1[i]=(T1[i-1]+T[i])%K;
    }
    ll res=0;
    FOR (i,1,min(kk-1,n)){ 
    	res=(res+2*T[i]*T1[min((kk-1)/i,n)]%K)%K;
    }
    cout<<res<<endl;


         return 0;
}