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

vector<int> prime;
int comp[4000005];
int trace[4000005];

void sieve(int n){
	for (int i=2; i<=n; i++){
		if (!comp[i]){
			prime.pb(i);
			trace[i]=i;
		}
		for (int j=0; j<prime.size() && prime[j]<=n/i; j++){
			comp[i*prime[j]]=1;
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
int cnt[4000006];

struct vec{
	vector<int> a;
	void trans(){
		sort(all(a));
		reverse(all(a));	
	}
	vec operator ^ (vec b){
		vec res;
		for (int i=0; i<a.size(); i++){
			cnt[a[i]]++;
		}
		for (int i=0; i<b.a.size(); i++){
			cnt[b.a[i]]++;
		}
		for (int i=0; i<a.size(); i++){
			if (cnt[a[i]]==1){
				res.a.pb(a[i]);
			}
		}
		for (int i=0; i<b.a.size(); i++){
			if (cnt[b.a[i]]==1){
				res.a.pb(b.a[i]);
			}
		}
		sort(all(res.a));
		reverse(all(res.a));
		return res;
	}
};

bool operator <(vec a, vec b){
	for (int i=0; i<a.a.size() && i<b.a.size(); i++){
		if (a.a[i]<b.a[i]) return 1;
		else if (a.a[i]>b.a[i]) return 0; 
	}
	if (a.a.size()<b.a.size()) return 1;
	return 0;	
}

vector<vec> basis;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    sieve(4000005);
    int n;
    cin>>n;
    FOR (i,1,n){
    	int x;
    	cin>>x;
    	vec A;
    	while(x>1){
    		int u=trace[x];
    		while (x%u==0){
    			x/=u;
    		}
    		A.a.pb(u);
    	}
    	A.trans();
    	for (int j=0; j<basis.size(); j++){
    		a
    	}
    }


         return 0;
}