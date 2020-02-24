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

    int n;
    cin >> n;
    
    vector<vector<int>> cnt(32);
    vector<int> a(n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
        FOR (j, 0, 30) {
            if ((1 << j) & a[i]) {
                cnt[j].pb(i);
            }
        }
    }

    int st = -1;
    FORD (j, 30, 0) {
        if (cnt[j].size() == 1) {
            st = j;
            break;
        }
    }

    if (st != -1) {
        int pos = cnt[st][0];
        swap(a[pos], a[1]);
    }
    FOR (i, 1, n) cout << a[i] << " ";
    return 0;
}