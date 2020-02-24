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

int d[1005][10];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;

    FOR (i,1,7){
    	FOR (j,0,n) d[j][i]=INF;
    } 
    FOR (i,1,n){
    	int c;
    	cin>>c;
    	string s;
    	cin>>s;
    	int y=0;
    	for (char q:s){
    		if (q=='A') y|=1;
    		if (q=='B') y|=2;
    		if (q=='C') y|=4;
    	}
    	//cout<<i<<" "<<y<<" "<<c<<endl;
    	FOR (j,0,7) d[i][j]=d[i-1][j];
    	FOR (j,0,7){
    		d[i][j|y]=min(d[i][j|y],d[i-1][j]+c);
    	}
    	//FOR (j,0,7) cout<<d[i][j]<<" "; cout<<endl;
    }
    if (d[n][7]==INF) cout<<-1;
    else cout<<d[n][7]<<endl;
    
	
         return 0;
}