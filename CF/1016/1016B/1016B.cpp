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
string s,t;

int a[100004];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    cin>>s>>t;
    FOR (i,0,n-m){
    	string A;
    	FOR (j,i,i+m-1){ 
    		A+=s[j];
    	} 
    	if (A==t) a[i+1]=a[i]+1;
    	else a[i+1]=a[i];
    }
    FOR (z,1,q){ 
    	int l, r;
    	cin>>l>>r;
    	if (r-m+1<l) cout<<0<<endl;
    	else cout<<a[r-m+1]-a[l-1]<<endl;
    }

         return 0;
}