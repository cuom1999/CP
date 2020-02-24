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

int a[15][100005];
int pos[100005][15];
int dd[100005];
ll res;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    FOR (i,1,m){
        FOR (j,1,n) {
            cin>>a[i][j];
            pos[a[i][j]][i]=j;
        }
    }
    int C=1;
    int cnt=0;
    while (C<=n){
        dd[a[1][C]]=1;
        int u=a[1][C];
        FOR (j,C,n){
            bool q=1;
            FOR (k,2,m){
                if (pos[u][k]+j-C>n || a[k][pos[u][k]+j-C]!=a[1][j]){
                    //cout<<j<<" "<<C<<" "<<u<<" "<<pos[u][k]+j-C<<" "<<a[k][pos[u][k]+j-C]<<endl;
                    res+=(j-C+1)*1ll*(j-C)/2; C=j;
                    //cout<<res<<endl;
                    q=0;
                    break;
                }
            }
            if (!q) break;
            if (j==n){
                res+=(n-C+2)*1ll*(n-C+1)/2; C=n+1;
            }
        }
    }

    cout<<res<<endl;
    
    
         return 0;
}