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
int comp[15000006];
int trace[15000006];

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
				trace[i*prime[j]]=prime[j];
			}
		}
	}
}
int a[300005],m[15000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    sieve(15000000);
	int n;
	cin>>n;
	FOR (i,1,n){
		cin>>a[i];
	}	
	int g=a[1];
	FOR (i,1,n){
		g=__gcd(g,a[i]);
	}
	FOR (i,1,n){
		a[i]/=g;	
	}
	int cnt=0;
	FOR (i,1,n){
		if (a[i]==1){
			cnt++; continue;
		}
		int t=a[i];
		while(t>1){
			m[trace[t]]++;
			int q=trace[t];
			while (t%q==0) t/=q;
		}
	}
	int res=0;
	FOR (i,2,15000000){
		res=max(res,m[i]);
	}
	if (res==0){
		cout<<-1;
	}
	else{
		cout<<n-res<<endl;
	}
         return 0;
}