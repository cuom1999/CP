#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("whereami.in","r",stdin)
#define OUT freopen("whereami.out","w",stdout)
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

// lcp[i] = lcp(sa[i - 1], sa[i]); i = 1 -> n
// sa[0] = n
// lcp[0] = lcp[1] = 0
// lcp(sa[i], sa[j]) = min(lcp[i + 1], ..., lcp[j])

struct SuffixArray {
    vector<int> sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            FOR (i, 0, n - 1) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            FOR (i, 0, n - 1) ws[x[i]]++;
            FOR (i, 1, lim - 1) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            FOR (i, 1, n - 1) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        FOR (i, 1, n - 1) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    SuffixArray sa(s);

    int res = 0;
    for (auto i: sa.lcp) res = max(res, i);
    cout << res + 1 << endl; 

    return 0;
}