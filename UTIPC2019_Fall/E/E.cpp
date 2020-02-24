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

int c[300][300]; // b can go after a

bool check(string s) {
    int n = s.size();
    FOR (i, 0, n - 2) {
        if (!c[s[i]][s[i + 1]]) return 0;
    }
    return 1;
}
bool check1(string s) {
    s += s[0];
    return check(s);
}

bool canConcat[300][27];
bool canConcatSelf[300][27];
string str[100005];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;
    FOR (i, 'a', 'z') {
        int m;
        cin >> m;
        if (!m) continue;
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            c[i][s[j]] = 1;
        }
    }
    FOR (i, 1, n) {
        cin >> str[i];
        if (check(str[i])) {
            canConcat[str[i][0]][str[i].size()] = 1;
        }
        if (check1(str[i])) {
            canConcatSelf[str[i][0]][str[i].size()] = 1;
        }
    }

    string good = "Feline good!\n";
    string bad = "Get meowt!\n";
    FOR (i, 1, n) {
        int m = str[i].size();
        if (!check(str[i])) {
            cout << bad;
            continue;
        }
        bool isGood = 0; 
        if (check(str[i]) && x <= m && m <= y) isGood = 1;
        FOR (ch, 'a', 'z') {
            if (isGood || m > y) break;
            if (c[str[i].back()][ch]) {
                FOR (j, 1, 20) {
                    if (canConcat[ch][j] && x <= m + j && m + j <= y) {
                        isGood = 1;
                        break;
                    }
                    // if (canConcatSelf[ch][j] && (y - m) / j * j >= x - m) {
                    //     isGood = 1;
                    //     break;
                    // }
                }
            }
        }
        if (isGood) {
            cout << good;
        }
        else cout << bad;
    }





    return 0;
}