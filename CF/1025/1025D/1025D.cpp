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
int a[706];
int can[706][706];
bitset<706> d[706][706];//,dd[706][706],is[706][706];
bool l[706][706], r[706][706];
/*
bool calc (int l, int r, int x){ 
    if (l==r) return 1;
    if (is[l][r][x]) return dd[l][r][x];
    is[l][r][x]=1;
    bool A=0;
    if (x-1>=l) {
        FOR (k,l,x-1){ 
            if (can[x][k]) A|=calc(l,x-1,k);
        }
    }
    else A=1;
    bool B=0;
    if (x+1<=r){ 
        FOR (k,x+1,r) { 
            if (can[x][k]) B|=calc(x+1,r,k);
        }
    }
    else B=1;
    bool C=(A&B);
    //cout<<l<<" "<<r<<" "<<x<<" "<<C<<endl;
    return dd[l][r][x]=(A&B);
}
*/
int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR (i,1,n){ 
        cin>>a[i];
    }
    FOR (i,1,n){ 
        FOR (j,i+1,n){ 
            if (__gcd(a[i],a[j])>1) can[i][j]=can[j][i]=1;
        }
    }
    bool res=0;
    
    FOR (i,1,n) {d[i][i][i]=1; if (can[i][i+1]) {l[i+1][i]=1; r[i][i+1]=1;} }
    FOR (len,1,n-1){ 
        FOR (i,1,n-len){ 
            int j=i+len;
            FOR (x,i,j){ 
                if (x==i){ 
                    d[i][j][x]=r[x][j];
                }
                else if (x==j){ 
                    d[i][j][x]=l[x][i];
                }
                else{ 

                    d[i][j][x]=l[x][i]&r[x][j];
                    /*if (i==1 && j==3 && x==2){ 
                        cout<<l[x][i]<<" "<<r[x][j]<<" "<<d[i][j][x]<<endl;
                    }*/
                }
                if (can[j+1][x]) l[j+1][i]|=d[i][j][x];
                if (can[i-1][x]) r[i-1][j]|=d[i][j][x];
            }
        }
    }
    //cout<<l[2][1]<<" "<<r[2][3]<<endl;
    //cout<<d[1][3][2]<<endl;

    FOR (i,1,n){ 
        res|=d[1][n][i];
    }
    /*FOR (i,1,n){ 
        FOR (j,i,n){ 
            FOR (k,i,j){ 
                if (d[i][j][k]!=calc(i,j,k)) {
                    cout<<i<<" "<<j<<" "<<k<<" "<<d[i][j][k]<<endl;
                }
            }
        }
    }*/

    //cout<<res<<endl;
    if (res==1) cout<<"Yes";else cout<<"No";

         return 0;
}