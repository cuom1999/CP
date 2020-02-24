#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("meetings.in","r",stdin)
#define OUT freopen("meetings.out","w",stdout)
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

int l;

struct Cow {
    int w, x, d;
    int getTime() {
        if (d == 1) return l - x;
        return x;
    }
};


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n >> l;

    int sumW = 0;

    vector<Cow> cows;
    FOR (i, 1, n) {
        int w, x, d;
        cin >> w >> x >> d;
        cows.pb({w, x, d});
        sumW += w;
    }

    sort(all(cows), [](Cow a, Cow b) {
        return a.getTime() < b.getTime();
    });

    vector<int> dir;
    vector<int> time;
    for (auto i: cows) {
        dir.pb(i.d);
        time.pb(i.getTime());
    }

    sort(all(cows), [](Cow a, Cow b) {
        return a.x < b.x;
    });

    vector<int> order;
    int leftCow = 0, rightCow = n - 1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == -1) {
            order.pb(leftCow);
            leftCow++;
        }
        else {
            order.pb(rightCow);
            rightCow--;
        }
    }

    int curW = 0;
    int lastTime = 0;
    for (int i = 0; i < n; i++) {
        curW += cows[order[i]].w;
        if (2 * curW >= sumW) {
            lastTime = time[i];
            break;
        }
    }

    vector<int> pos;
    ll res = 0;
    for (auto i: cows) {
        if (i.d == 1) {
            pos.pb(i.x);
        }
        else {
            int val = pos.end() - lower_bound(all(pos), i.x - 2 * lastTime);
            res += val;
        }
    }

    cout << res << endl;

 
    return 0;
}