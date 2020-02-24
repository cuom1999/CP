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
typedef pair < II, ll > IL;

ll dist[105][105];

struct Event {
    int location;
    bool type;
    int startTime, endTime;
    ll cost;

    bool operator< (const Event& e) {
        if (startTime != e.startTime) {
            return startTime < e.startTime;
        }
        return type < e.type;
    }
};


void calcDist(int n) {
    FOR (k, 1, n) {
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

vector<IL> waiting[2020025];

struct MyHash {
    static const int BUCKET_SIZE = 1000000;
    vector<II> v[BUCKET_SIZE];
    int operator[](int a) {
        int pos = a % BUCKET_SIZE;
        auto u = lower_bound(all(v[pos]), II(a, 0));
        return (*u).second;
    }
    void insert(int pos, int val) {
        v[pos % BUCKET_SIZE].pb({pos, val});
    }
    void resort() {
        FOR (i, 0, BUCKET_SIZE - 1) {
            if (v[i].size()) sort(all(v[i]));
        }
    }
};

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int g, n, m;
    cin >> g >> n >> m;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            if (i != j) dist[i][j] = 1e18;
        }
    }

    FOR (i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = dist[v][u] = min(dist[u][v], (ll) c);
    }   
    calcDist(n);

    vector<Event> events;
    vector<int> time;
    MyHash compressedTime;

    FOR (i, 1, n) {
        if (dist[1][i] > INF) continue;
        time.pb(dist[1][i]);
    }

    FOR (i, 1, g) {
        int location, startTime, endTime, cost;
        cin >> location >> startTime >> endTime >> cost;
        Event e = {location, 1, startTime, endTime, cost};
        events.pb(e);
        time.pb(e.startTime);

        FOR (j, 1, n) {
            if (dist[location][j] > INF) continue;
            time.pb(endTime + (int) dist[location][j]);
        }
    }
    sort(all(time));
    int timeCnt = 0;

    vector<int> transTime;
    transTime.pb(0);
    for (int i = 0; i < time.size(); i++) {
        if (!i || time[i] != time[i - 1]) {
            // compressedTime[time[i]] = ++timeCnt;
            compressedTime.insert(time[i], ++timeCnt);
            transTime.pb(time[i]);
        }
    }
    compressedTime.resort();
    time.clear();

    vector<ll> dp(n + 1);
    FOR (i, 2, n) dp[i] = -1e18;

    sort(all(events));

    const int MAX_TIME = 20200200;
    FOR (i, 1, n) {
        if (dist[1][i] > INF) continue;
        waiting[compressedTime[dist[1][i]] / 10].pb({{compressedTime[dist[1][i]], i}, 0});
    }

    int eventIdx = 0;
    FOR (t, 1, MAX_TIME) {
        for (auto &e: waiting[t / 10]) {
            // cout << e.first.first << endl;
            if (e.first.first != t) continue;
            dp[e.first.second] = max(dp[e.first.second], e.second);
            // cout << t << endl;
            // FOR (i, 1, n) cout << dp[i] << " "; cout << endl;   
        }
        while(eventIdx < events.size()) {
            if (events[eventIdx].startTime > transTime[t]) break;
            auto e = events[eventIdx];
            ll val = dp[e.location] + e.cost;
            FOR (i, 1, n) {
                if (dist[e.location][i] > INF) continue;
                int curTime = compressedTime[e.endTime + dist[e.location][i]];
                
                if (dp[i] < val) waiting[curTime / 10].push_back({{curTime, i}, val});
            }
            eventIdx++;
            // cout << t << endl;
            // FOR (i, 1, n) cout << dp[i] << " "; cout << endl;   
        }
    }
    
    ll res = 0;
    FOR (i, 1, n) {
        res = max(res, dp[i]);
    }
    cout << res << endl;

    return 0;
}