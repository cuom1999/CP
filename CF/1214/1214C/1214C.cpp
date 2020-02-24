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

    int m;
    cin >> m;

    string s;
    cin >> s;

    int n = s.length();

    int sum = 0;
    bool made = 0;
    FOR (i, 0, n - 1) {
        if (s[i] == '(') {
            sum++;
        }
        else {
            sum--;
        }

        if (sum < 0 && !made) {
            sum++;
            made = 1;
        } 
        else if (sum < 0) {
            cout << "No";
            return 0;
        }
    }

    if (made) {
        sum--;
    }

    if (sum == 0) {
        cout << "Yes";
    }
    else cout << "No";


    return 0;
}