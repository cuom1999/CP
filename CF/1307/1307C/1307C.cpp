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

ll cnt[505];
string s;
int n;

ll count(char a, char b) {
    ll cur = 0;
    ll res = 0;
    FOR (i, 0, n - 1) {
        if (s[i] == a) {
            cur++;
        }
        if (s[i] == b) {
            res += cur;
        }
    }
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);  
    cin >> s;

    n = s.size();

    FOR (i, 0, n - 1) {
        cnt[s[i]]++;
    } 

    ll res = 0;
    FOR (i, 'a', 'z') {
        res = max(res, cnt[i]);
        res = max(res, cnt[i] * (cnt[i] - 1) / 2);
    }

    FOR (i, 'a', 'z') {
        FOR (j, 'a', 'z') {
            if (i != j) {
                res = max(res, count(i, j));
            }
        }
    }
    cout << res << endl;

    return 0;
}