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

int st[100005], len[100005];
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
	    	if (c[i]=='#'){
	    		if (c[i-1]=='#'){
	    			len[C]++;
	    		}
	    		else{
	    			st[++C]=i;
	    			len[C]=1;
	    		}
	    	}
	    }
	    int e=0;
	    FOR (i,1,n){
	    	if (c[i]=='.') {
	    		e = i ; break;
	    	}
	    }
	    bool qq=0;
	    FOR (i,e,n){
	    	if (c[i]=='#') qq=1;
	    }
	    if (e==0) qq=0;
	    
	    int done = 0;
	    ll res=0;
	    bool q=0;
	    FOR (i,1,C){
	    	while (len[i]){
	    		if (st[i]+len[i]>n){
	    			q=1;
	    			break;
	    		}
	    		if (st[i]==done+1){
	    			done++;
		    		len[i]--;
		    		st[i]++;
		    		continue;
	    		}
		    	res+=(ll) st[i]-done-1;
		    	done++;
		    	len[i]--;
		    	st[i]+=2;
				res+=(ll) len[i];
		    	
		    	if (len[i]+st[i]==st[i+1]){
		    		len[i+1]+=len[i];
		    		st[i+1]=st[i];
		    		len[i]=0;
		    		break;
		    	}
		    }
		    if (q) break;
	    }
	    if (!qq){
	    	cout<<0<<endl;
	    }
	    else if (q){
	    	cout<<-1<<endl;
	    }
	    else{
	    	cout<<res<<endl;
	    }
	    FOR (i,1,C) st[i]=len[i]=0;
	}
	
         return 0;
}