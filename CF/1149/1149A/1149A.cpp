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

    int cnt1 = 0, cnt2 = 0;
    FOR (i, 1, n) {
        int x;
        cin >> x;
        if (x == 1) cnt1++;
        else cnt2++;
    }

    if (cnt1 == 0) {
        FOR (i, 1, n) cout << 2 << " ";
    }
    else if (cnt2 == 0) {
        FOR (i, 1, n) cout << 1 << " ";
    }
    else {
        cout << 2 << " " << 1 << " ";
        cnt1--;
        cnt2--;
        FOR (i, 1, cnt2) cout << 2 << " ";
        FOR (i, 1, cnt1) cout << 1 << " ";
    }
    return 0;
}