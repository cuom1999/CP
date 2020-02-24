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

vector<int> S,T;
int x;
int solve(vector<int>&v){
	int m=(1e9)+1;
	ll res=0;
	for (auto i:v) m=min(m,i);
	for (int i=0 ; i<v.size(); i++){ 
		v[i]-=m;
	}
	vector<int> v1;
	ll R=0;
	int n=v.size();	
	for (auto i:v){ 
		v1.pb(i%x);
		//cout<<i<<" "<<i%x<<endl;
		res+=(ll) ((ll)i-i%x)/x;
		R+=(ll) ((ll)i-i%x)/x;
		res%=n;
	}
	sort(all(v1));
	res%=n;
	v.clear();
	FOR (i,res,res+n-1){ 
		v.pb(v1[i%n]);
	}
	return R%2;
}


int a[500005];
int b[500005];
vector<int> S1,T1;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m>>x;

    FOR (i,1,n) {
    	int k;
    	cin>>k;
    	S.pb(k);    	
    }
    FOR (i,1,m) { 
    	int k;
    	cin>>k;
    	T.pb(k);
    }
    S1=S;
    T1=T;
    int e1=solve(S);
    int e2=solve(T);
    bool s1=0;
    bool t1=0;
    for (auto i:S){ 
    	if (i) s1=1;
    }
    for (auto i:T){ 
    	if (i) t1=1;
    }

  	ll res=1e18;
  	//for (auto i:S) cout<<i<<" "; cout<<endl;
  	//for (auto i:T) cout<<i<<" ";
	int g=__gcd(m,n);
	if (s1 && t1){
		FOR (i,0,g-1){ 
			a[i]=b[i]=2e9;
		}
		FOR (i,0,n-1){
			int q=(S[i]-S[(i+1)%n]+x)%x;
			if (q==0) q=x;
			a[i%g]=min(a[i%g],q);
		}
		FOR (i,0,m-1){
			int q= (T[i]-T[(i+1)%m]+x)%x;
			if (q==0) q=x;
			b[i%g]=min(b[i%g],q);
		}

		FOR (i,0,g-1){ 
			res=min(res,(ll) a[i] + b[i]);
		}
		cout<<res<<endl;
	}
	if (!s1 && !t1){ 
		if (m==1 || n==1) {
			cout<<0;
			return 0;
		}
		int res1=0;
		if ((m+n)%2) { 
			cout<<0;
			return 0;
		}
		for (auto i:S1){ 
			res1+=i/x;
		}
		int res2=0;
		for (auto i:T1){ 
			res2+=i/x;
		}
		if ((res1-res2)%2==0) { 
			cout<<0;
		}
		else cout<<x;
	}
	if (s1 && !t1) {
		sort(all(S));

		e1=(bool) ((e1+e2)%2);
		FORD (i,n-1,0){ 
			int q=(S[i]-S[(i+1)%n]+x)%x;
			if (q==0) q=x;
			if (e1) res=min(res,(ll) q+x);
			else res=min(res,(ll) q);
			e1^=1;
		}
		FORD (i,n-1,0){ 
			int q=(S[i]-S[(i+1)%n]+x)%x;
			if (q==0) q=x;
			if (e1) res=min(res,(ll) q+x);
			else res=min(res,(ll) q);
			e1^=1;
		}
	}
	if (!s1 && t1){ 
		sort(all(T));
		//cout<<e1<<" "<<e2<<endl;
		e1=(bool) ((e1+e2)%2);
		FORD (i,m-1,0){ 
			int q=(T[i]-T[(i+1)%m]+x)%x;
			if (q==0) q=x;
			if (e1) res=min(res,(ll) q+x);
			else res=min(res,(ll) q);
			e1^=1;
		}
		FORD (i,m-1,0){ 
			int q=(T[i]-T[(i+1)%m]+x)%x;
			if (q==0) q=x;
			if (e1) res=min(res,(ll) q+x);
			else res=min(res,(ll) q);
			e1^=1;
		}
		cout<<res<<endl;

	}



         return 0;
}
