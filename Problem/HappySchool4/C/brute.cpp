#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1<<(i))))
#define setbit1(n,i) ((n)|(1<<(i)))
#define togglebit(n,i) ((n)^(1<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD (1000000007)
#define asz 500005
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define pf push_front
ll fre[1000005];
ll a[1000005];
int main(){
    fastread;
    ll n,i,j,k,l,m;
    string s;
    cin>>s;
    cin >> m;
    n = s.size();
    ll gun=1;
    if(m==2||m==5){
        ll ans=0;
        for(i=0;i<n;i++){
            if((s[i]-'0')%m==0)
                ans+=(i+1);
        }
        cout<<ans<<endl;
        return 0;
    }
    for(i=1;i<=n;i++){
        ///if(i!=0)
        a[i]=(a[i-1]+((s[n-i]-'0')*gun)%m)%m;
        gun=(gun*10LL)%m;
        fre[a[i]]++;
    }
    ll sum=0;
    fre[0]++;
    for(i=0;i<m;i++){
        //if(i==0)
          ///  sum=(sum+fre[i]+((fre[i])*(fre[i]-1))/2);
       /// else
            sum+=(((fre[i])*(fre[i]-1))/2) ;
    }
    cout<<sum<<endl;
}