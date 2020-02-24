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

int inv(vector<int>& a) {
    bool inc = 1;
    int res = 0;
    for (int i = 1; i < a.size(); i++) {
        if (inc && a[i] < a[i - 1]) {
            inc = 0;
            res++;
        }
        else if (!inc && a[i] > a[i - 1]) {
            inc = 1;
            res++;
        }
    }    
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));
    int n;
    cin >> n;
    vector<int> a;

    FOR (i, 1, n) {
        int x;
        cin >> x;
        x = i;
        a.pb(x);
    }
    random_shuffle(all(a));
    vector<II> res;


    FOR (i, 1, 20) {
        for (auto i: a) cout << i << " ";
        cout << ": ";
        int minInv = inv(a);
        cout << minInv << endl;
        vector<int> minVec = a;
        if (!minInv) break;

        II op = {0, 0};

        FOR (i, 0, n - 1) {
            int c1 = 0, c2 = 0;
            FOR (j, i + 1, n - 1) {
                if (a[j] > a[j - 1]) c1++;
                else c2++;
                if (c1 && c2) break;

                vector<int> tmp = a;
                reverse(tmp.begin() + i, tmp.begin() + j + 1);
                int numInv = inv(tmp);
                if (numInv <= minInv) {
                    minInv = numInv;
                    minVec = tmp;
                    op = {i + 1, j + 1};
                }
            }
        }
        a = minVec;
        res.pb(op);
    }

    cout << res.size() << endl;
    return 0;
    for (auto i: res) cout << i.first << " " << i.second << "\n";
    return 0;
}