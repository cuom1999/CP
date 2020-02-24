#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("lineup.in","r",stdin)
#define OUT freopen("lineup.out","w",stdout)
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

typedef pair < string, string> SS;
typedef pair < ll, ll > pll;

const int SIZE = 8;
vector<string> name = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

vector<SS> queries;

bool check(vector<string>& order) {
    for (auto i: queries) {
        int pos1 = -10, pos2 = 10;
        for (int j = 0; j < order.size(); j++) {
            if (order[j] == i.first) pos1 = j;
            if (order[j] == i.second) pos2 = j;
        }
        if (abs(pos1 - pos2) != 1) return 0;
    }
    return 1;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        string s[6];
        FOR (i, 0, 5) cin >> s[i];
        queries.pb({s[0], s[5]});
    }
    int p[9];
    FOR (i, 1, 8) p[i] = i;

    vector<string> res;
    
    do {
        vector<string> cur;
        FOR (i, 1, SIZE) {
            cur.pb(name[p[i] - 1]);
        }

        if (check(cur)) {
            if (res.size() && res > cur) {
                res = cur;
            }
            if (!res.size()) {
                res = cur;
            }
        }

    } while(next_permutation(p + 1, p + SIZE + 1));

    for (auto i: res) cout << i << "\n";

    return 0;
}