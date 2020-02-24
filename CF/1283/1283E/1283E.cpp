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

int dpMin[200005][2][2], dpMax[200005][2][2];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    FOR (i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // find min
    vector<int> posMin(n + 2);
    int minVal = 0;
    FOR (i, 1, n) {
        if (!cnt[i]) continue;
        if (posMin[i] || posMin[i - 1]) continue;
        posMin[i + 1] = 1;
        minVal++;
    }

    // find max
    vector<int> posMax(n + 2);
    FOR (i, 1, n) {
        if (!cnt[i]) continue;
        if (cnt[i] >= 3) {
            posMax[i - 1] = posMax[i] = posMax[i + 1] = 1;
        }
        if (cnt[i] == 2) {
            if (!posMax[i - 1]) {
                posMax[i - 1] = posMax[i] = 1;
            }
            else {
                posMax[i] = posMax[i + 1] = 1;
            }
        }
        if (cnt[i] == 1) {
            if (!posMax[i - 1]) posMax[i - 1] = 1;
            else if (!posMax[i]) posMax[i] = 1;
            else posMax[i + 1] = 1;
        }
    }
    int maxVal = 0;
    for (auto i: posMax) maxVal += i;
    cout << minVal << " " << maxVal; 

    return 0;
}