#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;

typedef tree<II,null_type,less<II>,rb_tree_tag,tree_order_statistics_node_update> indTree;

ll a[200005],s[200005];

indTree S;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;ll T;
    cin>>n>>T;
    FOR (i,1,n){
    	ll t;
    	cin>>t;
    	s[i]=s[i-1]+t;
    }
    S.insert(II(0,0));
    ll res=0;
    FOR (i,1,n){
    	//for (auto j:S) cout<<j.first<<" "; cout<<endl;
    	//cout<<S.order_of_key(II(s[i]-T,i))<<" "<<T-s[i]<<endl;
    	res+=i-S.order_of_key(II(s[i]-T,i));
    	//cout<<res<<endl;
    	S.insert(II(s[i],i));
    }
    cout<<res<<endl;
	
         return 0;
}