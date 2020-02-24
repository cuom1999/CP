#include <bits/stdc++.h>
#include <ext/rope> //header with rope
using namespace __gnu_cxx; //namespace with rope and some additional stuff

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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

struct Circle {
    ll x, y, r;
    int index;
} circle[200005];

int p[200005];
vector<int> adj[200005];
int res[200005][3];
// 0: not take this
// 1: take this 
int n, q;
    
void dfs(int a) {
    for (auto i: adj[a]) {
        dfs(i);
    }

    if (a <= n) {
        res[a][1] = 1;
    }
    for (auto i: adj[a]) {
        if (i <= n) {
            res[a][0] += max(res[i][0], res[i][1]);
            res[a][1] += res[i][0];
        }
        else {
            res[a][0] += max(res[i][0], res[i][1]);
            res[a][1] += res[i][1];
        }
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;

    FOR (i, 1, n) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
        circle[i].index = i;
    }

    FOR (i, 1, q) {
        cin >> circle[i + n].x >> circle[i + n].y >> circle[i + n].r;
        circle[i + n].index = i + n;
    }

    vector<II> sweepline;

    FOR (i, 1, n + q) {
        sweepline.pb({circle[i].x - circle[i].r, i});
        sweepline.pb({circle[i].x + circle[i].r, -i});
    }

    sort(all(sweepline));

    rope<int> lowerHalf, upperHalf;

    FOR (i, 0, 2 * (n + q) - 1) {
        int index = abs(sweepline[i].second);
        ll curX = sweepline[i].first;
        ll curY = circle[index].y;
        if (sweepline[i].second < 0) {
            // close
            int lower = 0, upper = lowerHalf.size();
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                int curIndex = lowerHalf[mid];
                ld yIntersect = circle[curIndex].y - sqrt(sq(circle[curIndex].r) - sq(curX - circle[curIndex].x));
                if (abs(yIntersect - curY) < eps) {
                    lower = upper = mid;
                    assert(curIndex == index);
                    break;
                }
                else if (yIntersect < curY) {
                    lower = mid + 1;
                }
                else {
                    upper = mid - 1;
                }
            }

            lowerHalf.erase(lower, 1);
            // ----
            
            lower = 0, upper = upperHalf.size();
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                int curIndex = upperHalf[mid];
                ld yIntersect = circle[curIndex].y + sqrt(sq(circle[curIndex].r) - sq(curX - circle[curIndex].x));
                if (abs(yIntersect - curY) < eps) {
                    lower = upper = mid;
                    assert(curIndex == index);
                    break;
                }
                else if (yIntersect < curY) {
                    lower = mid + 1;
                }
                else {
                    upper = mid - 1;
                }
            }
            upperHalf.erase(lower, 1);
        }
        else {
            int firstCircle = -1;
            bool isLower = 0;
            ld firstY;

            // open
            int lower = 0, upper = lowerHalf.size();
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                int curIndex = lowerHalf[mid];
                ld yIntersect = circle[curIndex].y - sqrt(sq(circle[curIndex].r) - sq(curX - circle[curIndex].x));
                if (yIntersect < curY) {
                    lower = mid + 1;
                }
                else {
                    upper = mid;
                }
            }
            lowerHalf.insert(lower, index);
            if (lower) {
                isLower = 1;
                firstCircle = lowerHalf[lower - 1];
                firstY = circle[firstCircle].y - sqrt(sq(circle[firstCircle].r) - sq(curX - circle[firstCircle].x));
            }
            // ----
            lower = 0, upper = upperHalf.size();
            while (lower < upper) {
                int mid = (lower + upper) / 2;
                int curIndex = upperHalf[mid];
                ld yIntersect = circle[curIndex].y + sqrt(sq(circle[curIndex].r) - sq(curX - circle[curIndex].x));
                if (yIntersect < curY) {
                    lower = mid + 1;
                }
                else {
                    upper = mid;
                }
            }
            if (lower) {
                int cur = upperHalf[lower - 1];
                ld val = circle[cur].y + sqrt(sq(circle[cur].r) - sq(curX - circle[cur].x));
                
                if (firstCircle == -1 || val > firstY) {
                    firstCircle = cur;
                    isLower = 0;
                }
            }
            upperHalf.insert(lower, index);

            if (firstCircle != -1) {
                if (isLower) {
                    p[index] = firstCircle;
                }
                else {
                    p[index] = p[firstCircle];
                }
            }
        }
        // for (auto i: lowerHalf) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto i: upperHalf) {
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    FOR (i, 1, n + q) {
        adj[p[i]].pb(i);
    }

    dfs(0);

    FOR (i, 1, q) {
        cout << max(res[i + n][0], res[i + n][1] + 1) << "\n";
    }

    return 0;
}