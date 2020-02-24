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

ll sufHard[200005], sufEasy[200005];
struct Data {
    int time, type;
    bool operator < (const Data& d) {
        return time < d.time;
    }
} data[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        ll T, a, b;
        cin >> n >> T >> a >> b;
        FOR (i, 1, n) {
            cin >> data[i].type;
        }
        FOR (i, 1, n) {
            cin >> data[i].time;
        }
        sort(data + 1, data + 1 + n);
        sufEasy[n + 1] = sufHard[n + 1] = 0;
        FORD(i, n, 1) {
            sufHard[i] = sufHard[i + 1];
            sufEasy[i] = sufEasy[i + 1];
            if (data[i].type == 0) {
                sufEasy[i]++;
            }
            else {
                sufHard[i]++;
            }
        }

        int res = 0;
        data[0].time = -1;
        data[n + 1].time = T + 1;

        ll sumTime = 0;

        FOR (i, 1, n + 1) {
            ll curTime = 0;
            if (i > 1 && data[i - 1].type == 1) curTime = b;
            if (i > 1 && data[i - 1].type == 0) curTime = a; 
            sumTime += curTime;
            if (data[i].time == data[i - 1].time) continue;
            ll timeLeft = data[i].time - 1;
            
            if (sumTime > timeLeft) {
                continue;
            }

            ll val = timeLeft - sumTime;
            int score = i - 1;
            // cout << sufEasy[i] << " " << sufHard[i] << " " << val << endl;
            if (sufEasy[i]) {
                ll u = min(sufEasy[i], val / a);
                score += u;
                val -= u * a;
            }
            if (sufHard[i]) {
                ll u = min(sufHard[i], val / b);
                score += u;
            }
            res = max(res, score);
            // cout << timeLeft << " " << score << "\n";
        }
        // cout << endl;
        cout << res << '\n';
    }


    return 0;
}