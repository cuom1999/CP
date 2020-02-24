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

vector<int> v[1005];
int d[1005], f[1005];
int h[1005];
vector<int> V1,V2;
void dfs(int a, int p){
	h[a]=h[p]+1;
	for (auto i:v[a]){
		if (i==p) continue;
		dfs(i,a);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
	int t;
	cin>>t;
	FOR (z,1,t){
		int n;
		cin>>n;
		FOR (i,1,n-1){
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		int k1,k2;
		cin>>k1;
		FOR (i,1,k1){
			int x;
			cin>>x;
			V1.pb(x);
			f[x]=1;
		}
		cin>>k2;
		FOR (i,1,k2){
			int x;
			cin>>x;
			V2.pb(x);
			d[x]=1;
		}
		int u = V2[0];
		cout<<"B "<<u<<endl;
		cout.flush();
		int ans;
		cin>>ans;
		if (ans==-1) exit(0);
		if (f[ans]==1){
			cout<<"C "<<ans<<endl;
			cout.flush();
		}
		else{
			dfs(ans,0);
			int ma=INF;
			int ind=0; 
			for (auto i:V1){
				if (h[i]<ma){
					ind=i;
					ma=h[i];
				}
			}
			cout<<"A "<<ind<<endl;
			cout.flush();
			cin>>ans;
			if (ans==-1) exit(0);
			if (d[ans] == 1){
				cout<<"C "<<ind<<endl;
				cout.flush();
			}
			else{
				cout<<"C -1"<<endl;
				cout.flush();
			}	
		}	
		FOR (i,1,n){
			d[i]=f[i]=h[i]=0;
			v[i].clear();
		}
		V1.clear();
		V2.clear();
	}    
	
         return 0;
}