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


int h[1005];
vector<int> v[1005];
vector<II> res;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){
    	int x,y;
    	cin>>x>>y;
    	if (x==y) {
    		cout<<"NO"; return 0;
    	}
    	if (x>y) swap(x,y);
    	if (y!=n){
    		cout<<"NO"; return 0;
    	}
    	h[x]++;
    }
    FORD (i,n-1,1){
    	if (h[i]) continue;
    	int t=0;
    	FORD (j,n,1){
    		if (h[j]>1){
    			h[j]--;
    			t=j; break;
    		}
    	}
    	if (t<=i){
    		cout<<"NO"; return 0;
    	}
    	else{
    		v[t].pb(i);
    	}
    }

    cout<<"YES"<<endl;
    FOR (i,1,n-1){
    	if (!h[i]) continue;
    	v[i].pb(i);
    	cout<<n<<" "<<v[i][0]<<endl;
    	for (int j=0; j+1<v[i].size(); j++){
    		cout<<v[i][j]<<" "<<v[i][j+1]<<endl;
    	}
    }
	

	
         return 0;
}