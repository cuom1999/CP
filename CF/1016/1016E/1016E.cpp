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
#define EPS (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
struct point {
	ld x, y;
	point(ld x = 0, ld y = 0) : x(x), y(y) {}
	point operator+ (const point &a) const { return point(x+a.x, y+a.y); }
	point operator- (const point &a) const { return point(x-a.x, y-a.y); }
	point operator * (ld k) const { return point(x*k, y*k); }
	point operator / (ld k) const { return point(x/k, y/k); }
	bool operator== (point &p) {
		return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
	}
	bool operator< (const point &p) const {
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y < p.y;
	}
	point rotate(ld alpha) {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y *cos(alpha));
	}
	void read() {
		cin >> x >> y;
	}
	void write() {
		cout << fixed << setprecision(6) << x << " " << y << endl;
	}
};

ld dist(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y -b.y) * (a.y - b.y)); }

struct line {
	ld a, b, c;
	point A, B;
	line(ld a = 0, ld b = 0, ld c = 0) : a(a), b(b), c(c) {}
	line(point A, point B) : A(A), B(B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = -(a * A.x + b * A.y);
	}
	line(point P, ld m) {
		a = -m; b = 1;
		c = -((a * P.x) + (b * P.y));
	}
	ld f(point A) {
		return a*A.x + b*A.y + c;
	}
};

ll sy,a,b;

ll s[200005];

vector<ll> L,R;
int n;

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>sy>>a>>b;
    point A(a,sy);
    point B(b,sy);

    L.pb(0);
    R.pb(0);
    cin>>n;
    FOR (i,1,n) { 
    	ll l,r;
    	cin>>l>>r;
    	L.pb(l);
    	R.pb(r);
    	s[i]=s[i-1]+r-l;
    }
    L.pb(1e18);
    R.pb(1e18);
    int q;
    cin>>q;
    FOR (z,1,q){ 
    	ll x,y;
    	cin>>x>>y;
    	point M(x,y);
    	line la=line (M,A);
    	line lb=line (M,B);
    	ld u1=-la.c/la.a;
    	ld u2=-lb.c/lb.a;
    	int l=lower_bound(all(R),u1)-R.begin();
    	int r=upper_bound(all(L),u2)-L.begin()-1;
    	//cout<<l<<" "<<r<<endl;
    	ld res=0;

    	if (l==r){ 
    		res=min(u2,(ld) R[r])-max(u1,(ld)L[r]);
    	}
    	else if (l>r) res=0;
    	else{
	    	res=s[r-1]-s[l];
	    	//cout<<res<<endl;
	    	res+=min(u2,(ld) R[r])-L[r];
	    	res+=R[l]-max(u1,(ld) L[l]);
    	}
    	res=res/y*(-sy+y);
    	cout<<fixed<<setprecision(8)<<res<<endl;
    }




         return 0;
}