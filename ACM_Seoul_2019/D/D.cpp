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

map<string, string> suf;

string ori[] = {"a", "i", "y", "l", "n", "o", "r", "t", "u", "v", "w"};
string val[] = {"as", "ios", "ios", "les", "anes", "os", "res", "tas", "us", "ves", "was"};


string transform(string s) {
    char last = s.back();
    string u;
    u += last;

    if (suf.count(u)) {
        s.pop_back();
        s += suf[u];
    }
    else if (last == 'e' && s.size() >= 2 && s[s.size() - 2] == 'n') {
        s.pop_back();
        s.pop_back();
        s += suf["n"];
    }
    else {
        s += "us";
    }
    return s;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 0, 10) {
        suf[ori[i]] = val[i];
    }

    int n;
    cin >> n;

    FOR (i, 1, n) {
        string s;
        cin >> s;
        cout << transform(s) << "\n";
    }

    return 0;
}