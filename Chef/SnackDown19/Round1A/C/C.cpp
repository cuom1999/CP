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

int cnt[55];
int a[55];
int n;
vector<int> v[55];
int vs[55];

void dfs(int a){
	if (vs[a]) return;
	vs[a]=1;
	for (auto i:v[a]){
		dfs(i);
	}
}

bool check(){
	FOR (i,1,n){
		FOR (j,i+1,n){
			if(__gcd(a[i],a[j])==1){
				v[i].pb(j);
				v[j].pb(i);
			}
		}
	}
	dfs(1);
	FOR(i,1,n){
		if (!vs[i]) return 0;
	}
	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
    	cin>>n;
    	FOR (i,1,50) cnt[i]=0;
    	FOR (i,1,50){
    		vs[i]=0;
    		v[i].clear();
    	}
    	FOR (i,1,n){
    		cin>>a[i];
    		cnt[a[i]]++;
    	}
    	if (check()){
    		cout<<"0"<<endl;
    		FOR (i,1,n) cout<<a[i]<<" "; cout<<endl;
    	}
    	else{
    		if (cnt[47]==n){
    			a[1]=2;
    			cout<<1<<endl;
    			FOR (i,1,n) cout<<a[i]<<" "; cout<<endl;
    		}
    		else{
    			a[1]=47;
    			cout<<1<<endl;
    			FOR (i,1,n) cout<<a[i]<<" "; cout<<endl;
    		}
    	}

    }
    
	
         return 0;
}