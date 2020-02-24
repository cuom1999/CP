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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;


struct Data {
	int l, r, id;
};

int n, b;
bool bad[1028];

int cnt = 0;

string query(string q) {
	// cnt++;
	string s;
	// FOR (i, 0, n - 1) {
	// 	if (!bad[i]) s += q[i];
	// }
	// cout << q << " " << s << endl;
	cout << q << endl;
	cout.flush();
	cin >> s;
	return s;
}

void input() {
	// n = rand() % 1023 + 2;
	// b = rand() % 15 + 1;
	// n = 1023, b = 12;
	// b = min(b, n - 1);
	// set<int> s;
	// while (s.size() < b) {
	// 	s.insert(rand() % n);
	// }

	// memset(bad, 0, sizeof(bad));

	// for (auto i: s) bad[i] = 1;
	// cout << n << " " << b << endl;
	// for (auto i: s) cout << i << " "; cout << endl;
	int f;
	cin >> n >> b >> f;
}

vector<int> ansList;
vector<Data> segLevel[15];
int numBad[69000];

int main()
{//IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    int t;
    cin >> t;
    FOR (z, 1, t) {
	    input();
		ansList.clear();
		FOR (i, 0, 14) segLevel[i].clear();
		FOR (i, 0, 65000) numBad[i] = 0;
		cnt = 0;

		string q1(n, '0');

		FOR (i, 0, n - 1) {
			if ((i / 16) % 2 == 0) q1[i] = '1';
		}

		string ans1 = query(q1);

		int curGroupSize = 0;
		int curGroup = -1;
		ans1 += '.';

		FOR (i, 0, ans1.size() - 1) {
			if (!i || ans1[i] != ans1[i - 1]) {
				if (i) {
					Data d = {curGroup * 16, min(curGroup * 16 + 15, n - 1), 64 * curGroup + 1};
					segLevel[0].pb(d);
					numBad[d.id] = d.r - d.l + 1 - curGroupSize; 
				}
				curGroup++;
				curGroupSize = 1;
			}
			else {
				curGroupSize++;
			}
		}
	    FOR (i, 1, 11) {
	    	for (auto j: segLevel[i - 1]) {
	    		if (j.l == j.r) continue;
	    		else {
	    			int mid = (j.l + j.r) / 2;
	    			segLevel[i].pb({j.l, mid, j.id * 2});
	    			segLevel[i].pb({mid + 1, j.r, j.id * 2 + 1});
	    		}
	    	}
	    }

	    // FOR (i, 0, 10) {
	    // 	// cout << i << ": ";
	    // 	// for (auto j: segLevel[i]) cout << "(" << j.l << " " << j.r << " " << numBad[j.id] << ") ";
	    // 	// cout << endl;
	    // 	for (auto j: segLevel[i]) if (j.l == j.r) cout << j.l << " " << j.id << endl;
	    // }

	    FOR (i, 0, 11) {
	    	if (segLevel[i].size() == 0) break;
	    	bool isEnd = 1;
	    	for (auto j: segLevel[i]) {
	    		if (j.l != j.r) isEnd = 0;
	    	}
	    	
	    	if (isEnd) break;

	    	string q(n, '0');

	    	for (auto j: segLevel[i]) {
	    		if (numBad[j.id] && j.l != j.r) {
	    			int mid = (j.l + j.r) / 2;
	    			FOR (k, j.l, mid) q[k] = '1';
	    		}
	    	}

	    	string ans = query(q);

	    	int sum = 0;
	    	for (auto j: segLevel[i]) {
	    		// cout << j.l << " " << j.r << " " << numBad[j.id] << endl;
	    		if (!numBad[j.id]) continue;
	    		if (j.l != j.r) {
		    		int num1 = 0;
		    		FOR (k, j.l - sum, j.r - sum - numBad[j.id]) {
		    			if (ans[k] == '1') num1++;
		    		}
		    		numBad[j.id * 2] = (j.l + j.r) / 2 - j.l + 1 - num1;
		    		numBad[j.id * 2 + 1] = numBad[j.id] - numBad[j.id * 2];
		    	}
	    		sum += numBad[j.id];
	    	}
	    }


	    FOR (i, 0, 11) {
	    	for (auto j: segLevel[i]) {
	    		if (j.l == j.r && numBad[j.id]) {
	    			ansList.pb(j.l);
	    		}
	    	}
	    }

	    sort(all(ansList));

	    for (auto i: ansList) cout << i << " "; cout << endl;
	    cout.flush();

		// cout << cnt << endl;

	    int verdict;

		cin >> verdict;
		if (verdict == -1) {
			exit(0);
		}
	}

    return 0;
}