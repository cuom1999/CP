//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn 2005
#define pb push_back
#define oo 1000000007
//#define int long long
#define DoNothing "RPS"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int n, f[mn][mn], res= 0;
bitset< mn> a[mn], d[mn], z;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> n;
    forr(i, 1, n)
    {
        char c;
        forr(j, 1, n){
            cin>> c;
            if(c== '1'){
                f[i][j]= 1;
                a[i].set(j);
                d[j].set(i);
            }
        }
    }


    forr(i, 1, n)
    {
        forr(j, 1, n)
        {
            if(!f[i][j]) z= a[i]& d[j];
            else z= a[j]& d[i];
            if(z.count()){
                ++res;
                break;
            }
        }
    }

    cout<< res;

    return 0;
}
