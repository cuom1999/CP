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


char c[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
    	int n;
    	cin>>n;
    	int C=0;
    	FOR (i,1,n){
    		cin>>c[i];
    		if (c[i]=='#') C++;
    	}
    	int done = 0 ;
    	ll res=0;
    	bool q=0;
    	while (done<C){
	    	FOR (i,done+1,n){
	    		if (c[i]=='#') {
	    			done=i;
	    		}
	    		else break;
	    	}
	    	if (done==C) break;
	    	int st=0;
	    	FOR (i,done+1,n){
	    		if (c[i]=='#'){
	    			st=i; break;
	    		}
	    	}
	    	int en=n+1;
	    	FOR (i,st,n){
	    		if (c[i]=='.') {
	    			en=i-1; break;
	    		}
	    	}
	    	if (en==n+1){
	    		q=1;
	    		break;
	    	}
	    	res+=(ll)st-done-1;
	    	res+=(ll)en-st;
	    	done++;
	    	c[done]='#';
	    	c[st]='.';
	    	if (st!=en){
		    	c[st+1]='.';
		    	c[en+1]='#';
		    }
	    }
	    if (q) cout<<-1<<endl;
	    else cout<<res<<endl;
    }
    
	
         return 0;
}