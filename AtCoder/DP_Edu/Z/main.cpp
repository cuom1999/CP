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
#define sz(n) (int) (n.size())

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;


bool isEqual (ld a, ld b){
    return (abs(a-b)<eps);
}

struct point {
    ld x,y;
    point() {x=y=0;}
    point (ld a, ld b) {x=a;y=b;}
};

struct line {
    ld a, b;
    line (){ a=b=0;}
    line (ld u, ld v){a=u;b=v;}
};

point line_intersection(line l1, line l2){
    ld x=(l1.b-l2.b)/(l2.a-l1.a);
    return point (x,l1.a*x+l1.b);
}

bool operator < (line a, line b){
    if (abs(a.a-b.a) >eps) return a.a>b.a;
    else return a.b>b.b;
}

line l[200004];

//true with both min-max
bool isBad (line l1, line l2, line l3){
    return (line_intersection(l1,l3).x<line_intersection(l1,l2).x || abs(line_intersection(l1,l3).x-line_intersection(l1,l2).x)<eps);
}

vector<line> M;
vector<ld> M1;

//add line i
void add(int i){
    M.pb(l[i]);
    if (M.size()>=2){
        if (isEqual(M[sz(M)-2].a,M[sz(M)-1].a)) {
            M.erase(M.end()-2);
            M1.pop_back();
        }
    }
    while (sz(M)>=3 && isBad(M[sz(M)-3],M[sz(M)-2],M[sz(M)-1])){
        M.erase(M.end()-2);
        M1.pop_back();
    }
    if (M.size()>=2) M1.pb(line_intersection(M[sz(M)-1],M[sz(M)-2]).x);
}

ll query (ll x){
    ll u=sz(M);
    if (M.size() == 1 || x < M1[0]) return (M[0].a*x+M[0].b);
    ll dau=0,cuoi=sz(M1)-1,mid;
    while (dau<cuoi){
        mid=(dau+cuoi+1)/2;
        if (x<M1[mid]) cuoi=mid-1;
        else dau=mid;
    }
    return M[dau+1].a*x+M[dau+1].b;
}

ll h[200005], d[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
  	
  	int n;
  	ll C;
  	cin >> n >> C;

	FOR (i, 1, n) {
		cin >> h[i];
	}

	d[1] = 0;
	l[1] = line(-2 * h[1], sq(h[1]));

	add(1);

	FOR (i, 2, n) {
		d[i] = query(h[i]) + sq(h[i]) + C;

		l[i] = line(-2 * h[i], sq(h[i]) + d[i]);

		add(i);
	}

	cout << d[n] << endl;

    return 0;
}