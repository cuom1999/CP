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

int dd[1000005];

int tcs(int n){
    int res=0;
    while (n){
        res+=(n%10)*(n%10);
        n/=10;
    }
    return res;
}
ll d[1000005];

ll calc (ll a){
    if (a==1) return 1;
    if (d[a]) return d[a];
    if (dd[a] && d[a]==0) return d[a]=2;
    dd[a]=1;
    ll w=a;
    a=tcs(a);
    return d[w]=calc(a);
}
vector<ll> v;
int cnt[1000005];
int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (a,1,2000){
        if (calc(a)==1) {v.pb(a);}
    }

    FOR (i,0,9999){
    	int m=tcs(i);
    	for (auto j:v){
    		if (j>=m){
    			cnt[j-m]++;
    		}
    	}
    }

	int t;
	cin>>t;
	FOR (z,1,t){
		int l,r;
		cin>>l>>r;
        if (r==1000000000) r--;
		int l1 = l/10000;
		int r1 = r/10000;
		int res=0;
		FOR (i,l1+1,r1-1){
			res+=cnt[tcs(i)];
		}
		if (l1<r1){
			FOR (i,l,(l1+1)*10000-1){
				if(calc(tcs(i))==1) res++;
			}
			FOR (i,r1*10000,r){
				if (calc(tcs(i))==1) res++;
			}
		} 
		else{
			FOR(i,l,r){
				if (calc(tcs(i))==1) res++;
			}
		}
		cout<<r-l+1-res<<endl;
	}    

         return 0;
}