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

const int MAXN = 1005;

int x[MAXN], y[MAXN], z[MAXN];

struct Point {
    int x[3];
    Point(int a = 0, int b = 0, int c = 0) {
        x[0] = a;
        x[1] = b;
        x[2] = c;
    }
};

struct Rec {
    Point lower, upper;

    ll area() {
        ll res = 1;
        FOR (i, 0, 2) {
            res *= (upper.x[i] - lower.x[i] + 1);
        }
        return res;
    }

    bool trim() {
        FOR (i, 0, 2) {
            if (lower.x[i] > upper.x[i]) {
                return false;
            }
        }
        return true;
    }
};

bool contained(Rec &a, Point &b) {
    FOR (i, 0, 2) {
        if (b.x[i] > a.upper.x[i] || b.x[i] < a.lower.x[i]) return 0;
    }
    return 1;
}

bool contained(Rec& a, Rec &b) {
    FOR (i, 0, 2) {
        if (b.lower.x[i] <= a.lower.x[i] && a.upper.x[i] <= b.upper.x[i]) continue;
        return 0;
    }
    return 1;
}

bool intersect(Rec &a, Rec &b) {
    Rec c;
    FOR (i, 0, 2) {
        c.lower.x[i] = max(a.lower.x[i], b.lower.x[i]);
        c.upper.x[i] = min(a.upper.x[i], b.upper.x[i]);
        if (c.lower.x[i] > c.upper.x[i]) return 0;
    }
    return 1;
}
Point gem[MAXN];
Rec rec[MAXN];
        

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    while (true) {
        
        int a, b, c, m;
        cin >> a;
        if (a == -1) break;

        cin >> b >> c >> m;

        vector<int> cnt(m + 1);

        FOR (i, 1, m) {
            FOR (j, 0, 2) {
                cin >> gem[i].x[j];
            }
        }

        bool fthCondi = 1;

        FOR (i, 1, m) {
            FOR (j, 0, 2) {
                cin >> rec[i].lower.x[j];
            }
            FOR (j, 0, 2) {
                cin >> rec[i].upper.x[j];
            }

            fthCondi &= rec[i].trim();
        }

        if (!fthCondi) {
            cout << "NO\n";
            continue;
        }

        bool isGood = 1;
        Rec bigRec;
        bigRec.lower = Point(1, 1, 1);
        bigRec.upper = Point(a, b, c);
        FOR (i, 1, m) {
            if (!contained(rec[i], bigRec)) {
                isGood = 0;
                break;
            }
        }

        if (!isGood) {
            cout << "NO\n";
            continue;
        }

        bool isNotIntersect = 1;

        FOR (i, 1, m) {
            FOR (j, i + 1, m) {
                if (intersect(rec[i], rec[j])) {
                    isNotIntersect = 0;
                    break;
                }
            }
            if (!isNotIntersect) break;
        }

        if (!isNotIntersect) {
            cout << "NO\n";
            continue;
        }
        FOR (i, 1, m) {
            if (contained(rec[i], gem[i])) {
                cnt[i]++;
            }
        }

        bool containedMore = 1;
        FOR (i, 1, m) {
            if (cnt[i] != 1) {
                containedMore = 0;
                break;
            }
        }

        if (!containedMore) {
            cout << "NO\n";
            continue;
        }

        ll totalArea = 0;
        FOR (i, 1, m) {
            totalArea += rec[i].area();
        }

        if (totalArea != bigRec.area()) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
}