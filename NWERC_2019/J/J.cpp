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

const int MAXN = 500005;

int a[500005], p[500005];
int cost[500005];

struct Matrix {
    int coef[3][3];
    Matrix() {
        memset(coef, 0, sizeof(coef));
    }

    Matrix operator* (const Matrix& a) {
        Matrix res;
        FOR (i, 0, 2) {
            FOR (j, 0, 2) {
                FOR (k, 0, 2) {
                    res.coef[i][j] += coef[i][k] * a.coef[k][j]; 
                }
            }
        }
        return res;
    }
    void print() {
        FOR (i, 0, 2) {
            FOR (j, 0, 2) {
                cout << coef[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

Matrix st[4 * MAXN];
Matrix lz[4 * MAXN];
Matrix unit; 

void build(int id, int l, int r) {
    FOR (i, 0, 2) lz[id].coef[i][i] = 1;
    if (l == r) {
        st[id].coef[2][0] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void down(int id, int l, int r) {
    if (l == r) {
        return;
    }
    lz[id * 2] = lz[id] * lz[id * 2];
    lz[id * 2 + 1] = lz[id] * lz[id * 2 + 1]; 
    lz[id] = unit;
}

void update(int id, int l, int r, int u, int v, Matrix& m) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        lz[id] = m * lz[id];
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, m);
    update(id * 2 + 1, mid + 1, r, u, v, m);
}

Matrix getMatrix(int id, int l, int r, int u) {
    if (l == r) {
        // cout << l << " " << r << endl;
        // lz[id].print();
        // st[id].print();
        Matrix res = lz[id] * st[id];
        return res;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    if (u <= mid) return getMatrix(id * 2, l, mid, u);
    return getMatrix(id * 2 + 1, mid + 1, r, u);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> c >> r;

    vector<II> v;
    FOR (i, 1, n) {
        cin >> a[i];
        v.pb({abs(a[i]) + 1, i});
    }
    sort(v.begin(), v.end());

    int ind = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!i || v[i].first != v[i - 1].first) ind++;
        p[v[i].second] = ind;
        cost[ind] = v[i].first;
    }
    
    build(1, 0, n);

    Matrix sw;
    sw.coef[0][1] = sw.coef[1][0] = sw.coef[2][2] = 1;

    Matrix m1;
    m1.coef[0][0] = m1.coef[0][2] = m1.coef[1][0] = m1.coef[2][2] = 1;

    Matrix m2;
    m2.coef[0][1] = m2.coef[1][1] = m2.coef[1][2] = m2.coef[2][2] = 1;

    Matrix m3;
    m3.coef[0][0] = m3.coef[0][2] = m3.coef[1][1] = m3.coef[1][2] = m3.coef[2][2] = 1;

    FOR (i, 0, 2) unit.coef[i][i] = 1;

    FOR (i, 1, n) {
        update(1, 0, n, p[i], n, sw);
           
        if (a[i] < 0) {
            update(1, 0, n, 0, p[i] - 1, m2);
        }   
        if (a[i] > 0) {
            update(1, 0, n, 0, p[i] - 1, m1);
        }
        if (!a[i]) {
            update(1, 0, n, 0, p[i] - 1, m3);
        }

        // cout << i << ": " << endl;
        // FOR (j, 0, n) {
        //     getMatrix(1, 0, n, j).print();
        // }
        // cout << endl;
    }

    ll res = 2e18;
    FOR (i, 0, ind) {
        Matrix m = getMatrix(1, 0, n, i);
        // cout << i << ": " << endl;
        // m.print();
        ll val = min(m.coef[0][0], m.coef[1][0]) * 1ll * r + c * 1ll * cost[i];
        res = min(res, val);
    }

    cout << res << endl;


    return 0;
}