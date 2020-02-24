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
ll a[150005], b[150005], c[150005];
int n;
bool check(ll k){ 
	if (k<=1) return 0;
	FOR (i,1,n){ 
		if ( (a[i]%k)==0 || (b[i]%k)==0 ) continue;
		else return 0;
	}
	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR (i,1,n){ 
    	cin>>a[i]>>b[i];
    	c[i]=a[i]*b[i];
    }
    ll res=c[1];
    FOR (i,2,n){ 
    	res=__gcd(res,c[i]);
    }
    ll t1=__gcd(res,a[1]);
    ll t2=__gcd(res,b[1]);
    ll r1=0,r2=0;
    for (ll i=2; i*i<=t1; i++){ 
    	if (t1%i==0) { 
    		r1=i;
    	}
    }
    if (!r1) r1=t1;
    for (ll i=2; i*i<=t2; i++){ 
    	if (t2%i==0) { 
    		r2=i;
    	}
    }
    if (!r2) r2=t2;
    //cout<<t1<<" "<<t2<<endl;
    if (check(r1)) { 
    	cout<<r1;
    	return 0;
    }
    if (check(r2))  {
    	cout<<r2;
    	return 0;
    }
    cout<<-1;


         return 0;
}