#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
#define FORD(i,a,b) for(ll i=a ; i>=b ; i--)
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

ll a[300005], b[300005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    ll S1=0,S2=0;
    FOR(i,1,n){
    	cin>>a[i];S1+=a[i];
    }
    cin>>m;
    FOR (i,1,m){
    	cin>>b[i];S2+=b[i];
    }
    if (S1!=S2){
    	cout<<-1;
    	return 0;
    }
    int l=0,r=0;
    S1=0; S2=0;
    int res=0;
    while (l<=n || r<=m){
    	if (S1==S2 && S1){
    		S1=0;
    		S2=0;
    		l++; r++;
    		S1+=a[l];
    		S2+=b[r];
    		res++;
    	}
    	else if (S1==S2){
    		l++; r++;
    		S1+=a[l];
    		S2+=b[r];
    	}
    	else if (S1<S2){
    		l++;
    		S1+=a[l];
    	}
    	else {
    		r++;
    		S2+=b[r];
    	}
    	//out<<l<<" "<<r<<" "<<S1<<" "<<S2<<" "<<res<<endl;
    }
    if (S1) res++;
    cout<<res<<endl;


    
	
         return 0;
}