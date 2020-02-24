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

struct data{
	int x1, x2, y;
	bool operator< (data a){
		return y<a.y;
	}
};
vector<data> V;
vector<II> D;
int y[100005];
int m,n;

int solve(vector<II> &D){
	sort(all(D));
	D.pb(II(1000000002,1000000002));
	if(D[0].first>1) return 0;
	int en = D[0].second;
	for (int i=1; i<D.size(); i++){
		if (D[i].first>D[i-1].second+1){
			break;	
		}
		else{
			en=D[i].second;
		}
	}
	int u=upper_bound(y+1,y+n+1,en)-(y+1);
	return u;
}
int d[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cin>>n>>m;
	FOR (i,1,n){
		cin>>y[i];
	}
	n++;
	y[n]=INF;    
	sort(y+1,y+n+1);
	FOR (i,1,m){
		data u;
		cin>>u.x1>>u.x2>>u.y;
		V.pb(u);
	}
	sort(all(V));
	int C=0;
	for (int i=0; i<V.size(); i++){
		if (i && V[i].y!=V[i-1].y){
			//cout<<V[i-1].y<<" "<<solve(D)<<endl;
			//d[++C]=solve(D);
			d[solve(D)]++;
			D.clear();
			D.pb(II(V[i].x1,V[i].x2));
		}
		else{
			D.pb(II(V[i].x1,V[i].x2));
		}
	}
	//cout<<V.back().y<<" "<<solve(D)<<endl;
	if (V.size()) d[solve(D)]++;
	int res=INF;
	int S=0;
	FOR (i,0,n)S+=d[i];
	FOR (i,0,n-1){
		S-=d[i];
		res=min(res,i+S);
	}
	cout<<res<<endl;

         return 0;
}