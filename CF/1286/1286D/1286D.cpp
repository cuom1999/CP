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

const ll MOD = 998244353;

ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD; 
}

struct Proton {
    ll x, v, p;
} proton[100005];

struct Collision {
    ll dist, v;
    int pos, dir1, dir2;
};

void debug(ll x) {
    FOR (b, 1, 10000) {
        ll a = x * b % MOD;
        if (a <= 10000) {
            cout << a << "/" << b << " ";
            return;
        }
    }
}

struct Matrix {
    ll coef[2][2];
    Matrix() {
        memset(coef, 0, sizeof(coef));
    }
    ll sumCoef() {
        ll res = 0;
        FOR (i, 0, 1) {
            FOR (j, 0, 1) {
                res = (res + coef[i][j]) % MOD;
            }
        }
        return res;
    }
} st[400005];

ll inv[100005][2];

void merge(int id, int mid) {
    st[id] = Matrix();
    FOR (i, 0, 1) {
        FOR (j, 0, 1) {
            FOR (k, 0, 1) {
                st[id].coef[i][j] += st[id * 2].coef[i][k] * st[id * 2 + 1].coef[k][j] % MOD * inv[mid + 1][k] % MOD;
                st[id].coef[i][j] %= MOD;
            }
        }
    }
}



void build(int id, int l, int r) {
    if (l == r) {
        ll u = proton[l].p;
        ll v = proton[l + 1].p;
        st[id].coef[0][0] = (1 - u + MOD) * (1 - v + MOD) % MOD;
        st[id].coef[0][1] = (1 - u + MOD) * v % MOD;
        st[id].coef[1][0] = u * (1 - v + MOD) % MOD;
        st[id].coef[1][1] = u * v % MOD;
        // cout << id << " " << l << " " << r << " " << st[id].sumCoef() << endl;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(id, mid);
    // cout << id << " " << l << " " << r << " " << st[id].sumCoef() << endl;
}

void update(int id, int l, int r, int u, int i, int j) {
    if (l == r) {
        st[id].coef[i][j] = 0;
        return;
    }

    int mid = (l + r) / 2;
    if (u <= mid) update(id * 2, l, mid, u, i, j);
    else update(id * 2 + 1, mid + 1, r, u, i, j);
    merge(id, mid);
}

ll query() {
    ll res = 0;
    FOR (i, 0, 1) {
        FOR (j, 0, 1) {
            res = (res + st[1].coef[i][j]) % MOD;
        }
    }
    return res;
}

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll rev100 = pw(100, MOD - 2);
    FOR (i, 1, n) {
        cin >> proton[i].x >> proton[i].v >> proton[i].p;
        proton[i].p = proton[i].p * rev100 % MOD;
        inv[i][1] = pw(proton[i].p, MOD - 2);
        inv[i][0] = pw(1 + MOD - proton[i].p, MOD - 2);
    }

    vector<Collision> collision;

    FOR (i, 1, n - 1) {
        Collision c1 = {0, 0, i, 0, 0};
        Collision c2 = c1;

        c1.dist = c2.dist = proton[i + 1].x - proton[i].x;
        c1.v = proton[i].v + proton[i + 1].v;
        c1.dir1 = 1, c1.dir2 = 0;
        collision.pb(c1);

        c2.v = abs(proton[i + 1].v - proton[i].v);
        if (proton[i].v > proton[i + 1].v) {
            c2.dir1 = 1;
            c2.dir2 = 1;
        }
        if (proton[i].v < proton[i + 1].v) {
            c2.dir1 = c2.dir2 = 0;
        }
        if (c2.v) {
            collision.pb(c2);
        }
    }

    sort(all(collision), [](Collision a, Collision b) {
        return a.dist * b.v < b.dist * a.v;
    });

    build(1, 1, n - 1);
    // cout << query() << endl;
    // return 0;
    ll last = 1;
    ll res = 0;
    for (auto c: collision) {
        ll time = c.dist * pw(c.v, MOD - 2) % MOD;
        update(1, 1, n - 1, c.pos, c.dir1, c.dir2);
        ll newLast = query();
        // cout << newLast << endl;
        // cout << c.pos << " " << c.dir1 << " " << c.dir2 << endl;
        // return 0;
        ll prob = (last - newLast + MOD) % MOD;
        // cout << c.pos << " " << newLast << " " << prob << endl;
        last = newLast;
        prob %= MOD;
        res = (res + prob * time % MOD) % MOD;
    }

    cout << res << endl;
    return 0;
}