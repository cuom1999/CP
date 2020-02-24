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

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

map<string, int> d;

struct cmp {
	bool operator () (const string &a, const string &b) { 
		return a.length() < b.length();
	}
};

priority_queue<string, vector<string>, cmp> pq;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    FOR (z, 1, t) {
    	cout << "Case #" << z << ": ";

    	d.clear();
    	while (pq.size()) pq.pop();

	    int n;
	    cin >> n;

	    FOR (i, 1, n) {
	    	string s;
	    	cin >> s;

	    	string suf;
	    	FORD (j, s.length() - 1, 0) {
	    		suf = s[j] + suf;
	    		d[suf]++;
	    	}
	    }

	    for (auto i: d) {
	    	if (i.second > 1) {
	    		pq.push(i.first);
	    	}
	    }

	    int res = 0;

	    while (pq.size()) {
	    	string s = pq.top();
	    	pq.pop();
	    	if (d[s] <= 1) continue;
	    	res += 2;

	    	string suf;
	    	FORD (j, s.length() - 1, 1) {
	    		suf = s[j] + suf;
	    		d[suf] -= 2;
	    	}
	    }

	    cout << res << endl;
	}

    
	
    return 0;
}