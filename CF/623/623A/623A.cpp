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

int e[505][505];

int color[505];
int vs[505];
int n;
void dfs(int a, int c){
	if (vs[a]) return ;
	vs[a]=1;
	color[a]=c;
	FOR (i,1,n) {
		if (e[a][i]) dfs(i,c^1);
	}
}

vector<int> A,C;
char s[505];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    FOR (i,1,n) color[i]=2;
    FOR (i,1,n){
    	s[i]='b';
    	FOR (j,i+1,n){
    		e[i][j]=e[j][i]=1;
    	}
    }
    int E=n*(n-1)/2;
    FOR (z,1,m){
    	int x,y;
    	cin>>x>>y;
    	e[x][y]=e[y][x]=0;
    	E--;
    }
    bool q=0;
    FOR (i,1,n){
    	FOR (j,1,n){
    		if (e[i][j]) {
    			dfs(i,0); q=1;
    			break;
    		}
    	}
    	if (q) break;
    }
    FOR (i,1,n){
    	if (color[i]==0) A.pb(i);
    	if (color[i]==1) C.pb(i);
    }

    if (E!=A.size()*C.size()) {
    	cout<<"No";
    	return 0;
    }
    for (auto i:A){
    	for (auto j:C){
    		if (e[i][j]==0){
    			cout<<"No"; return 0;
    		}
    	}
    }
    for (auto i:A) s[i]='a';
    for (auto i:C) s[i]='c';

    cout<<"Yes"<<endl;
    FOR (i,1,n) cout<<s[i];

    
	
         return 0;
}