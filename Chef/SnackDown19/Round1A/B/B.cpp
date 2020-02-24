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
#define INF 1000000001
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int a[100005],b[100005],c[100005];

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
    		b[i]=a[i];
    	}
    	sort(b+1,b+n+1);
    	int cnt=0;
    	FORD (i,n,1){
    		if (a[i]==a[1]){
    			cnt++;
    		}
    		else break;
    	}
    	int u=1;
    	FOR (i,1,n){
    		if (b[i]==a[1]){
    			u=i+cnt; break;
    		}
    	}
    	if (cnt==n){
    		cout<<"YES"<<endl;
    	}
    	else{
    		bool q=0;
    		FOR (i,1,n){
    			if (a[i]!=b[u]) {q=1; break;}
    			u++;
    			if (u>n) u=1;
    		}
    		if (q) cout<<"NO"<<endl;
    		else cout<<"YES"<<endl;
    	}
    }
    
	
         return 0;
}