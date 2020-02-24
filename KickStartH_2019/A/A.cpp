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

const int MAXN = 100005;
int a[MAXN];

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    int t;
    cin >> t;

    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";

        int sum = 0;
        int n;
        vector<int> cnt(MAXN);

        cin >> n;
    
        FOR (i, 1, n) {
            cin >> a[i];
        }

        int res = 0;
        FOR (i, 1, n) {
            cnt[a[i]]++;
            if (a[i] >= res) sum++;

            while (sum >= res) {
                // cout << i << " " << sum << " " << res << endl;
                sum -= cnt[res];
                res++;
            }
            // cout << i << " " << sum << " " << res << endl;
            cout << res - 1 << " ";
        }
        cout << "\n";
        // cout << endl;
    }



    return 0;
}