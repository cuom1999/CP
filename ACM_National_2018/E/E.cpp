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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> prime;
int comp[400005];
int trace[400005];
void sieve(int n){
	FOR (i,2,n){
		if (!comp[i]){
			prime.pb(i);
			trace[i]=i;
		}
		for (int j=0; j<prime.size() && prime[j]<=n/i; j++){
			comp[prime[j]*i]=1;
			if (i%prime[j]==0){
				trace[i*prime[j]]=prime[j];
				break;
			}
			else{
				trace[i*prime[j]]=trace[i];
			}
		}
	}
}

vector<int> divisors;
vector<II> fact;

void listDiv(int n, ll u, int m){
	if (u>=m) return;
	if (n==fact.size()) {
		divisors.pb(u);
		return ;
	}
	ll Y=u;
	FOR(i,0,fact[n].second){
		listDiv(n+1,Y,m);
		Y*=fact[n].first;
	}
}

void handle(int n){
	divisors.clear();
	fact.clear();
	int N=n;
	while (n>1){
		int u=trace[n];
		int cnt=0;
		while (n%u==0){
			cnt++;
			n/=u;
		}
		fact.pb(II(u,2*cnt));
	}
	listDiv(0,1,N);
}

vector<int> Q[400005];
ll S[1000005];

void gen (int a, int b, int c){
	int s=a+b+c;
	int x0=b, x1=c;
	while (1){
		ll u=x1*1ll*x1;
		if (u%x0!=0) break;
		u/=x0;
		x0=x1;
		x1=u;
		if (x1>1000000) break;
		s+=x1;
		if (s>1000000) break;
		S[s]++;
	}
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    sieve(400000);
    
    FOR (i,2,400000){
    	handle(i);
    	Q[i]=divisors;
    }
    int cnt=0;
    FOR (n,2,400000){
    	for (auto a:Q[n]){
	    	ll N=n*1ll*n/a;
	    	if (N+a+n>1000000) continue;
	    	S[N+a+n]++;
	    	gen(a,n,N);
	    }
    }

    int nn;
    cin>>nn;
    FOR (i,1,nn){
    	int x;
    	cin>>x;
    	ll res=S[x]+(x-1)/2+1;
    	cout<<res<<" ";
    }




         return 0;
}