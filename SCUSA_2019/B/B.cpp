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

int cnt[366];
ld logfact[366];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;

    ld res = 0;
    FOR (i, 1, 365) {
        logfact[i] = logfact[i - 1] + log10(i);
    }

    
    FOR (i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
        sum += x;
        res -= logfact[x];
    }
    res += logfact[sum];

    
    FOR (i, 1, n) {
        res += log10(366 - i);
    }
    FOR (i, 1, 365) {
        res -= logfact[cnt[i]];
    }
    res -= log10(365) * sum;

    cout << fixed << setprecision(8) << res << endl;

    return 0;
}