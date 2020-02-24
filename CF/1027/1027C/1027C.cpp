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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int a[10005];
int x[1000005];
vector<int> v;
int dd[10005];

ld calc(ld a, ld b){ 
	return (a/b +b/a);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin>>T;
    FOR (z,1,T){
    	v.clear();
	    int n;
	    cin>>n;
	    FOR (i,1,n){ 
	    	cin>>x[i];
	    	a[x[i]]++;
	    }
	    
	    bool q=0;
	    FOR (i,1,n) { 
	    	if (!dd[x[i]]) a[x[i]]/=2;
	    	else continue;
	    	dd[x[i]]=1;
	    	if (a[x[i]]>=2){ 
	    		FOR (g,1,4) cout<<x[i]<<" ";
	    		cout<<endl;
	    		q=1;
	    		break;
	    	}
	    	else if (a[x[i]]) v.pb(x[i]);
	    }
	    FOR (i,1,n) {dd[x[i]]=0;a[x[i]]=0;}
	    if (q) {continue;}
	    sort(all(v));
	    ld S=1e18;
	    II res=II(0,0);
	    for (int i=0; i<v.size(); i++){ 
	    	int j=i-1;
	    	if (j>=0){ 
	    		if (S>calc(v[i],v[j])){ 
	    			S=calc(v[i],v[j]);
	    			res=II(v[i],v[j]);
	    		}
	    	}
	    	j=i+1;
	    	if (j<v.size()){ 
	    		if (S>calc(v[i],v[j])){ 
	    			S=calc(v[i],v[j]);
	    			res=II(v[i],v[j]);
	    		}
	    	}
	    }
	    cout<<res.first<<" "<<res.first<<" "<<res.second<<" "<<res.second<<endl;
	}


         return 0;
}