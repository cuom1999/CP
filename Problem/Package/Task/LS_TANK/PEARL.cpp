#include <bits/stdc++.h>

template <typename T> inline void read(T &x){
    bool b = 0; char c;
    while (!isdigit(c = getchar()) && c!= '-');
    if (c == '-') c = getchar(), b = 1;
    x = c-48;
    while (isdigit(c = getchar())) x = (x<<3)+(x<<1)+c-48;
    if (b) x = -x;
}

using namespace std;
#define For(i, a, b) for (int i = a; i <= b; i++)
#define FOr(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for (int i = a; i >= b; i--)

#define fname "PEARL"
typedef int64_t ll;
const int N = 2011;

int n, g[N], c[N];
ll res, f[22][N][2];
bool dt[N];
void try1(const int x){
    if (dt[x]) return;
    dt[x] = 1;
    int tg = x, xm = 0;
    while (tg > 0){
        xm += (tg%10)*(tg%10);
        tg /= 10;
    }try1(xm);
    g[x] = g[xm];
}
void change(ll p){
    n = 0;
    while (p > 0){
        c[++n] = p%10;
        p /= 10;
    }
    reverse(c+1, c+n+1);
}
void dp(const int i, const int s, const int ok){
    if (f[i][s][ok] >= 0) return;
    f[i][s][ok] = 0;
    if (i > n){
        f[i][s][ok] = g[s];
        return;
    }
    if (!ok){
        For (x, 0, c[i]-1){
            int sm = s+x*x;
            dp(i+1, sm, 1);
            f[i][s][0] += f[i+1][sm][1];
        }
        int sm = s+c[i]*c[i];
        dp(i+1, sm, 0);
        f[i][s][0] += f[i+1][sm][0];
    }
    else
        For (x, 0, 9){
            int sm = s+x*x;
            dp(i+1, sm, 1);
            f[i][s][1] += f[i+1][sm][1];
        }
}
void tao(){
    freopen (fname".inp", "w", stdout);
    int ntest =  100;
    cout << 100 << '\n';
    For (i, 1, 100)
        cout << 1 << " " << 1000000000000000000 << '\n';
}
int main(){
    //tao();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen (fname".inp", "r", stdin);
    freopen (fname".out", "w", stdout);
    n = 2000; g[1] = 1;
    For (i, 2, n) try1(i);
    int ntest; cin >> ntest;
    while (ntest--){
        ll a, b; cin >> a >> b;
        change(b);
        memset(f, -1, sizeof(f));
        dp(1, 0, 0);
        res = f[1][0][0];
        a--; change(a);
        memset(f, -1, sizeof(f));
        dp(1, 0, 0);
        cout << (b-a)-(res-f[1][0][0]) << '\n';
    }
}
