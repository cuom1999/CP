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
#define eps (1e-15)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n;
ld x[100005], y[100005];

bool calc_y (ld Y){
	ld mi=-1e18,ma=1e18;
	FOR (i,1,n){
		ld T=2*Y*y[i]-sq(y[i]);
		if (T<0) return 0;
		T=sqrt(T);
		//cout<<x[i]-T<<" "<<x[i]+T<<endl;
		mi=max(mi,x[i]-T);
		ma=min(ma,x[i]+T);
	}
	if (mi<=ma) return 1;
	return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int am=0,du=0;
    FOR (i,1,n) {
    	cin>>x[i]>>y[i];
    	if (y[i]>0) du=1;
    	else am=1;
    }
    if (am&&du) {
    	cout<<-1;
    	return 0;
    }
    if (am){
    	FOR (i,1,n) y[i]=-y[i];
    }
    ld st=0,en=1e18; //en++;
    FOR (i,1,n) st=max(st,y[i]/2.0);
    ld mid;
    while (fabs(en-st)/en>eps){
    	mid=(en+st)/2;
    	bool q=calc_y(mid);
    	if (q){
    		en=mid;
    	}
    	else st=mid;
    }
    cout<<fixed<<setprecision(8)<<st<<endl;


	
         return 0;
}