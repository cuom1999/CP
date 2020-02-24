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

#define fname "DANCE"
typedef long long ll;
const int N = 7e4+11;

int n, m, l, W, res, sum;
int a[N][12], b[N][12];
void tao(){
    srand(time(NULL));
    freopen (fname".inp", "w", stdout);
    n = 7000; l = 3000; m = 10;
    W = 910000;
    cout << n << ' ' << l << ' ' << m << ' ' << W << '\n';
    For (i, 1, m){
        For (j, 1, n)
            cout << rand()%10+1 << ' ';
        cout << '\n';
    }
    For (i, 1, m){
        For (j, 1, l)
            cout << rand()%10+1 << ' ';
        cout << '\n';
    }
}
int main(){
    //tao();
    freopen (fname".inp", "r", stdin);
    freopen (fname".out", "w", stdout);
    read(n); read(l); read(m); read(W);
    For (i, 1, m) For (j, 1, n) read(a[j][i]);
    For (i, 1, m) For (j, 1, l) read(b[j][i]);
    For (i, l, n){
        sum = 0;
        For (j, 1, l)
            For (k, 1, m)
                sum += (a[i-l+j][k]*b[j][k]);
        if (sum >= W) res++;
    }
    cout << res;
}
