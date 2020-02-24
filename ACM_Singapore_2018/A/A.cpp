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
typedef pair < ll, ll > II;



struct point {
	ld x,y;
    //point(){x=y=0;}
	point(ld a,ld b){ x=a; y=b; }
	void writepoint(){
		cout<<x<<" "<<y<<endl;
	}
};
struct vec{
	ld x,y;
	vec(ld a, ld b){x=a; y=b;}
};

vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}

ld cross (vec a, vec b){
	return a.x*b.y-a.y*b.x;
}

bool ccw(point m, point n, point a) {
    //return true if point a is on the left side of line mn
    //change to >=0 if accept a on mn
	return (cross(toVec(m,n),toVec(m,a))>eps);
}

bool collinear(point a, point b, point c){
    // return true if a,b,c are collinear
	return (fabs(cross(toVec(a,b),toVec(a,c)))<eps);
}
//atan2

vector<point> P,CH;
point pivot(INF,INF);

ld dist (point a , point b){
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

bool angcmp(point a,point b){
	if (collinear(a,b,pivot)) return (dist(a,pivot)<dist(b,pivot));
	ld d1x=a.x-pivot.x, d1y=a.y-pivot.y;
	ld d2x=b.x-pivot.x, d2y=b.y-pivot.y;
	return (atan2(d1y,d1x)-atan2(d2y,d2x)<0);
}

ld area(point A, point B, point C) {
	return abs(A.x * B.y - A.y * B.x + B.x * C.y - B.y * C.x + C.x * A.y - C.y * A.x) / 2.0;
}

map<II, int> d;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	ll n;
	ll x,y;

	cin>>n;

	ll r=1;
	pivot=point((ld)INF,(ld)INF);
	FOR (i,1,n){
		cin>>x>>y;
		if (d.find(II(x, y)) == d.end()) {
			P.pb(point(x,y));
			if ((pivot.y>y) || (pivot.x>x && pivot.y==y)) {pivot=point(x,y);r=i-1;}
		}
		d[II(x, y)] = 1;
	}
	n = P.size();
	point temp=P[0]; P[0]=pivot; P[r]=temp;
	sort(++P.begin(),P.end(),angcmp);

	if (collinear(P[0], P[1], P[n - 1])) {
		cout << 0;
		return 0;
	}
	CH.pb(P[n-1]); CH.pb(P[0]); CH.pb(P[1]);
	ll ii=2;

	while (ii<n){
		ll j=(ll) CH.size()-1;
		if (ccw(CH[j-1],CH[j],P[ii])) CH.pb(P[ii++]);
		else CH.pop_back();
	}
	CH.pop_back();


	ll m=CH.size();
	ld res = 0;
	FOR (i, 0, m - 1) {
		int k = i + 2;
		FOR (j, i + 1, m - 2) {
			k = max(k, j + 1);
			while (k <= m - 1 && area(CH[i], CH[j], CH[k]) < area(CH[i], CH[j], CH[k + 1])) {
				k++;
			}
			res = max(res, area(CH[i], CH[j], CH[k]));
		} 
	}	
	cout << fixed << setprecision(8) << res << endl;

	return 0;
}
