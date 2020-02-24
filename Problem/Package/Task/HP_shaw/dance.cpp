#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(int _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
typedef pair<int,int> ii;
#define x first
#define y second
const int
    maxn        =   70000,
    maxl        =   30000,
    maxm        =   10;
int
    n,l,m,W,A[maxm+2][maxn+2],B[maxm+2][maxl+2],res;
void input(){
    cin >> n >> l >> m >> W;
    finc(i,1,m)
        finc(j,1,n) cin >> A[i][j];
    finc(i,1,m)
        finc(j,1,l) cin >> B[i][j];
}
void solve(){
    finc(pos,1,n-l+1){
        int sum=0;
        finc(i,1,m){
            finc(j,1,l) sum+=A[i][pos+j-1]*B[i][j];
            if (sum>W) break;
        }
        if (sum>W) ++res;
    }
    cout << res;
}
int main(){
    fast_io;
    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    input();
    solve();
    return 0;
}






