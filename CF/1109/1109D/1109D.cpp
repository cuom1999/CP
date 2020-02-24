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

const int N = 7;

int deg[N + 1];

vector<int> v[N + 1];
int res[N + 1];

int h[N + 1];

void dfs(int a) {
	for (auto i: v[a]) {
		if (!h[i]) {
			h[i] = h[a] + 1;
			dfs(i);
		}
	}
}

void pruferToTree(int a[N - 1]) {
	int n = N - 2;
	FOR (i, 1, N) {
		v[i].clear();
		deg[i] = 1;
		h[i] = 0;
	}
	FOR (i, 1, n) {
		deg[a[i]]++;
	}

	FOR (i, 1, n) {
		FOR (j, 1, N) {
			if (deg[j] == 1) {
				v[a[i]].pb(j);
				v[j].pb(a[i]);
				deg[j]--, deg[a[i]]--;
				break;
			}
		}
	}
	int u = 0, vv = 0;
	FOR (i, 1, N) {
		if (!u && deg[i]) {
			u = i;
			deg[i]--;
		} 
		else if (deg[i]) {
			vv = i;
		}
	}
	v[vv].pb(u);
	v[u].pb(vv);

	h[1] = 1;
	dfs(1);

	res[h[2] - h[1] - 1]++;
}

int a[N - 1];

void solve(int stt, int a[N - 1]) {
	if (stt == N - 1) {
		//FOR (i, 1, N - 2) cout << a[i] << " "; cout << endl;
		pruferToTree(a);
		return;
	}

	FOR (i, 1, N) {
		a[stt] = i;
		solve(stt + 1, a);
	}
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve(1, a);
	
	FOR (i, 0, N - 2) {
		cout << res[i] << " ";
	}

    return 0;
}