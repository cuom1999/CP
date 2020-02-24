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

vector<int> deg;

int n;
ll s[500005], s1[500005];
ll st[500005 * 4];


bool cmp(int a, int b) {
	return a > b;
}

void build (int id, int l, int r) {
	if (l == r) {
		st[id] = s[l];
		return; 
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u, ll v) {
	if (l == r) {
		st[id] = v;
		return;
	}	

	int mid = (l + r) / 2;
	if (u <= mid) update(id * 2, l, mid, u, v);
	else update(id * 2 + 1, mid + 1, r, u, v);

	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

vector<int> ans;

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    
    deg.pb(INF);
    int sum = 0;
    FOR (i, 1, n) {
    	int x;
    	cin >> x;
    	deg.pb(x);
    	sum = (sum + x) % 2;
    }
    
    n++;

    int down = n + 1, up = 0;
    int bound = (n - 1 - sum) / 2;
	
	deg.pb(2 * bound + sum);

	sort(all(deg));
    reverse(all(deg));

    FOR (i, 1, n) {
		s1[i] = s1[i - 1] + deg[i];
	}

	int pointer = 1;

	FOR (k, 1, n) {
		if (pointer <= k) pointer = k + 1;
		while (deg[pointer] <= k && pointer <= n) pointer++;
		ll sum = k * (k - 1) - s1[k];
		sum += s1[pointer - 1] - s1[k];
		sum += k * (n - pointer + 1);
		s[k] = sum;
	}
	build(1, 1, n);

	if (st[1] >= 0) ans.pb(bound);

	int cur = bound - 2;
	
	int u = lower_bound(all(deg), bound, cmp);
	int v = u;
	while (cur >= 0) {
		if (v <= u) v = u + 1;
		while (deg[v] > cur && v <= n + 1) v++;
		v--;
		FOR (i, u, v - 1) {
			s[i] += (cur + 2);
			s[i] -= deg[i + 1];
			s[i] -= min(i, deg[i + 1]);
			s[i] += min(i, cur);
			update(1, 1, n, i, s[i]); 
		}

		if (cur + 2 < u) {
			s[cur + 2] -= 2; 
			update(1, 1, n, cur + 2, s[cur + 2]); 
		}
		if (cur + 1 < u) {
			s[cur + 1] -= 1; 
			update(1, 1, n, cur + 1, s[cur + 1]); 
		}
		if (st[1] >= 0) ans.pb(cur);
	}

	reverse(all(ans));
	if (ans.size() == 0) {
		cout << -1;
	}
	else {
		for (auto i: ans) cout << i << " ";
	}


	
    return 0;
}