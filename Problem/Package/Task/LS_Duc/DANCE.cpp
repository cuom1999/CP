#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
typedef long long ll;
#define NMAX 70005
ll a[11][NMAX];
ll b[11][NMAX];
ll n,l,m,W;
int main(){
    freopen("DANCE.inp","r",stdin);
    freopen("DANCE.out","w",stdout);
    read(n);read(l);read(m);read(W);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) read(a[i][j]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=l;j++){
            read(b[i][j]);
        }
    }
    int res=0;
    for(int x=1;x<=n-l+1;x++){
        ll ans=0;
        bool flag=0;
        for(int i=1;i<=m;i++){
            for(int j=x;j<=x+l-1;j++){
                ans=ans+a[i][j]*b[i][j-x+1];
                if(ans>W){
                    res++;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    writeln(res);
}
