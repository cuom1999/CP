#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tmp,k,t,res;
int d[2001];
ll l,r;

bool kt(int n){
    for(int i=1;i<=20;i++){
        while(n>0){
            tmp=n%10;n/=10;
            k+=tmp*tmp;
        }
        n=k;k=0;
        if(n==1) return true;
    }
    return false;
}
bool ok(ll n){
    k=0;
    while(n>0){
        tmp=n%10;n/=10;
        k+=tmp*tmp;
    }
    if(d[k]) return true;
    return false;
}

int main(){
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    for(int i=1;i<=2000;i++){
        if(kt(i)==1) d[i]=1;
    }
    cin>>t;
    while(t--){
        cin>>l>>r;res=0;
        for(ll i=l;i<=r;i++){
            if(ok(i)) res++;
        }
        cout<<r-l+1-res<<"\n";
    }
    return 0;
}
