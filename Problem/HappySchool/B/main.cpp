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

// n: so tap hop (n <= 5)
// moi tap hop <= 1e5
// moi so <= 1e6

int cnt[1000005];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<int> v[6];
    FOR (i, 1, n) {
        int m;
        cin >> m;
        FOR (j, 1, m) {
            int x;
            cin >> x;
            assert(x <= 1e6);
            v[i].insert(x);
        }
        for (auto j: v[i]) {
            cnt[j]++;
        }
    }

    FOR (i, 1, 1000000) {
        if (cnt[i] == n) {
            cout << i << " ";
        }
    }
    cout << "\n";
    FOR (i, 1, 1000000) {
        if (cnt[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';


    return 0;
}