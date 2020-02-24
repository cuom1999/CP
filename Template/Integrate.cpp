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

ld X0,Y0,X1,Y1,X2,Y2,r;

ld f(ld x){
	ld a=min(Y2,sqrt(r*r-x*x));
	ld b=max(-sqrt(sq(r)-sq(x)),Y1);
	return max((ld)0,a-b);
}

inline double simpson(double fl,double fr,double fmid,double l,double r) { return (fl+fr+4.0*fmid)*(r-l)/6.0; }
double rsimpson(double slr,double fl,double fr,double fmid,double l,double r)
{
	double mid = (l+r)*0.5;
	double fml = f((l+mid)*0.5);
	double fmr = f((mid+r)*0.5);
	double slm = simpson(fl,fmid,fml,l,mid);
	double smr = simpson(fmid,fr,fmr,mid,r);
	if(fabs(slr-slm-smr) < eps) return slm+smr;
	return rsimpson(slm,fl,fmid,fml,l,mid)+rsimpson(smr,fmid,fr,fmr,mid,r);
}
double integrate(double l,double r)
{
	double mid = (l+r)*.5;
	double fl = f(l);
	double fr = f(r);
	double fmid = f(mid);
	return rsimpson(simpson(fl,fr,fmid,l,r),fl,fr,fmid,l,r);
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>X0>>Y0>>r){
	    cin>>X1>>Y1>>X2>>Y2;
	    if(X1>X2) swap(X1,X2);
	    if (Y1>Y2) swap(Y1,Y2);
	    X1-=X0; Y1-=Y0; X2-=X0; Y2-=Y0;

	    ld st=max(-r,X1);
	    ld en=min(r,X2);
	    if (st>en){
	    	cout<<0<<endl;
	    	continue;
	    }
	    cout<<fixed<<setprecision(10)<<integrate(st,en)<<endl;
	}


	
         return 0;
}