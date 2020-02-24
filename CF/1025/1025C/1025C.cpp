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
string s;
int d[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int n=s.length();
    int res=0;
    FOR (z,1,10){
	    FOR (i,0,n-1){ 
	    	if (s[i]!=s[(i+n-1)%n]) d[i]=d[(i+n-1)%n]+1;
	    	else d[i]=1;
	    	res=max(res,d[i]);
	    }
	}
	cout<<min(res,n)<<endl;




         return 0;
}