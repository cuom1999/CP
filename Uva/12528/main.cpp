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

ld W, D, A;
int K;
vector<ld> P1, Q1, P2, Q2;

ld calc(vector<ld> &f, ld x) {
	ld val = 1;
	ld res = 0;
	FOR (i, 0, K) {
		res += f[i] * val;
		val *= x;
	}
	return res;
}

ld f1(ld x) {
	ld num = 0, dem = 0;
	num = calc(P1, x);
	dem = calc(Q1, x);
	return num / dem;
}

ld f2(ld x) {
	ld num = 0, dem = 0;
	num = calc(P2, x);
	dem = calc(Q2, x);
	return num / dem;	
}

ld d;

ld f(ld x){
	ld a = f1(x);
	ld b = f2(x);
	a = max(a, d);
	b = max(b, d);
	return a - b;
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

    while (cin >> W) {
    	cin >> D >> A >> K;
    	P1.clear(); Q1.clear(); P2.clear(); Q2.clear();
    	FOR (i, 0, K) {
    		ld x;
    		cin >> x;
    		P1.pb(x);
    	}
    	FOR (i, 0, K) {
    		ld x;
    		cin >> x;
    		Q1.pb(x);
    	}
    	FOR (i, 0, K) {
    		ld x;
    		cin >> x;
    		P2.pb(x);
    	}
    	FOR (i, 0, K) {
    		ld x;
    		cin >> x;
    		Q2.pb(x);
    	}
    	//d = -4;
    	//cout << f(6) << endl;
    	//cout << integrate(0, W) << endl;
    	//return 0;
    	ld L = -D, R = 0;
    	while (abs(R - L) > eps) {
    		d = (L + R) / 2;
    		ld val = integrate(0, W);
    		if (val < A) {
    			R = d;
    		} 
    		else {
    			L = d;
    		}
    	}
    	cout << fixed << setprecision(5) << -L << endl;
    }

    
	
    return 0;
}