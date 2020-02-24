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

ll a[100005], b[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
	    int n;
	    cin>>n;
	    FOR (i,1,n){
	    	cin>>a[i];
	    }
	    FOR (i,1,n){
	    	cin>>b[i];
	    }
	    int cur=1;
	    while (cur<=n-2){
	    	if (a[cur]>b[cur]){
	    		break;
	    	}
	    	if (a[cur]==b[cur]){
	    		cur++; continue;
	    	}

	    	a[cur+1]+=2*(b[cur]-a[cur]);
	    	a[cur+2]+=3*(b[cur]-a[cur]);
	    	a[cur]=b[cur];
	    	cur++;
	    }
	    bool q=1;
	    FOR (i,1,n){
	    	if (a[i]!=b[i]) q=0;
	    }
	    if (q){
	    	cout<<"TAK"<<endl;
	    }
	    else{
	    	cout<<"NIE"<<endl;
	    }
	}
	    
		
         return 0;
}