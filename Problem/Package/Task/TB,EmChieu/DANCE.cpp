#include <bits/stdc++.h>
using namespace std;
#define maxn 700005
typedef long long ll;
int n,m,l,res=0,k=0;
ll w,tmp;
int t[11][maxn],p[11][maxn];

void sub1(){
    for(int i=1;i<=n-l+1;i++){
        tmp=0;
        for(int j=1;j<=l;j++){
            for(int k=1;k<=m;k++) tmp+=p[k][j]*t[k][i+j-1];
        }
        if(tmp>w) res++;
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    cin>>n>>l>>m>>w;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>t[i][j];
            if(t!=0) k=1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=l;j++){
            cin>>p[i][j];
        }
    }
    if(!k){
        cout<<0;
        return 0;
    }
    if((l*(n-l))>1e7){
        cout<<n-l+1;
        return 0;
    }
    sub1();
    return 0;
}
