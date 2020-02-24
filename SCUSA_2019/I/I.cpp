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
    int e = 0, o = 0;

    int n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2 == 0) e++;
    if (((n + 1) * (n + 2) / 2 - 1) % 2 == 0) e++;

    if (e == 0) {
        cout << "Odd";
    }
    else if (e == 1) {
        cout << "Either";
    }
    else {
        cout << "Even";
    }

    return 0;
}