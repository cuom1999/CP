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
typedef pair < ll, ll > pll;

int maxMatrix(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();

    int ans = 0;
    vector<int> d(m, -1), d1(m), d2(m);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0)
                d[j] = i;
        }

        for (int j = 0; j < m; ++j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d1[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d2[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = 0; j < m; ++j)
            ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
    return ans;
}

vector<vector<int>> c, a;
int n, m, h;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void flood(int currH) {
    queue<II> q;
    FOR (i, 0, n - 1) {
        FOR (j, 0, m - 1) {
            if (a[i][j]) q.push({i, j});
        }
    }

    while (q.size()) {
        auto u = q.front();
        q.pop();
        FOR (k, 0, 3) {
            int newX = dx[k] + u.first;
            int newY = dy[k] + u.second; 
            if (isValid(newX, newY) && !a[newX][newY] && c[newX][newY] <= currH) {
                a[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> h;

    c.resize(n);
    FOR (i, 0, n - 1) c[i].resize(m);
    a.resize(n);
    FOR (i, 0, n - 1) a[i].resize(m);

    FOR (i, 0, n - 1) {
        FOR (j, 0, m - 1) {
            int x;
            cin >> x;
            c[i][j] = x;
        }
    }

    a[n / 2][m / 2] = 1;
    FOR (i, 0, h) {
        flood(i);
        cout << maxMatrix(a) << "\n";
    }



    return 0;
}