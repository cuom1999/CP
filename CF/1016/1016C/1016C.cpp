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

ll a[4][300005];
int n;
ll calc (int r, int c, int t, int st){ 
	ll A=0;

	if (c==1) st|=2;
	
	if (c==n) st|=4;
	//cout<<r<<" "<<c<<" "<<t<<" "<<st<<" "<<n<<endl;
	if ((st&1)==0){
		A=max(A,calc(r^1,c,t+1,st^1)+t*1ll*a[r][c]);
	}
	if ((st&2)==0){ 
		A=max(A,calc(r,c-1,t+1,st|4)+t*1ll*a[r][c]);
	}
	if ((st&4)==0) { 
		A=max(A,calc(r,c+1,t+1,st|2)+t*1ll*a[r][c]);
	}
	cout<<r<<" "<<c<<" "<<t<<" "<<st<<" "<<A<<endl;
	return A;
}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR (i,1,n) cin>>a[0][i];
    FOR (i,1,n) cin>>a[1][i];
    cout<<n<<endl;
    cout<<calc(0,1,0,0)<<endl;



         return 0;
}