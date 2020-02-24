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

int n,k;

vector<int> v[1000005];

int h[1000005];
int d[1000005], m[1000005];

void pre(int a, int p){
	h[a]=h[p]+1;
	for (auto i:v[a]){
		if (i!=p)
		pre(i,a);
	}
}

void dfs(int a, int p){
	for (auto i:v[a]){
		if (i==p) continue;
		dfs(i,a);
		d[a]+=d[i];
	}
	if (v[a].size()==1){
		d[a]=0;
		m[a]=h[a];
		return ;
	}
	multiset<int> S;
	for (auto i:v[a]){
		if (i==p) continue;
		S.insert(m[i]);
	}
	while (S.size()>1){
		auto it=S.begin();
		auto it2=++it;
		it--;
		if ((*it)+(*it2)<=k+2*h[a]){
			S.erase(it);
		}
		else break;
	}
	m[a]=*S.begin();
	d[a]+=S.size();
	d[a]--;
	//cout<<a<<" "<<d[a]<<" "<<m[a]<<endl;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR (i,1,n-1){
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    int root=0;
    FOR (i,1,n){
    	if (v[i].size()>1) {root=i; break;}
    }
    pre(root,0);
    dfs(root,0);
    cout<<d[root]+1<<endl;

    
	
         return 0;
}