#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;++i)
#define LL long long
using namespace std;
const int N = 2000 +3;
int n;
char a[N][N] ;
vector<int> G[N] ;
int dd[N] ;
int main()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("RPS.inp","r",stdin);
    freopen("RPS.out","w",stdout);
    cin >> n ;
    FOR(i,1,n) FOR(j,1,n) cin >> a[i][j] ;

    FOR(i,1,n) FOR(j,1,n){
        if(a[i][j]=='1'&& a[j][i]=='0') G[i].push_back(j) ;
    }
    FOR(i,1,n)
    {
        for( int u:G[i] )
        for( int v:G[u] )
        if(a[v][i]=='1' && a[i][v]=='0'){
            dd[i] = 1;dd[u] = 1;dd[v] = 1 ;
        }
    }
    int kq = 0;
    FOR(i,1,n) if(dd[i]==1) kq ++;
    cout << kq ;
}
