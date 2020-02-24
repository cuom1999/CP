#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;++i)
#define LL long long
using namespace std;
const int N = 1e5 +3;
int t;
LL L,R;
int vs[1500],ok[1500] ;
int Tinh(LL x)
{
    int kq = 0;
    while(x>0){
        kq += (x%10)*(x%10) ;
        x/=10;
    }
    return kq;
}
void INIT()
{
    ok[1] = 1;
    queue<int> Q;
    FOR(i,2,1460) Q.push(i) ;
    while(!Q.empty())
    {
        int gt = Q.front() ; Q.pop();
        vector<int> Can;
        Can.clear() ;
        int hi = 1;
        while(1){
             Can.push_back(gt) ;
             if(ok[gt]==1) break;
             vs[gt] ++;
             if(vs[gt]>=2) {hi = 2;break;}
             gt = Tinh(gt);
        }
        for(auto x:Can) {
            vs[x] = hi; ok[x] =hi;
        }
    }
   // FOR(i,1,110) cerr<<i<<" "<< ok[i] <<'\n';
}
int main()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("PEARL.inp","r",stdin);
    freopen("PEARL.out","w",stdout);
    INIT();
    //FOR(i,10,99) if(ok[Tinh(i)]==1) cout<< i<<'\n';
    cin >> t;
    FOR(__,1,t)
    {
        LL L,R ;
        cin >> L >> R ;
        int cnt = 0;
        for(LL i=L;i<=R;i++) if(ok[Tinh(i)] !=1 ) ++cnt;
        cout << cnt <<'\n';
    }
}
