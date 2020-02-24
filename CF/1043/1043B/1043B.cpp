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

int n;
int a[100005];
int b[1005];

bool solve(int k){
	FOR (i,0,k-1){
		b[i]=a[i+1]-a[i];
	}
	FOR (i,k,n-1){
		if ((a[i+1]-a[i])!=b[i%k]) return 0;
	}
	return 1;
}
vector<int> res;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR (i,1,n) cin>>a[i];
    FOR (i,1,n) {
    	if (solve(i)) res.pb(i);
    }
    cout<<res.size()<<endl;
    for (auto i:res) cout<<i<<" ";
    	
	
        return 0;
    
}