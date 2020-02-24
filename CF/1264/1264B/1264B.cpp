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

void construct(int a[4]) {
    FOR (i, 1, a[0]) cout << "0 1 ";
    FOR (i, 1, a[1] - a[0]) cout << "2 1 ";
    FOR (i, 1, a[3]) cout << "2 3 ";
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int a[4];
    FOR (i, 0, 3) cin >> a[i];
    if (a[2] == a[3] && !a[2] && a[0] - a[1] == 1) {
        cout << "YES\n";
        FOR (i, 1, a[1]) cout << "0 1 ";
        cout << 0; 
        return 0;
    }
    if (a[0] == a[1] && !a[0] && a[3] - a[2] == 1) {
        cout << "YES\n";
        FOR (i, 1, a[2]) cout << "3 2 ";
        cout << 3; 
        return 0;
    }

    int d = a[0] + a[2] - a[1] - a[3];
    if (abs(d) > 1) {
        cout << "NO";
        return 0;
    }
    if (a[1] < a[0] || a[2] < a[3]) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (d == 0) construct(a);
    if (d == 1) {
        a[2]--;
        construct(a);
        cout << "2 ";
    }
    if (d == -1) {
        cout << "1 ";
        a[1]--;
        construct(a);
    }


    return 0;
}