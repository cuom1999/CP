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

int n,L;
ll S;
int p[100006][20];
vector<int> v[100005];
ll w[100005];
ll s[100005];
int h[100005];


void predfs(int a, int p){
	for (auto i:v[a]){
		h[i]=h[a]+1;
		s[i]=s[a]+w[i];
		predfs(i,a);
	}
}

void preProcess(){
	FOR (i,1,17){
		FOR (j,1,n){
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
}

int calc(int a){
	ll M=S;
	int k=0;
	int H=h[a];
	FORD(i,17,0){
		if ((1<<i)>L) continue;
		int u=p[a][i];
		//cout<<a<<" "<<i<<" "<<k<<" "<<M<<" "<<u<<" "<<s[a]-s[u]<<endl;
		if (s[a]-s[u]<=M){
			M-=(s[a]-s[u]);
			k+=(1<<i);
			a=u;
		}
	}
	k=min(k,H+1);
	return k;
}

int r[100005];

struct cmp{
	bool operator () (int a, int b){
		return h[a]<h[b];
	}
};

priority_queue<int, vector<int>, cmp> Q;
int dd[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cin>>n>>L>>S;
	FOR (i,1,n) {
		cin>>w[i];
		if (w[i]>S) {cout<<-1;return 0;}
	}
	FOR (i,2,n){
		int x;
		cin>>x;
		v[x].pb(i);
		p[i][0]=x;
	}   
	s[1]=w[1];
	predfs(1,0);
	preProcess();

	//cout<<calc(3)<<endl;
	//return 0;

	FOR (i,1,n){
		r[i]=calc(i);
		//cout<<i<<" "<<r[i]<<endl;
	}

	FOR (i,1,n){
		if (v[i].size()==0){
			Q.push(i);
		}	
	}
	int res=0;
	dd[0]=1;
	while (Q.size()){
		int t=Q.top();
		int tt=t;
		Q.pop();
		if (dd[t]) continue ; 
		res++;
		dd[t]=1;
		int e=r[t];
	 	e=min(e,L);
	 	//cout<<t<<" ";
	 	FOR (i,1,e-1){
	 		t=p[t][0];
	 		//cout<<t<<" ";
	 		dd[t]=1;
	 	}
	 	//cout<<endl;
	 	//cout<<tt<<" "<<t<<endl;
	 	t=p[t][0];
	 	if (!dd[t]) Q.push(t);
	}
	cout<<res<<endl;

         return 0;
}