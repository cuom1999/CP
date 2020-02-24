//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "DANCE"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, l, m, W, res, ans= 0, a[11][70005], b[11][30005];



main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n>> l>> m>> W;

    forr(i, 1, m)
    forr(j, 1, n)
    cin>> a[i][j];

    forr(i, 1, m)
    forr(j, 1, l)
    cin>> b[i][j];

    forr(k, 0, n- l)
    {
        res= 0;
        forr(i, 1, m)
        forr(j, 1, l)
        res+= a[i][j+ k]* b[i][j];
        if(res> W) ++ans;
    }

    cout<< ans;

    //else lm();


    return 0;
}
