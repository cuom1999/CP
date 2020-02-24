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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll K=1e9+7;

ll d[100005];
ll a[100005];
vector<int> v;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    d[0]=1;

    FOR (i,1,50000){
    	d[2*i]=d[2*i-2]*(ll)(2*i-1)%K;
    }
    int t;
    cin>>t;
    FOR (z,1,t){

	    int n;
	    cin>>n;
	    FOR (i,1,n){
	    	int x;
	    	cin>>x;
	    	v.pb(x);
	    }
	    sort(all(v));
	    int C=0;
	    for (int i=0; i<v.size(); i++){
	    	if (i==0 || v[i]>v[i-1]){
	    		a[++C]++;
	    	}
	    	else{
	    		a[C]++;
	    	}
	    }
	    ll res=1;
	    FORD (i,C,1){
	    	if (a[i]==0){
	    		continue;
	    	}
	    	if (a[i]%2==0){
	    		res=res*d[a[i]]%K;
	    	}
	    	else{
	    		res=res*a[i]%K;
	    		a[i]--;
	    		res=res*d[a[i]]%K;
	    		res=res*a[i-1]%K;
	    		a[i-1]--;
	    	}
	    }
	    FOR (i,1,C) a[i]=0;
	    v.clear();
	    cout<<res<<endl;
	}		
         return 0;
}