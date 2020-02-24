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

typedef pair < int, int > II;
typedef pair < int, II > III;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[105][105][105][105];
int n, m;
int a[105][105];

bool isValid(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] >= 0);
}


int necDist[30];
II pos[30];
ll dp[30][105][105];

ll res = INF;
int k;
vector<II> close[30];

void solve(int c) {
    int tmp[105][105];
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            tmp[i][j] = INF;
        }
    }
    priority_queue< III, vector<III>, greater<III> > pq;
    
    for (auto i: close[c - 1]) {
        tmp[i.first][i.second] = dp[c - 1][i.first][i.second];
        pq.push({tmp[i.first][i.second], i});
    }

    while (pq.size()) {
        II u = pq.top().second;
        int du  = pq.top().first;
        pq.pop();

        if (tmp[u.first][u.second] != du) continue;
        FOR (i, 0, 3) {
            int newX = u.first + dx[i];
            int newY = u.second + dy[i];
            if (isValid(newX, newY) && tmp[newX][newY] > du + a[newX][newY]) {
                tmp[newX][newY] = du + a[newX][newY];
                pq.push({tmp[newX][newY], {newX, newY}});
            }
        }
    }

    for (auto i: close[c]) {
        dp[c][i.first][i.second] = tmp[i.first][i.second];
        if (c == k) {
            res = min(res, dp[c][i.first][i.second]);
        }
    }

}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k;
    FOR (i, 1, k) {
        cin >> necDist[i];
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            string s;
            cin >> s;
            if (s[0] >= 'A' && s[0] <= 'Z') {
                a[i][j] = -s[0] + 'A' - 1;
                pos[s[0] - 'A' + 1] = {i, j};
            }
            else {
                a[i][j] = stoi(s);
            }
        }
    }

    close[0].pb({1, 1});

    FOR (c, 1, k) {
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                if (sq(i - pos[c].first) + sq(j - pos[c].second) <= sq(necDist[c]) && a[i][j] >= 0) {
                    close[c].pb({i, j});
                }
            }
        }
    }

    if (a[1][1] < 0) {
        cout << -1;
        return 0;
    }
    dp[0][1][1] = a[1][1];
    FOR (i, 1, k) solve(i); 
    if (res >= INF) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}