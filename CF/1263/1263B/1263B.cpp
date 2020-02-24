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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        map<string, int> cnt;
        vector<int> tmp;
        string a[12];

        int n;
        cin >> n;
        FOR (i, 1, n) {
            string x;
            cin >> x;
            a[i] = x;
            if (cnt.count(x) == 0) cnt[x]++;
            else tmp.pb(i);
        }
        cout << tmp.size() << "\n";
        for (auto i: tmp) {
            FOR (j, 0, 9) {
                string val = a[i];
                val.pop_back();
                val += (char) (j + '0');
                if (cnt.count(val) == 0) {
                    a[i] = val;
                    cnt[val] = 1;
                    break;
                }
            }
        }
        FOR (i, 1, n) cout << a[i] << "\n";
    }
    return 0;
}