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
#define EPS (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

bool checkInt(ld t){
	return (fabs(t-(ll)t)<EPS);
}

inline int cmp(ld a, ld b) {
	return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

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
};
ld dist(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y -
	b.y) * (a.y - b.y)); }
// end of Point section --------------------------------------------------
// Line section ----------------------------------------------------------
struct line {
	ld a, b, c;
	point A, B;
	line(ld a = 0, ld b = 0, ld c = 0) : a(a), b(b), c(c) {}
	line(point A, point B) : A(A), B(B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = -(a * A.x + b * A.y);
	}
};
bool areParallel(line l1, line l2) { return cmp(l1.a*l2.b, l1.b*l2.a) ==0; }
	
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;
	ld dx = l1.b*l2.c - l2.b*l1.c;
	ld dy = l1.c*l2.a - l2.c*l1.a;
	ld d = l1.a*l2.b - l2.a*l1.b;
	p = point(dx/d, dy/d);
	return true;
}

bool check(point A, point B, point I){
	if (A.x<B.x) swap(A,B);
	return (((ll)I.x<=(ll)A.x && (ll)I.x>=(ll)B.x) && (((ll)I.y<=(ll)A.y && (ll)I.y>=(ll)B.y) || ((ll)I.y<=(ll)B.y && (ll)I.y>=(ll)A.y)));
}

map<point,int> dd;


ll a[1005],b[1005];
ll c[1005],d[1005];
ll t[1000005];

ll calc(ll a, ll b, ll c, ll d){
	c=c-a; d-=b;
	if (c<0) c=-c;
	if (d<0) d=-d;
	return __gcd(c,d)+1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    for (ll i=1; i<=1000; i++){
    	t[i*(i+1)/2]=i;
    }
    int n;
    cin>>n;
    FOR (i,1,n){
    	cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    FOR (i,1,n){
    	FOR (j,i+1,n){

    		line l1=line(point((ld)a[i],(ld)b[i]),point((ld)c[i],(ld)d[i]));
    		line l2=line(point((ld)a[j],(ld)b[j]),point((ld)c[j],(ld)d[j]));
    		point p;
    		//cout<<i<<" "<<j<<endl;
    		if (areIntersect(l1,l2,p)){
    			//cout<<i<<" "<<j<<" "<<p.x<<" "<<p.y<<endl;
    			if (checkInt(p.x) && checkInt(p.y)){
    				p.x=(ll)p.x; p.y=(ll) p.y;
    				if (check(point(a[i],b[i]),point(c[i],d[i]),p) && check(point(a[j],b[j]),point(c[j],d[j]),p)){
    					dd[p]++;
    				}
    			}
    		}
    	}
    }
    //for (auto i:dd) cout<<i.first.x<<" "<<i.first.y<<" "<<i.second<<endl;	
    ll res=0;
    FOR (i,1,n){
    	res+=calc(a[i],b[i],c[i],d[i]);
    }
    for (auto i:dd){
    	res-=t[i.second];
    }
    cout<<res<<endl;
	
         return 0;
}