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
#define eps (1e-10)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ld, ld > DD;

vector<DD> v;

ld x[1005], y[1005];

void add(int i, int j) {
	ld a, b;
	if (x[i] == x[j]) {
		a = 1e9;
		b = x[i];
	}
	else {
		a = (y[j] - y[i]) / (x[j] - x[i]);
		b = y[i] - a * x[i];
	}
	v.pb({a, b});
}

bool equalLD(ld a, ld b) {
	return abs(a - b) < eps;
}
bool equalDD(DD a, DD b) {
	return equalLD(a.first, b.first) && equalLD(a.second, b.second);
}

bool cmp(DD a, DD b) {
	if (equalLD(a.first, b.first)) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

vector<int> val;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	FOR (i, 1 , n) {
		cin >> x[i] >> y[i];
	}

	FOR (i, 1, n) {
		FOR (j, i + 1, n) {
			add(i, j);
		}
	}

	sort(all(v), cmp);

	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (i && equalDD(v[i], v[i - 1])) continue;
		// cout << v[i].first << " " << v[i - 1].first << endl;
		if (equalLD(v[i].first, v[i - 1].first)) {
			cnt++;
		}
		else { 	
			val.pb(cnt);
			cnt = 1;
		}
	}		
	val.pb(cnt);

	ll sum = 0;
	ll sum1 = 0;

	for (auto i: val) {
		sum += i;
		sum1 += i * 1ll * (i - 1) / 2;
		// cout << i << " ";
	}

	cout << sum * (sum - 1) / 2 - sum1 << endl;

	return 0;
}