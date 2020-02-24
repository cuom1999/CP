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
    string s;
    cin >> s;
    int n = s.size();

    vector<int> a(n + 1);
    FOR (i, 1, n) {
        a[i] = a[i - 1];
        if (s[i - 1] == '1') a[i]++;
    }

    ll res = 0;
    FOR (i, 0, n) {
        FOR (j, 0, i - 1) {
            if (a[i] != a[j] && (i - j) % (a[i] - a[j]) == 0) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}