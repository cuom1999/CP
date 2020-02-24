#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const int MAX_N = 1005;
const int mod = (int)1e9 + 7;

void check(int x, int l, int r) {
    assert(x >= l && x <= r);
}

void add(int &a, const int &b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

pi start, endd;
int n, m;
pair < int, pi > dp[MAX_N][MAX_N];

string findBack(pi cur) {
    pi to = dp[cur.f][cur.s].s;
  
    if (to.s > cur.s) {
        int tmp = (to.s - cur.s);
        string str = "";
        while(tmp--)
            str += "L";
        if (to == start)
            return str;
        return findBack(mp(to.f - 1, to.s)) + "D" + str;
    } else {
        int tmp = (cur.s - to.s);
        string str = "";
        while(tmp--)
            str += "R";
        if (to == start)
            return str;        
        return findBack(mp(to.f - 1, to.s)) + "D" + str;   
    }
}

string longestPath(vector<vector<char>> maze) {
    n = sz(maze), m = sz(maze[0]);
    check(n, 1, 1000), check(m, 1, 1000);
    start = endd = mp(-1, -1);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            assert(maze[i][j] == '.' || maze[i][j] == '#' || maze[i][j] == 'S' || maze[i][j] == 'E');
            dp[i][j] = mp(-inf, mp(-1, -1));
            if (maze[i][j] == 'S') {
                assert(start == mp(-1, -1));
                start = mp(i, j);
            } 
            if (maze[i][j] == 'E') {
                assert(endd == mp(-1, -1));
                endd = mp(i, j);
            }
        }
    
    for (int j = start.s; j < m; j++) {
        if (maze[start.f][j] == '#')
            break;
        dp[start.f][j] = mp(j - start.s + 1, start);
    }
    for (int j = start.s; j >= 0; j--) {
        if (maze[start.f][j] == '#')
            break;
        dp[start.f][j] = mp(start.s - j + 1, start);
    }

    for (int i = start.f + 1; i <= endd.f; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '#') {
                continue;
            }
        
            int nx = j;

            pair < int, pi > cur = mp(-inf, mp(-1, -1));
            while(nx < m && maze[i][nx] != '#') {
                    int f = dp[i - 1][nx].f + 1 - nx;
                    pi s = mp(i, nx);
                    
                    cur = max(cur, mp(f, s));

                if (dp[i][nx].f < cur.f + nx)
                    dp[i][nx] = mp(cur.f + nx, cur.s);
                nx++;
            }
            
            int to = nx;
            
            nx--;
            cur = mp(-inf, mp(-1, -1));
            
            while(nx >= j) {
                    int f = dp[i - 1][nx].f + 1 + nx;
                    pi s = mp(i, nx);
                
                    cur = max(cur, mp(f, s));

                if (dp[i][nx].f < cur.f - nx)
                    dp[i][nx] = mp(cur.f - nx, cur.s);
                nx--;
            }
            
        }
    }
    
    if (dp[endd.f][endd.s].f < 0)
        return "Not_Exist";
    
    return findBack(endd);    
}

int main()
{
    freopen("input014.txt", "r", stdin);
    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m);

    for (int i = 0; i < m; i++) {
        maze[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    string result = longestPath(maze);

    cout << result << "\n";

    
    return 0;
}

