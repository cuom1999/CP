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

#define fname "RPS"
typedef long long ll;
const int N = 2011;

int n, ok, root, cnt, res;
int a[N][N], dx[N][5];
vector <int> ke[N];
void DFS(const int u, const int h){
    if (h == 3){
        if (u == root) ok = 1;
        return;
    }
    dx[u][h] = cnt;
    FOr (i, 0, ke[u].size()){
        int v = ke[u][i];
        if (dx[v][h+1] != cnt)
            DFS(v, h+1);
    }
}
void tao(){
    srand(time(NULL));
    freopen (fname".inp", "w", stdout);
    n = 20;
    cout << n << '\n';
    bool dt[1001];
    memset(dt, 0, sizeof(dt));
    For (i, 1, n) dt[i] = rand()%2;
    For (i, 1, n){
        if (dt[i]) continue;
        For (j, i+1, n){
            if (dt[j]) a[i][j] = 1;
            else a[i][j] = rand()%2;
            a[j][i] = 1-a[i][j];
        }
    }
    For (i, 1, n){
        For (j, 1, n){
            if (i != j && a[i][j] == a[j][i]) a[i][j] = 1-a[i][j];
            cout << a[i][j];
        }
        cout << '\n';
    }
}
int main(){
    //tao();
    freopen (fname".inp", "r", stdin);
    freopen (fname".out", "w", stdout);
    read(n);
    For (i, 1, n)
        For (j, 1, n){
            char ch = getchar();
            while (ch == '\n' || ch == ' ') ch = getchar();
            a[i][j] = ch-'0';
        }
    For (i, 1, n)
        For (j, 1, n)
            if (a[i][j])
                ke[i].push_back(j);
    For (i, 1, n){
        root = i, ok = 0;
        cnt++;
        DFS(i, 0);
        res += ok;
    }
    cout << res;
}
