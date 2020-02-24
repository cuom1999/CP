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

const ll K = 1e9 + 7;
const int MAXN = 100005;

struct Matrix {
    ll coef[2][2];

    Matrix() {
        FOR (i, 0, 1) {
            FOR (j, 0, 1) coef[i][j] = 0;
        }
    }

    void toggle() {
        swap(coef[0][0], coef[1][1]);
        swap(coef[1][0], coef[0][1]);
    }
    Matrix operator* (Matrix& x) {
        Matrix res;
        FOR (i, 0, 1) {
            FOR (j, 0, 1) {
                FOR (k, 0, 1) {
                    res.coef[i][j] += coef[i][k] * x.coef[k][j] % K;
                    res.coef[i][j] %= K;
                }
            }
        }

        return res;
    }

    void print() {
        FOR (i, 0, 1) {
            FOR (j, 0, 1) {
                cout << coef[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


Matrix st[4 * MAXN], a, b, unit;
bool lz[4 * MAXN];
string s;

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == 'A') st[id] = a;
        else st[id] = b;
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2 + 1] * st[id * 2];
}

void down(int id, int l, int r) {
    if (l == r || !lz[id]) return; 
    lz[id * 2] ^= 1;
    lz[id * 2 + 1] ^= 1;
    st[id * 2].toggle();
    st[id * 2 + 1].toggle();
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return;
    }

    if (u <= l && r <= v) {
        lz[id] ^= 1;
        st[id].toggle();
        return;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = st[id * 2 + 1] * st[id * 2];
}

Matrix query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return unit;
    }
    if (u <= l && r <= v) {
        // cout << l << " " << r << endl;
        // st[id].print();
        return st[id];
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    Matrix res = query(id * 2, l, mid, u, v);
    Matrix q = query(id * 2 + 1, mid + 1, r, u, v);
    res = q * res;
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    cin >> s;
    s = '0' + s;

    a.coef[0][0] = 1;
    a.coef[0][1] = 1;
    a.coef[1][1] = 1;
    
    b.coef[0][0] = 1;
    b.coef[1][0] = b.coef[1][1] = 1;;

    unit.coef[0][0] = unit.coef[1][1] = 1;

    build(1, 1, n);

    // query(1, 1, n, 2, 4).print();
    // st[1].print();
    // a.print();
    // b.print();

    FOR (z, 1, q) {
        int type;
        cin >> type;
        if (type == 2) {
            int l, r;
            ll a, b;
            cin >> l >> r >> a >> b;
            Matrix m = query(1, 1, n, l, r);
            // m.print();
            ll resA = m.coef[0][0] * a % K + m.coef[0][1] * b % K;
            resA %= K;
            ll resB = m.coef[1][0] * a % K + m.coef[1][1] * b % K;
            resB %= K;

            cout << resA << " " << resB << "\n";
        }
        else {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
    }
    return 0;
}