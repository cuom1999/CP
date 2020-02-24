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

vector<char> c = {'^', '>', 'v', '<'};
int n;

char nextC(char ch) {
    if (ch == '.') return '.';
    FOR (i, 0, 3) {
        if (c[i] == ch) {
            return c[(i + 1) % 4];
        }
    }
    return 0;
}

void move(vector<vector<char>>& a) {
    vector<vector<char>> b = a;
    FOR (i, 0, n - 1) {
        FOR (j, 0, n - 1) {
            int i1 = j, j1 = n - 1 - i;
            b[i1][j1] = nextC(a[i][j]);
        }
    }
    a = b;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for (auto i: s) {
        if (i == 'L') cnt--;
        else cnt++;
    }
    cnt = (cnt % 4 + 4) % 4;

    vector<vector<char>> a(n, vector<char>(n));
    FOR (i, 0, n - 1) {
        FOR (j, 0, n - 1) {
            cin >> a[i][j];
        }
    }
    FOR (i, 1, cnt) move(a);

    FOR (i, 0, n - 1) {
        FOR (j, 0, n - 1) {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}