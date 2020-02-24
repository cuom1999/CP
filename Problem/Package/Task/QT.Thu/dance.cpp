#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=7e4+1;

ll f[11][N],a[11][N],W;
int n,l,m;

void countt(){
    int res=0;
  for(int i=1;i<=n-l+1;i++){
        ll ans=0;
    for(int j=i;j<i+l;j++){
        for(int k=1;k<=m;k++){
           ans+=f[k][j-i+1]*a[k][j];
        if (ans>W)  break;
  }
   if (ans>W) {res++;break;}
    }
    }
    cout<<res;
}
int main(){
        freopen("dance.inp", "r", stdin);
        freopen("dance.out", "w", stdout);
           ios_base::sync_with_stdio(0);
             cin.tie(0);cout.tie(0);
        cin>>n>>l>>m>>W;
         for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
              cin>>a[i][j];
         for(int i=1;i<=m;i++)
            for(int j=1;j<=l;j++)
        cin>>f[i][j];
        countt();
}
