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

vector<int> digits(int x) {
    vector<int> res;
    while (x) {
        res.pb(x % 10);
        x /= 10;
    }
    return res;
}

int sumDigit(int x) {
    vector<int> d = digits(x);
    int res = 0;
    for (auto i: d) {
        res += i;
    }
    return res;
}

vector<int> adj(int x) {
    vector<int> res;
    set<int> s;
    s.insert(x + 1);
    vector<int> d = digits(x);
    sort(all(d));
    for (int i = 0; i < d.size(); i++) {
        if (d[i]) {
            swap(d[i], d[0]);
            break;
        }
    }

    do {
        int num = 0;
        for (auto i: d) {
            num = num * 10 + i;
        }
        s.insert(num);
    } while (next_permutation(all(d)));
    for (auto i: s) {
        res.pb(i);
    }
    return res;
}

int smallest(int x) {
    vector<int> d = digits(x);
    sort(all(d));
    for (int i = 0; i < d.size(); i++) {
        if (d[i]) {
            swap(d[i], d[0]);
            break;
        }
    }
    int num = 0;
    for (auto i: d) {
        num = num * 10 + i;
    }
    return num;
}

int calc(int x) {
    if (x <= 9) return x - 1;
    if (x <= 99) {
        if (x > 11 && x % 10 == 1) return 1 + calc(10 + x / 10);
        return 1 + calc(x - 1);
    }
    if (x == smallest(x)) return 1 + calc(x - 1);
    int y = x - x % 10;
    if (x == y) {
        if (x == smallest(x)) {
            return 1 + calc(x - 1);
        }
        return 1 + calc(smallest(x));
    }
    if (y == smallest(y)) {
        return x % 10 + calc(smallest(y + 1));
    }
    return x % 10 + calc(y);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // vector<int> d(10000);
    // d[1000] = 1;
    // queue<int> q; 
    // q.push(1000);
    // while (q.size()) {
    //     int u = q.front();
    //     q.pop();
    //     vector<int> v = adj(u);
    //     for (auto i: v) {
    //         if (i >= 1000 && !d[i]) {
    //             d[i] = d[u] + 1;
    //             q.push(i);
    //         }
    //     }
    // }
    
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int x;
        cin >> x;
        cout << calc(x) << "\n";
    }

    return 0;
}