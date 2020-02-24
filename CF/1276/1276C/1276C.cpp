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

map<int, int> cnt;
int s[400005], suf[400005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (auto i: cnt) {
        s[i.second]++;
    } 

    FORD (i, n, 1) {
        suf[i] = suf[i + 1] + s[i];
    }

    int maxArea = -1;
    int indexI = -1, indexJ = -1;

    int total = 0;
    FOR (i, 1, n) {
        total += suf[i];
        FOR (j, i, n / i) {
            if (total >= i * j) {
                if (maxArea < i * j) {
                    maxArea = i * j;
                    indexI = i;
                    indexJ = j;
                }
            }
        }
    }

    cout << maxArea << "\n";
    cout << indexI << " " << indexJ << "\n";

    vector<int> v;
    for (auto i: cnt) {
        for (int j = 0; j < indexI && j < i.second; j++) {
            v.pb(i.first);
        }
    }

    while (v.size() > maxArea) v.pop_back();

    map<int, int> d;
    for (auto i: v) d[i]++;

    vector<II> num;
    for (auto i: d) {
        num.pb({i.second, i.first});
    }
    sort(all(num));
    reverse(all(num));

    v.clear();
    for (auto i: num) {
        FOR (j, 1, i.first) v.pb(i.second);
    }
    vector<II> pos;

    FOR (k, 0, indexJ - 1) {
        FOR (i, 0, indexI - 1) {
            int j = (i + k) % indexJ;
            pos.pb({i + 1, j + 1});
        }
    }
    vector<vector<int>> a(indexI + 1);
    FOR (i, 1, indexI) a[i].resize(indexJ + 1);
    FOR (i, 0, maxArea - 1) {
        a[pos[i].first][pos[i].second] = v[i];
    }

    FOR (i, 1, indexI) {
        FOR (j, 1, indexJ) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}