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

bitset<55> a[100005], res;

map<ll, int> vs;

ll solve(int n, int m) {
    FOR (i, 1, n) {
        ll val = 0;
    
        FOR (j, 0, m - 1) {
            if (a[i][j] == 1) {
                val += (1LL << j);
            }
        }
        vs[val] = 1;
    }
    FOR (i, 0, (1LL << m) - 1) {
        if (!vs[i]) {
            return i;
        }
    }
    return -1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
        string s;
        cin >> s;
        FOR (j, 0, m - 1) {
            a[i][j] = s[j] - '0';
        }
    }
    string s;
    cin >> s;
    if (s == "LN" && solve(n, m) == -1) {
        return 0;
    }
    if (s.size() != m) {
        cout << "Output phai chua " << m << " ky tu" << endl;
        exit(0);
    }
    FOR (j, 0, m - 1) {
        if (s[j] != '0' && s[j] != '1') {
            cout << "Output chua ky tu khong phai 0 hoac 1" << endl;
            exit(0); 
        }
        res[j] = s[j] - '0';
    }

    FOR (i, 1, n) {
        bitset<55> val = res ^ a[i];
        if (val.count() == m) {
            cout << "Hoc sinh " << i << " duoc 0 diem" << endl;
            exit(0);
        }
    }
    return 0;
}