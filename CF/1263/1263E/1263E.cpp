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

const int MAXN = 1000005;
int stMin[4 * MAXN], lz[4 * MAXN], stMax[4 * MAXN];

void down(int id, int l, int r) {
    if (!lz[id] || l == r) return;
    FOR (i, 0, 1) {
        int u = id * 2 + i;
        lz[u] += lz[id];
        stMin[u] += lz[id];
        stMax[u] += lz[id];
    }
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        stMin[id] += k;
        stMax[id] += k;
        lz[id] += k;
        return;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);
    stMin[id] = min(stMin[id * 2], stMin[id * 2 + 1]);
    stMax[id] = max(stMax[id * 2], stMax[id * 2 + 1]);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string command;
    FOR (i, 1, n) command += 'a';

    int cur = 0, sum = 0;
    FOR (i, 0, n - 1) {
        if (s[i] == 'L') {
            if (cur) cur--;
        }
        else if (s[i] == 'R') {
            cur++;
        }
        else {
            int val = 0;
            if (command[cur] == '(') {
                val--;
                sum--;
            }
            else if (command[cur] == ')') {
                val++;
                sum++;
            }
            if (s[i] == '(') {
                val++;
                sum++;
            }
            if (s[i] == ')') {
                val--;
                sum--;
            }
            command[cur] = s[i];
            update(1, 0, n, cur, n, val);
        }
        // cerr << i << " " << sum << endl;
        if (sum) {
            cout << -1 << " ";
        }
        else {
            if (stMin[1] >= 0) {
                cout << stMax[1] << " ";
            }
            else cout << -1 << " ";
        }
    }



    return 0;
}