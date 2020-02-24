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

ll a[1005], b[1005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    ll sumVote = 0;
    FOR (i, 1, n) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x] += y;
        b[x] += z;
        sumVote += y;
        sumVote += z;
    }

    ll sumA = 0, sumB = 0;
    FOR (i, 1, d) {
        ll sum = a[i] + b[i];
        ll mid = sum / 2 + 1;
        if (a[i] > b[i]) {
            a[i] -= mid;
            cout << "A " << a[i] << " " << b[i] << "\n"; 
        }
        else {
            b[i] -= mid;
            cout << "B " << a[i] << " " << b[i] << "\n";    
        }

        sumA += a[i];
        sumB += b[i];        
    }

    cout << fixed << setprecision(9) << abs(sumA - sumB) * 1.0 / sumVote << endl;


    return 0;
}