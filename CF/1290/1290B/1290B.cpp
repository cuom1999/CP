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

int a[200005][26];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    int q;
    cin >> s >> q;
    int n = s.length();
    s = '0' + s;

    int cnt = 0;
    FOR (i, 1, n) {
        FOR (j, 0, 25) {
            a[i][j] = a[i - 1][j];
            if ((j + 'a') == s[i]) {
                a[i][j]++;
            }
        }
    }

    FOR (z, 1, q) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }

        char special = -1;
        int cnt = 0;
        FOR (i, 0, 25) {
            int val = a[r][i] - a[l - 1][i];
            if (val) {
                cnt++;
            }
            if (val == 1) {
                special = i + 'a';
            }
        }   
        if (cnt == 1 || ((cnt == 2) && (s[l] == s[r]))) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }

    }

    return 0;
}