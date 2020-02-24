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

string s, a[4];

void solve() {
    FOR (i, 1, 3) cout << a[i] << " "; cout << endl;
    int ptr[4];
    FOR (i, 0, 3) ptr[i] = 0;

    while (ptr[0] < s.length()) {
        FOR (i, 1, 3) {
            if (ptr[i] < a[i].size() && s[ptr[0]] == a[i][ptr[i]]) {
                ptr[i]++;
                break;
            }
        }
        ptr[0]++;
    }
    bool good = 1;
    FOR (i, 1, 3) {
        if (ptr[i] < a[i].size()) good = 0;
    }
    if (good) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    cin >> s;

    FOR (z, 1, q) {
        char type;
        int ind;
        cin >> type >> ind;
        if (type == '+') {
            char c;
            cin >> c;
            a[ind] += c;
        }
        else {
            a[ind].pop_back();
        }
        solve();
    }

    return 0;
}