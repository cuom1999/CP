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

int n;
ld x[100005], y[100005];

inline int calc(ld X, ld Y){
	int t=0,tt=0;
	FOR (i,1,n){
		if (sq(x[i]-X)-2*Y*y[i]+sq(y[i])>0) {
			if (x[i]<X) t=1;
			else tt=1;
		}
	}
	if (t&&tt) return 2;
	if (t) return -1;
	if (tt) return 1;
	return 0;
}

bool calc_y (ld Y){
	ld st=-1e8, en=1e8;
	ld mid=(st+en)/2;
	while (en-st>eps){
		mid=(en+st)/2;
		int q=calc(mid,Y);
		if (q==2) return 0;
		if (q==0) return 1;
		if (q==-1){
			en=mid;
		}
		if (q==1){
			st=mid;
		}
	}
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
    ld st=0,en=5e13;
    en++;
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
    cout<<fixed<<setprecision(8)<<en<<endl;


	
         return 0;
}