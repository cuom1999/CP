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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

const int MAXN = (1 << 20) + 4;

int cnt[MAXN];
int res[MAXN];
int a[MAXN];

vector<II> v;

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;

    cin >> n;

    FOR (i, 1, (1 << n)) {
    	int x;
    	cin >> x;
    	// cnt[x]++;
    	v.pb(II(x, i));
    } 

    int C = 0;

    sort(all(v));

    for (int i = 0; i < v.size(); i++) {
    	if (!i || v[i].first != v[i - 1].first) {
    		a[v[i].second] = ++C;
    	}
    	else {
    		a[v[i].second] = C;
    	}
    }

    FOR (i, 1, (1 << n)) {
    	cnt[a[i]]++;
    }

    int sum = 0;

    FOR (i, 1, (1 << n)) {
     	sum += cnt[i];
     	res[i] = log2(sum);
    }

    FOR (i, 1, (1 << n)) {
    	cout << n - res[a[i]] << " ";
    }

	
    return 0;
}