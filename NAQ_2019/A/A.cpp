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

int a[27];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 0, n - 1) {
        char c;
        cin >> c;
        if (c == 'T') a[i] = 1;
    }

    char c;
    stack<int> s;
    while (cin >> c) {
        if (c >= 'A' && c <= 'Z') {
            s.push(a[c - 'A']);
        }
        else {
            int res;
            if (c == '-') {
                int u = s.top();
                s.pop();
                res = u ^ 1;
            }
            else {
                int u = s.top();
                s.pop();
                int v = s.top();
                s.pop();
                if (c == '*') {
                    res = u & v;
                }               
                else {
                    res = u | v;
                } 
            }
            s.push(res);
        }
    }
    if (s.top()) {
        cout << "T" << endl;
    }
    else {
        cout << "F" << endl;
    }
    return 0;
}