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

struct query
{
	int l, r, stt;
	query (int __l=0, int __r=0, int __stt=0){ 
		l=__l; r=__r; stt=__stt;
	}
};

bool operator < (query a, query b) { 
	if (a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}

vector<query> Q;

int fen[1000005];
int n;
void add(int u, int v){ 
	for (int i=u; i<=n; i+=i&-i){ 
		fen[i]^=v;
	}
}

int sum(int u){ 
	int res=0;
	for (int i=u; i; i-=i&-i){ 
		res^=fen[i];
	}
	return res;
}

int a[1000005];
int res[1000005];
unordered_map<int, int> pre;
int s[1000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR (i,1,n) {
    	cin>>a[i];
    	s[i]=s[i-1]^a[i];
    }
    int m;
    cin>>m;
    FOR (i,1,n){ 
    	Q.pb(query(0,i,0));
    }
    FOR (i,1,m){ 
    	int l, r;
    	cin>>l>>r;
    	Q.pb(query(l,r,i));
    }
    sort(all(Q));
    for (auto q:Q){ 
    	if (q.l==0){ 
    		add(q.r,a[q.r]);
    		int k=pre[a[q.r]];

    		if (k) add(k,a[q.r]);
    		pre[a[q.r]]=q.r;
    	}
    	else { 
    		res[q.stt]=sum(q.r)^sum(q.l-1);
    		res[q.stt]^=(s[q.r]^s[q.l-1]);
    		//cout<<q.l<<" "<<q.r<<" "<<res[q.stt]<<endl;
    	}
    	/*cout<<q.r<< "K"<<endl;
    	FOR (i,1,q.r) { 
   			int t=sum(i)^sum(i-1);
			cout<<t<<" ";    			
   		}
   		cout<<endl;*/
    }
    FOR (i,1,m) cout<<res[i]<<endl;

    
         return 0;
}