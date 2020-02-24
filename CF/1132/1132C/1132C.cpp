#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

int s[5005], l[5005], r[5005], a[5005];
int n, q;
int c[5005];

int solve(int index) {
    FOR (i, l[index], r[index]) {
        a[i]--;
    }

    int sum = 0;

    FOR (i, 1, n) {
        if (a[i] == 1) {
            c[i] = 1;
        }
        else {
            c[i] = 0;
        }

        if (a[i]) sum++;
    }

    s[0] = 0;

    FOR (i, 1, n) {
        s[i] = s[i - 1] + c[i];
    }

    int res = 0;

    FOR (i, 1, q) {
        if (i == index) continue;

        res = max(res, sum - (s[r[i]] - s[l[i] - 1]));
    }

    FOR (i, l[index], r[index]) {
        a[i]++;
    }

    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> q;

    FOR (i, 1, q) {
        cin >> l[i] >> r[i];
        s[r[i] + 1]--;
        s[l[i]]++;
    }

    FOR (i, 1, n) {
        a[i] = a[i - 1] + s[i];
    }

    int res = 0;

    FOR (i, 1, q) {
        res = max(res, solve(i));
    }

    cout << res << endl;


    return 0;
}