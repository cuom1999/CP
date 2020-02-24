#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
//set<int> v;
void pt2(ll n, ll c[]){
   ll u=0;
   FOR (i,0,30) c[i]=0;
   while (n){
        c[u]=n%2;
        n/=2;
        u++;
   }
}
vector<int> v,v1;
ll c[100],dd[35000005];
ll sum;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(NULL);
    ll a,b,k,r,res=0;
    while (1){
        cin>>a>>b>>k;
        if (a==0) break;
        res=0;
        FOR (i,1,1LL<<25) dd[i]=0;
        //cout<<1<<endl;
        FOR (t,1,1LL<<(a+b+1)-1){
            if (dd[t]==0){
                pt2(t,c);
                v.clear();
                r=0;
                FOR (i,0,60){
                    if (c[i]==1) {r++;v.pb(i);}
                }
                if (r!=a) {continue;}
                r=0;
                for (int i=0; i+1<v.size();i++){
                    if (v[i+1]-v[i]==1) r++;
                }
                if (v[v.size()-1]==a+b-1 && v[0]==0) r++;
                if (r==a-k) {res++;}//for(auto i: v) cout<<i<<" ";cout<<endl;}
                FOR (j,0,a+b-1){
                    v1.clear();
                    sum=0;
                    for (auto i: v) v1.pb((i+j)%(a+b));
                    for (auto i: v1){
                        sum+=1LL<<i;
                        dd[sum]=1;
                    }
                }
            }
        }
        //cout<<res/(a+b)<<endl;
        cout<<res<<endl;
    }

         return 0;
}
