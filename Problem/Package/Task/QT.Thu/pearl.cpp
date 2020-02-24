#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=4e5;

int f[N],T;

bool trau(ll x){
    int i=0;
  while(x!=1){
      ll ans=0,z=x;
    while(x!=0){
    ans+=(x%10)*(x%10);
    x/=10;
    }
    x=ans;
    i++; if (x==58) break;
  }
  return x==1;
}
int main(){
    freopen("pearl.inp", "r", stdin);
    freopen("pearl.out", "w", stdout);
       ios_base::sync_with_stdio(0);
         cin.tie(0);cout.tie(0);
        for(int i=1;i<=N;i++)
        if (trau(i)) f[i]=f[i-1]+1;
     else f[i]=f[i-1];

     cin>>T;
      while(T-->0){
        ll x,y,res=0;
        cin>>x>>y;
        if (y<=N) cout<<f[y]-f[x-1]<<"\n";
        else {
            if (x<=N && y<N) {res=f[N]-f[x-1];x=N+1;}
        for(x;x<=y;x++)
          if (trau(x)) {

                res++;
          }
          cout<<res<<"\n";
        }
      }

}
