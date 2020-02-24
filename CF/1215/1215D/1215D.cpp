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



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = '0' + s;

    int a = 0, b = 0;
    int sum = 0;

    FOR (i, 1, n) {
        if (s[i] == '?') {
            if (i <= n / 2) a++;
            else b++;
        }
        else {
            if (i <= n / 2) {
                sum += s[i] - '0';
            }
            else {
                sum -= s[i] - '0';
            }
        }
    }
    int u = min(a, b);
    a -= u;
    b -= u;
        
    if (sum >= 0) {
        if (a == 0 && sum == 9 * (b / 2)) {
            cout << "Bicarp\n";
        } 
        else {
            cout << "Monocarp\n";
        }
    }
    else {
        if (b == 0 && -sum == 9 * (a / 2)) {
            cout << "Bicarp\n";
        }        
        else {
            cout << "Monocarp\n";
        }
    }
    return 0;
}