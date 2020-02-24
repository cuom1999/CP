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

int midPoint[10][10];

void add(int a, int b, int c) {
    midPoint[a][c] = midPoint[c][a] = b;
}

bool isValid(vector<int> p) {
    int n = p.size() - 1;
    vector<bool> vs(10);
    FOR (i, 1, n - 1) {
        int a = midPoint[p[i]][p[i + 1]];
        if (a && !vs[a]) return 0;
        vs[p[i]] = 1;
    }
    return 1;
}

struct Point {
    int x, y;
    Point operator-(Point B) {
        return {x - B.x, y - B.y};
    }
};

int ccw(Point A, Point B, Point C) {
    Point D = B - A;
    Point E = C - B;
    return D.x * E.y - D.y * E.x;
}

char getTurn(Point A, Point B, Point C) {
    int val = ccw(A, B, C);
    if (val > 0) {
        return 'L';
    }
    else if (val < 0) {
        return 'R';
    }
    if ((B.x - A.x) * (C.x - B.x) > 0 || (B.y - A.y) * (C.y - B.y) > 0) {
        return 'S';
    }
    return 'A';
}

Point pts[10];

string getTurns(vector<int> p) {
    int n = p.size() - 1;
    string res;
    FOR (i, 1, n - 2) {
        res += getTurn(pts[p[i]], pts[p[i + 1]], pts[p[i + 2]]);
    }
    return res;
}

bool match(string a, string b) {
    for (int i = 0; i < b.size(); i++) {
        if (a[i] == b[i] || b[i] == '?') continue;
        return 0;
    }
    return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    add(1, 2, 3);
    add(4, 5, 6);
    add(7, 8, 9);
    add(1, 4, 7);
    add(2, 5, 8);
    add(3, 6, 9);
    add(1, 5, 9);
    add(3, 5, 7);

    int curX = 0;
    int curY = 0;
    FOR (i, 1, 9) {
        pts[i] = {curX, curY};
        curX++;
        if (curX == 3) {
            curX = 0;
            curY--;
        }
    }

    vector<int> a(10);
    FOR (i, 1, 9) {
        a[i] = i;
    }
    string s;
    cin >> s;

    int res = 0;
    do {
        if (isValid(a) && match(getTurns(a), s)) {
            res++;
        }
    } while(next_permutation(a.begin() + 1, a.begin() + 10));
    
    cout << res << endl;
    
    return 0;
}