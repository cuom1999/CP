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

vector<int> c;
int n;

vector<int> calc(vector<int> &a) {
    vector<int> res(2 * n + 1);
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            res[i + j] += a[i] * a[j];
        }
    }
    FOR (i, 0, n * 2) res[i] %= 10;
    return res;
}


void backtrack(int pos, vector<int>& a) {
    if (pos == -1) {
        if (calc(a) == c) {
            reverse(all(a));
            for (auto i: a) cout << i;
            exit(0);
        }
        return;
    }

    // cout << pos << endl;
    // for (auto i: a) cout << i << " "; cout << endl;

    int deg = pos + n;
    ll sum = 0;
    FOR (i, pos + 1, n) {
        int j = deg - i;
        if (pos + 1 <= j && j <= n) {
            sum += a[i] * a[j];
        }
    }

    if (pos == n) {
        FOR (i, 0, 9) {
            if (i * i % 10 == c[deg]) {
                a[n] = i;
                backtrack(pos - 1, a);
            }
        }
    }
    else {
        FOR (i, 0, 9) {
            if ((2 * a[n] * i + sum) % 10 == c[deg]) {
                a[pos] = i;
                backtrack(pos - 1, a);
            }
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (auto i: s) {
        c.pb(i - '0');
    }
    reverse(all(c));

    n = c.size();
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    n = (n - 1) / 2;
    vector<int> a(n + 1);
    backtrack(n, a);
    cout << -1 << endl;
    return 0;
}