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

const ll MOD = 1e9 + 7;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

ll pw(ll a, ll n) {
    if (n == 0) {
        return 1;
    }

    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

struct BIT {
    ll fen[200005];
    int k;
    BIT() {
        memset(fen, 0, sizeof(fen));
    }

    void reset() {
        memset(fen, 0, sizeof(fen));
    }

    void add(int u, ll v) {
        ll val = pw(v, k);
        for (int i = u; i <= 200000; i += i & -i) {
            fen[i] = (fen[i] + val) % MOD;
        }
    }

    ll getSum(int u) {
        ll res = 0;
        for (int i = u; i; i -= i & -i) {
            res = (res + fen[i]) % MOD;
        }
        return res;
    }
};

void compress(vector<II> &a) {
    vector<II> v;
    for (int i = 0; i < a.size(); i++) {
        v.pb({a[i].first, i + 1});
        v.pb({a[i].second, -(i + 1)});
    }
    sort(all(v));
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!i || v[i].first != v[i - 1].first) {
            cnt++;
        }
        if (v[i].second > 0) {
            a[v[i].second - 1].first = cnt;
        }
        else {
            a[-v[i].second - 1].second = cnt;
        }
    }
}

ll res[100005][10][2];
ll coef[10];
int N = 9;

struct Triple {
    int x, y, pos;
    bool operator< (Triple t) {
        if (x != t.x) return x < t.x;
        if (y != t.y) return y < t.y;
        return pos < t.pos;
    }
};

void solve(vector<II> &a, int type) {
    BIT fen[10];
    FOR (i, 0, N) {
        fen[i].k = coef[i];
    }

    int n = a.size();
    vector<Triple> v;

    FOR (i, 0, n - 1) {
        v.pb({a[i].first, a[i].second, i + 1});
    }
    for (auto i: v) cout << i.pos << " "; cout << endl;
    sort(all(v));
    for (auto i: v) {
        FOR (j, 0, N) {
            res[i.pos][j][type] += fen[j].getSum(i.x - 1);
            res[i.pos][j][type] %= MOD;
            fen[j].add(i.y, i.pos + 100);
        }
    }
    FOR (i, 0, N) fen[i].reset();

    v.clear();
    FOR (i, 0, n - 1) {
        v.pb({a[i].second, a[i].first, i + 1});
    }
    sort(all(v));
    reverse(all(v));
    // if (!type) {
    //     for (auto i:v) cout << i.x << " " << i.y << endl;
        // cout << res[1][0][type] << endl;
    // }
    for (auto i: v) {
        FOR (j, 0, N) {
            res[i.pos][j][type] += (fen[j].getSum(200000) - fen[j].getSum(i.x) + MOD);
            res[i.pos][j][type] %= MOD;

            fen[j].add(i.y, i.pos + 100);
        }
    }
}   

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 0, N) {
        coef[i] = Rand(1, MOD - 1);
    }

    int n;
    cin >> n;
    // n = 100000;

    vector<II> a(n), b(n);

    FOR (i, 0, n - 1) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        // a[i] = b[i] = {1, 10};
    }

    compress(a);
    compress(b);

    solve(a, 0);
    solve(b, 1);

    FOR (i, 1, n) {
        FOR (j, 0, N) {
            // cout << i << " " << j << " " << res[i][j][0] << " " << res[i][j][1] << endl;
            if (res[i][j][0] != res[i][j][1]) {
                cout << "NO";
                return 0;
            }
        }
    }    
    cout << "YES";



    return 0;
}