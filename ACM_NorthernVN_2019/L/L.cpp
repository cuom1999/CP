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


map<ll, ll> cnt;
ll a[2505];

int main() {
    //IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[sq(a[i])]++;
    }

    sort (a + 1, a + n + 1);

    int cntN = 0;
    int cntV = 0;
    int cntT = 0;
    ll numAcute = 0;
    ll numRight = 0;
    ll numScale = 0;

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            ll x = a[i];
            ll y = a[j];

            int first = j;
            int last = n;
            while (first != last) {
                int mid = (first + last+ 1) / 2;
                if (a[i] + a[j] > a[mid]) {
                    first = mid;
                }
                else {
                    last = mid - 1;
                }
            }
            int d = first;

            first = j;
            last = d;
            while (first < last) {
                int mid = (first + last + 1) / 2;
                if (x * x + y * y > a[mid] * a[mid]) {
                    first = mid;
                }
                else {
                    last = mid - 1;
                }
            }

            int c = first;
            // cout << i << " " << j << ": ";
            // cout << c << " " << d << endl;
            numAcute += c - j;
            // numRight += max(0, c - 1 - (b + 1) + 1);
            if (cnt.count(x * x + y * y)) numRight += cnt[x * x + y * y];

            numScale += d - c;
        }
    }

    cout << numAcute << " " << numRight << " " << numScale - numRight << "\n";
    return 0;
}
