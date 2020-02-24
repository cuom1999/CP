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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

bool isPalin(string& s) {
    int n = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[n - i]) return 0;
    }

    return 1;
}

int d[30];

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    ll res = n * 1ll * (n - 1) / 2 + 1;

    FOR (i, 0, n - 1) {
        d[s[i] - 'a']++;
    }

    FOR (i, 0, 25) {
        res -= d[i] * 1ll * (d[i] - 1) / 2;
    }

    cout << res << endl;

    return 0;
}