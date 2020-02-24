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

ll w;
ll pw10[16];

// count numbers in [l, r] that % w <= remainder
ll countNum(ll l, ll r, ll remainder) {
    if (l / w == r / w) {
        ll l1 = l % w;
        ll r1 = r % w;
        r1 = min(r1, remainder);
        return max(0LL, r1 - l1 + 1);
    }

    ll u = l / w + 1;
    ll v = r / w - 1;

    ll res = max(0LL, (v - u + 1) * (remainder + 1));
    ll l1 = l % w;
    if (l1 <= remainder) {
        res += remainder - l1 + 1;
    }
    ll r1 = r % w;
    if (r1 >= remainder) {
        res += remainder + 1;
    }
    else {
        res += r1 + 1;
    }
    return res;
}

ll countDigit(ll remainder) {
    if (remainder < 0) return 0;
    ll res = 0;
    FOR (i, 0, 14) {
        res += countNum(pw10[i], pw10[i + 1] - 1, remainder) * (i + 1);
    }
    res += 16 * countNum(pw10[15], pw10[15], remainder);
    return res;
}

// <= r and % w == remainder
ll countDigitRange(ll r, ll remainder) {
    ll _log10 = 15;
    FOR (i, 0, 15) {
        if (pw10[i] <= r) {
            _log10 = i;
        }
        else break;
    }
    ll res = 0;
    FOR (i, 0, _log10 - 1) {
        res += (countNum(pw10[i], pw10[i + 1] - 1, remainder) - countNum(pw10[i], pw10[i + 1] - 1, remainder - 1)) * (i + 1);
    }

    res += (countNum(pw10[_log10], r, remainder) - countNum(pw10[_log10], r, remainder - 1)) * (_log10 + 1);
    return res;
}

int digit(int pos, ll x) {
    return x / pw10[pos] % 10;
}

int solve(ll k) {
    ll lower = 0, upper = w - 1;
    while (lower < upper) {
        ll mid = (lower + upper) / 2;
        ll cnt = countDigit(mid);
        if (cnt >= k) {
            upper = mid;
        }
        else {
            lower = mid + 1;
        }
    }
    ll remainder = lower;
    // cout << countDigit(remainder) << endl;
    k -= countDigit(remainder - 1);

    lower = 1, upper = 1e15;
    while (lower < upper) {
        ll mid = (lower + upper) / 2;
        if (countDigitRange(mid, remainder) >= k) {
            upper = mid;
        }
        else lower = mid + 1;
    }
    // cout << remainder << " " << lower << endl;
    // cout << countDigitRange(remainder, remainder) << endl;
    ll m = countDigitRange(lower, remainder) - k;
    // cout << lower << endl;
    // cout << digit(m, lower) << endl;
    return digit(m, lower);
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    pw10[0] = 1;
    FOR (i, 1, 15) {
        pw10[i] = pw10[i - 1] * 10;
    }

    int t;
    cin >> t;
    FOR (z, 1, t) {
        ll k;
        cin >> w >> k;

        // FOR (i, 1, k) cout << solve(i);
        // cout << endl;
        cout << solve(k) << "\n";
    }

    return 0;
}