/**
 *	Author: Thien
 *	Tre Trau Cop Code
**/

#include <bits/stdc++.h>
#define maxn 1000000
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define se second
#define MOD 1000000007
#define reset(d) memset(d, 0, sizeof d)
#define endl "\n"
#define Task "pearl"

using namespace std;

ll u, v;
int T, x, cnt;
int d[maxn], f[maxn], dd[maxn];

int tinh(int x) {
    int kq = 0;
    while( x > 0 ) {
        kq += (x % 10) * (x % 10);
        x /= 10;
    }
    return kq;
}

void khoitao() {
    int sum = 0;
    for(int i = 2; x = i, cnt = 0, i <= 1539; i++) {
        while( !dd[x] ) {
            d[++cnt] = x;
            dd[x]++;
            x = tinh(x);
        }
        sum += cnt;
        for(int j = 1; j <= cnt; j++) dd[d[j]] = 0;
        if( d[cnt] == 1 ) continue;
        for(int j = 1; j <= cnt; j++) f[d[j]] = 1;
    }
}

bool check(int k) {
    if( k <= 1539 && f[k] ) return true;
    int kq = 0;
    while( k > 0 ) {
        kq += (k % 10) * (k % 10);
        k /= 10;
    }
    return (f[kq] > 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    khoitao();
    cin >> T;
    while( T-- ) {
        cin >> u >> v;
        int res = 0;
        for(int i = u; i <= v; i++) if( check(i) ) res++;
        cout << res << endl;
    }

    return 0;
}
