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
    maxn    =   2000;
int
    n,res;
#define bs bitset<2000>
bs
    D1[maxn],D2[maxn];
vector<int>
    G[maxn];
void input(){
    cin >> n;
    rep(i,n) rep(j,n){
        char c; cin >> c; if (j==i) continue;
        if (c=='0') D1[i][j]=1; else G[i].pb(j),D2[i][j]=1;
    }
}
void solve(){
    rep(u,n)
        for(auto &v:G[u]) if ((D2[v]&D1[u]).any()){
            ++res;
            break;
        }
    cout << res;
}
int main(){
    fast_io;
    freopen("rps.inp","r",stdin);
    freopen("rps.out","w",stdout);
    input();
    solve();
    return 0;
}






