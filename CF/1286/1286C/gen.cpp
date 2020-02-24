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

string s = "aabc";
    
void writeSeg(int l, int r) {
    vector<string> v;
    FOR (i, l - 1, r - 1) {
        FOR (j, i, r - 1) {
            string tmp;
            FOR (k, i, j) {
                tmp += s[k];
            }
            v.pb(tmp);
        }
    }
    cout << v.size() << endl;
    for (auto i: v) cout << i << endl;
}

int main()
{
    freopen("input.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n = s.size();
    cout << n << "\n";
    writeSeg(1, n);
    writeSeg(1, n / 2);
    writeSeg(1, n / 2 - 1);

    return 0;
}