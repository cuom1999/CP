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
typedef pair < II, int > III;

int a[105], used[105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        used[a[i]] = 1;
    }
    int even = 0, odd = 0;

    FOR (i, 1, n) {
        if (!used[i]) {
            if (i % 2 == 0) even++;
            else odd++;
        }
    }

    vector<II> v;
    int last = 0;
    int ori = 0;
    FOR (i, 1, n) {
        if (a[i] == 0 && a[i - 1]) {
            last = i - 1;
        }
        if (a[i] && a[i - 1] == 0 && i > 1) {
            v.pb({last, i});
        }
        if (a[i] && a[i - 1]) {
            if (abs(a[i] - a[i - 1]) % 2) ori++;
        }
    }
    if (a[n] == 0) {
        v.pb({last, 0});
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (v.size() == 1 && v[0].first == v[0].second && v[0].first == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> cnt(2), cntBound(2);
    int cntMix = 0;
    for (auto i: v) {
        if (!i.first || !i.second) {
            int pos = i.first + i.second;
            if (!i.first) {
                cntBound[a[pos] % 2] += pos - 1;
            }
            else {
                cntBound[a[pos] % 2] += n - pos;
            }
        }
        else {
            if ((a[i.first] - a[i.second]) % 2 == 0) {
                cnt[a[i.first] % 2] += i.second - i.first - 1;
            }
            else {
                cntMix++;
            }
        }
    }
    int res = cntMix;
    if (cnt[0] > even) {
        res += 2;
    }
    if (cnt[1] > odd) {
        res += 2;
    }
    cout << res + ori << endl;

    return 0;
}