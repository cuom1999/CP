#include <bits/stdc++.h>
using namespace std;
#define maxn 2010
int n,res=0;
char a[maxn][maxn];
int d[maxn][maxn],f[maxn][maxn];
vector<int>g[maxn];

void sub1(){
    for(int i=1;i<=n;i++){
        for(int j:g[i])if(j!=i){
            for(int k:g[j])if(k!=i){
                if(a[k][i]=='1') d[i][j]=d[j][k]=d[k][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(d[i][j] && d[j][k] && d[k][i]){
                    if(!f[i][j]) res++,f[i][j]=1;
                    if(!f[j][k]) res++,f[j][k]=1;
                    if(!f[k][i]) res++,f[k][i]=1;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("RPS.INP","r",stdin);
    freopen("RPS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]=='1') g[i].push_back(j);
        }
    }
    sub1();
    cout<<res;
    return 0;
}
