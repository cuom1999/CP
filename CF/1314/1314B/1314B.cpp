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

int a[1 << 18];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    FOR (i, 1, k) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    if (!k) {
        cout << 0 << endl;
        return 0;
    }

    int total = (1 << n);
    int res = 0;
    FOR (round, 1, n) {
        int num = 1 << round;
        int sum = 0;
        int sumHalf = 0;
        FOR (i, 1, total) {
            sum += a[i];
            if (i % (num / 2) == 0 && i % num) {
                sumHalf = sum;
            }

            if (i % num == 0) {
                if (round > 2) {
                    int otherHalf = sum - sumHalf;
                    // cout << round << " " << sumHalf << " " << otherHalf << endl;
                    if (sumHalf >= 2 || otherHalf >= 2) {
                        res += 3;
                    }
                    else if (sumHalf || otherHalf) {
                        res += 2;
                    }
                }
                else if (round == 1) {
                    res += min(3, sum * 2);
                }
                else {
                    res += min(1, sum);
                }
                sum = 0;
            }
        }
    }

    cout << res + 1 << endl;

    return 0;
}