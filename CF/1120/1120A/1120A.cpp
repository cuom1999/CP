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

int st[500005 * 4];
int cnt[500005];


void build (int id, int l, int r) {
	if (l == r) {
		st[id] = cnt[l];
		return;
	}

	int mid = (l + r) / 2;

	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v) {
	if (l == r) {
		st[id] += v;
		return;
	}

	int mid = (l + r) / 2;

	if (u <= mid) update(id * 2, l, mid, u, v);
	else update(id * 2 + 1, mid + 1, r, u, v);

	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int a[500005];
int b[500005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N = 500000;

    int m, n, k, s;

    cin >> m >> k >> n >> s;

    FOR (i, 1, m) {
    	cin >> a[i];
    }

    FOR (i, 1, s) {
    	int x;
    	cin >> x;
    	cnt[x]--;
    }

    build(1, 1, N);

    int right = 0;

    FOR (i, 1, m) {
    	while (st[1] < 0 && right < m) {
    		right++;
    		update(1, 1, N, a[right], 1);
    	}
    	if (st[1] >= 0) b[i] = right;
    	else b[i] = INF;
    	update(1, 1, N, a[i], -1);
    } 

    int st = -1;

    FOR (i, 1, m) {
    	int res = 0;

    	if (b[i] - i + 1 > k) {
    		res += b[i] - i + 1 - k;
    	}

    	res += (i - 1) % k;

    	res += max(0, (i - 1) - (i - 1) % k - (n - 1) * k);

    	if (res <= m - n * k) {
    		st = i;
    		break;
    	}
    }

    if (st == -1)  cout << -1 << endl;
    else {
    	vector<int> v;
    	FOR (i, 1, (st - 1) % k) {
    		v.pb(i);
    	}

    	for (int i = (st - 1) % k + 1; i <= max(0, (st - 1) - (st - 1) % k - (n - 1) * k) + (st - 1) % k; i++) {
    		v.pb(i);
    	}

    	if (b[st] - st + 1 > k) {
    		int tmp = b[st] - st + 1;
    		FOR (i, st, b[st]) {
	   			if (cnt[a[i]] >= 0) {
	   				v.pb(i);
	   				tmp--;
	   				if (tmp == k) break;
	   				continue;
	   			}
    			cnt[a[i]]++;
    		}
    	} 

    	cout << v.size() << endl;

    	for (auto i: v) cout << i << " ";
    }



	
    return 0;
}