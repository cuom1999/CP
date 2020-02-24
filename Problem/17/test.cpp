#include <bits/stdc++.h>
#define base 1000000007LL
#define ll long long
#define X first
#define Y second
#define pb push_back
#define EPS 1e-9
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
using namespace std;
typedef pair<int, int> II;
typedef pair<II, int> III;

ll nhan(ll a, ll b, ll mod)
{
    if (b<0) {b=-b; a=-a;}
    if (b == 0) return 0;
    if (b == 1) return a%mod;
    ll g = nhan(a, b/2, mod);
    if (b%2) return (g+g+a)%mod;
    return (g+g)%mod;
}

ll mu(ll a, ll b, ll mod)
{
    if (b == 0) return 1%mod;
    if (b == 1) return a%mod;
    ll g = mu(a, b/2, mod);
    if (b%2) return nhan(nhan(g, g, mod), a, mod);
    return nhan(g, g, mod);
}

ll getMod(ll u, ll mod)
{
    if (u >= 0) return u%mod;
    u = u % mod + mod;
    return u;
}

ll x, y, d;

void extendedEuclid(ll a, ll b)
{
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a % b);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
} // 25x+18y= 839 // store x, y, and d as global variables

ll inv(ll a, ll mod)
{
    extendedEuclid(a, mod);
    x %= mod;
    return x;
}

vector<ll> convert(ll a, ll b)
{
    vector<ll> res;
    while (a) {
        ll c = a%b;
        a /= b;
        res.pb(c);
    }
    reverse(all(res));
    return res;
}

ll getRes(ll a, ll b, ll B, ll n)
{
    a %= b;
    FOR(i,1,n-1) a = nhan(a, B, b);
    ll dau = 0, cuoi = B-1;
    while (dau <= cuoi) {
        ll mid = (dau+cuoi) / 2;
        if ((long double) a / b >= (long double) mid / B) dau = mid+1;
        else cuoi = mid-1;
    }
    return cuoi;
}

ll a, b, B, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int numt;
    cin>>numt;
    while (cin >> n >> a >> b >> B) {

        // corner case ?!
        if (B == 1) {
            cout << 0;
            continue;
        }

        // rut gon
        ll x = __gcd(a, b);
        a /= x; b /= x;

        // n nho
        if (n <= 60) {
            cout << getRes(a, b, B, n) << endl;
        }
        // n lon
        else {
            // tinh g
            ll g = 1, bphay;
            vector<ll> Bx;
            ll N = n;
            if (0) {
                g = __gcd(b, B);
                bphay = b / g;
                N--;
                Bx.pb(B/g);
            }
            else {
                bphay = b;
                ll i = 1;
                while (1) {
                    ll k = __gcd(bphay, B);
                    if (k == 1) break;
                    g *= k;
                    Bx.pb(B/k);
                    N--;
                    bphay /= k;
                    i++;
                }
            }
            //cout<<bphay<<" "<<N<<endl;
            // tinh r
            ll r = nhan(mu(B, N, bphay), a, bphay);
            FOR(i,0,sz(Bx)-1) r = nhan(r, Bx[i], bphay);
            //cout<<r<<" "<<bphay<<endl;
            ll q = nhan(getMod(-r, B), inv(bphay, B), B);
            cout << (q+B)%B <<endl;

        }
    }
    return 0;
}
