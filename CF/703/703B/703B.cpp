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

ll c[100005],d[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    FOR (i,1,n){ 
    	cin>>c[i];
    }
    FOR (i,1,k){ 
    	int a;
    	cin>>a;
    	d[a]=1;
    }
    ll S=0,S1=0, S2=0;
    FOR (i,1,n){ 
    	if (d[i]){ 
    		S+=c[i];
    		S2+=sq(c[i]);
    	}
    	else{ 
    		S1+=c[i];
    	}
    }
    ll res=(S*S-S2)/2;
    res+=S*S1;
    FOR (i,1,n){ 
    	int j=i+1;
    	if (i==n) j=1;
    	if (d[i]==0 && d[j]==0){ 
    		res+=c[i]*c[j];
    	} 
    }
    cout<<res<<endl;


         return 0;
}