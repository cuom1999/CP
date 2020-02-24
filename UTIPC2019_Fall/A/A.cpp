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

string s[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> s[i];
    }

    int firstA = INF, firstB = INF;
    char cur = 'C';
    bool men = 1, women = 1;
    int cnt = 0;
    s[n + 1] = "CCC";

    FOR (i, 1, n + 1) {
        if (s[i][0] != cur) {
            if (i > 1 && (!men || !women) && cnt > 1) {
                cout << s[i - 1][0] << endl;
                return 0;
            }
            cnt = 0;
            men = 0;
            women = 0;
            cur = s[i][0];
        }

        cnt++;
        if (s[i][2] == 'M') men = 1;
        if (s[i][2] == 'W') women = 1;

        if (i < n && s[i] == s[i + 1]) {
            if (s[i][0] == 'A') {
                cout << "A" << endl;
                return 0;
            }
            else {
                cout << "B" << endl;
                return 0;
            }
        }
        if (i <= n - 3) {
            bool good = 0;
            FOR (j, 0, 2) {
                if (s[i + j][0] != s[i + 1 + j][0]) {
                    good = 1;
                }
            }
            if (!good) {
                if (s[i][0] == 'A') {
                    cout << "A" << endl;
                    return 0;
                }
                else {
                    cout << "B" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No violation" << endl;



    return 0;
}