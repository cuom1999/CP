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

int match[10][10], mov[10][10];

void add(int i, int j) {
    match[i][j] = match[j][i] = 1;
} 

void add1(int i, int j) {
    mov[i][j] = 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);  

    add(0, 6);
    add(0, 9);
    add(2, 3);
    add(3, 5);
    add(6, 9);

    add1(0, 8);
    add1(1, 7);
    add1(3, 9);
    add1(5, 6);
    add1(5, 9);
    add1(6, 8);
    add1(9, 8);

    string s, t;
    cin >> s >> t;

    vector<int> diff;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            diff.pb(i);
        }
    }

    if (diff.size() == 0) {
        cout << "yes\n";
    }
    else if (diff.size() == 1) {
        int i = diff[0];
        if (match[s[i] - '0'][t[i] - '0']) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    else if (diff.size() == 2) {
        int i = diff[0];
        int j = diff[1];
        for (auto &c: s) c -= '0';
        for (auto &c: t) c -= '0';
        if (mov[s[i]][t[i]] && mov[t[j]][s[j]]) {
            cout << "yes\n";
        }
        else if (mov[t[i]][s[i]] && mov[s[j]][t[j]]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    else {
        cout << "no\n";
    }

    return 0;
}