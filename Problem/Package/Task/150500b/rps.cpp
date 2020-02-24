#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("rps.inp","r",stdin)
#define OUT freopen("rps.out","w",stdout)
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

bitset<2001> bs[2005];
// string s;
char s[2001];
vector<int> v[2005];

int main()
{
IN;
OUT;
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);

    int n;
    // cin>>n;
    scanf("%d", &n);
    FOR (i,1,n){
    	// cin>>s;
        scanf("%s", s);
    	FOR (j,0,n-1){
    		if (s[j]=='1') {
    			bs[i][j+1]=1;
    			v[i].pb(j+1);
    		}
    	}
    }
    int res=0;
    FOR (i,1,n){
    	bitset<2001> B,C;
    	for (auto j:v[i]) B|=bs[j]; 

    	C=bs[i];
    	C.flip();
    	C&=B;
    	if (C.count()) res++; //thoa man
    }
    // cout<<res<<endl;
    printf("%d", res);

	    
    return 0;
    
}