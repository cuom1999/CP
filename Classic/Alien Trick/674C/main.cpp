#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

typedef pair < int, ld > ID;
typedef pair < ll, ll > pll;

ld a[200005], s[200005], f[200005], u[200005];
ld d[200005];
int cnt[200005];

ld cost(int i, int j) {
	return f[j] - f[i - 1] - s[i - 1] * (u[j] - u[i - 1]);
}

struct Point {
	ld x, y;
	int index;
};

struct CHT {
	vector<Point> v;

	ld cross (Point a, Point b) {return (ld)(b.y - a.y) / (b.x - a.x);}

	void addLine(ld x, ld y, int index) {
		if (v.size() && v.back().x == x && v.back().y == y) return;

		while(v.size() >= 2 && cross(v[v.size()-2], v.back()) > cross(v.back(), (Point){x, y})){
			v.pop_back();	
		}
		v.push_back({x, y, index});
	}

	ID query(ld x) {
		int s = 0, e = (int) v.size()-1;
		auto f = [&](int p) {
			return v[p].x * x + v[p].y;
		};
		while(s != e){
			int m = (s + e) / 2;
			if(f(m) <= f(m+1)) e = m;
			else s = m + 1;
		}
		return {v[s].index, v[s].x * x + v[s].y};
	}
};

int n, k;
	
// each region costs x 
ID solve(ld x) {
	CHT cht;
	// (s[i], u[i] * s[i] - f[i] + d[i])
	cht.addLine(0, 0, 0);

	FOR (i, 1, n) {
		auto q = cht.query(-u[i]);
		d[i] = q.second + f[i] + x;
		cht.addLine(s[i], u[i] * s[i] - f[i] + d[i], i);
		cnt[i] = cnt[q.first] + 1;
	}

	return {cnt[n], d[n]};
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	FOR (i, 1, n) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		f[i] = f[i - 1] + s[i] / a[i];
		u[i] = u[i - 1] + 1 / a[i];
 	}

 	ld L = 0, R = 1e15;
 	while (R - L > (1e-6)) {
 		ld mid = (L + R) / 2;
 		if (solve(mid).first <= k) {
 			R = mid;
 		}
 		else {
 			L = mid;
 		}
 	}

 	cout << fixed << setprecision(8) << solve(L).second - k * L << endl;
 	

	return 0;
}