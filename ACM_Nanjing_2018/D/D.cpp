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
#define eps (1e-7)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

struct point {
	ld x, y, z;
};
point a[105];

ld dist(point a, point b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z));
} 

int n;

ld calc(ld x, ld y, ld z) {
	ld res = 0;
	FOR (i, 1, n) {
		res = max(res, sq(a[i].x - x) + sq(a[i].y - y) + sq(a[i].z - z));
	}
	return res;
}


ld findZ(ld x, ld y) {
	ld L = -1e5, R = 1e5, LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	while (R - L > eps) {
		if (calc(x, y, LL) > calc(x, y, RR)) {
			L = LL;
		}
		else R = RR;
		LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	} 
	return calc(x, y, L);
}

ld findY(ld x) {
	ld L = -1e5, R = 1e5, LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	while (R - L > eps) {
		if (findZ(x, LL) > findZ(x, RR)) {
			L = LL;
		}
		else R = RR;
		LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	} 
	return findZ(x, L);	
}



ld findX() {
	ld L = -1e5, R = 1e5, LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	while (R - L > eps) {
		if (findY(LL) > findY(RR)) {
			L = LL;
		}
		else R = RR;
		LL = (L * 2 + R) / 3, RR = (L + R * 2) / 3;
	} 
	return findY(L);
}


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z;
	cout << fixed << setprecision(8) << sqrt(findX()) << endl;
    return 0;
}