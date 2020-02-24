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

vector<int> a[5];
vector<int> v;
string s[121], S;

char ask(int i, int pos) {
	cout << (i - 1) * 5 + pos << endl;
	char c;
	cin >> c;
	return c;
	// return S[(i - 1) * 5 + pos - 1];
}

void gen() {
	int a[6];
	FOR (i, 1, 5) a[i] = i;

	int num = 0;
	do {
		num++;
		FOR (i, 1, 5) {
			s[num] += (char) (a[i] + 'A' - 1);
		}
	} while (next_permutation(a + 1, a + 6));

	vector<int> vec;
	FOR (i, 1, 120) vec.pb(i);
	random_shuffle(all(vec));

	FOR (i, 0, 118) {
		S += s[vec[i]];
	} 
	cout << s[vec[119]] << endl;
}

int dd[6];

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	// srand(time(NULL));
	int t, f;
	cin >> t >> f;
	FOR (z, 1, t) {
		// gen();
		FOR (i, 0, 4) dd[i] = 0;
		FOR (i, 1, 119) {
			v.pb(i);
		}
		string res;
		FOR (i, 1, 5) {
			FOR (j, 0, 4) a[j].clear();

			for (auto j: v) {
				char c = ask(j, i);
				a[c - 'A'].pb(j);
			}
			FOR (j, 0, 4) {
				if (!dd[j] && a[j].size() < (v.size() + 1) / (6 - i)) {
					v = a[j];
					res += (char) (j + 'A');
					dd[j] = 1;
					break;
				}
			}
		}
		cout << res << endl;
		char verdict;
		cin >> verdict;
	}


	return 0;
}