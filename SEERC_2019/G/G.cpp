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

int n, m, h;
int a[105][105], b[105][105];

struct Data {
    Data(int x, int y, int z): x(x), y(y), z(z) {}
    int x, y, z;
};


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> h;

    FOR (i, 0, n - 1) {
        FOR (j, 0, m - 1) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    FOR (i, 0, n - 1) {
        FOR (j, 0, h - 1) {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    vector<Data> maxRes, minRes;
    FOR (i, 0, n - 1) {
        vector<int> mVals, hVals;
        FOR (j, 0, m - 1) {
            if (a[i][j]) {
                mVals.pb(j);
            }
        }
        FOR (j, 0, h - 1) {
            if (b[i][j]) {
                hVals.pb(j);
            }
        }
        if (!mVals.size() && !hVals.size()) continue;
        if (!mVals.size() || !hVals.size()) {
            cout << -1;
            return 0;
        }
        for (auto j: mVals) {
            for (auto k: hVals) {
                maxRes.pb(Data(i, j, k));
            }
        }

        if (mVals.size() <= hVals.size()) {
            int diff = hVals.size() - mVals.size();
            FOR (j, 0, diff) {
                minRes.pb(Data(i, mVals[0], hVals[j]));
            }
            for (int j = 1; j < mVals.size(); j++) {
                minRes.pb(Data(i, mVals[j], hVals[j + diff]));
            }
        }
        else {
            int diff = mVals.size() - hVals.size();
            for (int j = 0; j <= diff; j++) {
                minRes.pb(Data(i, mVals[j], hVals[0]));
            }   
            for (int j = diff + 1; j < mVals.size(); j++) {
                minRes.pb(Data(i, mVals[j], hVals[j - diff]));
            }
        }
    }
    cout << maxRes.size() << "\n";
    for (auto i: maxRes) {
        cout << i.x << " " << i.y << " " << i.z << "\n";
    }
    cout << minRes.size() << "\n";
    for (auto i: minRes) {
        cout << i.x << " " << i.y << " " << i.z << "\n";
    }

    return 0;
}