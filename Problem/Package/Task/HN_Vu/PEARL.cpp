///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define bit(n,i) (((n)>>(i))&1)
#define cntbit(n) __builtin_popcount(n)
#define el; cout<<"\n";
#define fi first
#define file "PEARL"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn
#define MOD 1000000007
#define mp make_pair
#define oo 2003012500
#define pb push_back
#define pi acos(-1)
#define pii pair<int,int>
#define reset(x) memset(x,0,sizeof(x))
#define se second
#define sz size()
#define ub upper_bound
#define ull unsigned long int

using namespace std;
///declare:
int t;
long long l, r, ans;
int cs[250] = {1,7,10,13,19,23,28,31,32,44,49,68,70,79,82,86,91,94,97,100,103,109,129,130,133,139,167,176,188,190,192,193,203,208,219,226,230,236,239,262,263,280,291,293,301,302,310,313,319,320,326,329,331,338,356,362,365,367,368,376,379,383,386,391,392,397,404,409,440,446,464,469,478,487,490,496,536,556,563,565,566,608,617,622,623,632,635,637,638,644,649,653,655,656,665,671,673,680,683,694,700,709,716,736,739,748,761,763,784,790,793,802,806,818,820,833,836,847,860,863,874,881,888,899,901,904,907,910,912,913,921,923,931,932,937,940,946,964,970,973,989,998,1000,1003,1009,1029,1030,1033,1039,1067,1076,1088,1090,1092,1093,1112,1114,1115,1121,1122,1125,1128,1141,1148,1151,1152,1158,1177,1182,1184,1185,1188,1209,1211,1212,1215,1218,1221,1222,1233,1247,1251,1257,1258,1274,1275,1277,1281,1285,1288,1290,1299,1300,1303,1309,1323,1330,1332,1333,1335,1337,1339,1353,1366,1373,1390,1393,1411,1418,1427,1444,1447,1448,1457,1472,1474,1475,1478,1481,1484,1487};
int sum (ll n)
{
    int s=0;
    while (n)
    {
        int m = n%10;
        s += m*m;
        n /= 10;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        ans = 0;
        if(r-l <= 1000000)
        {
            for (ll i=l; i<=r; i++)
                if( !binary_search(cs, cs+225, sum(i)) )ans++;
        }
        cout << ans;
        el;
    }
    return 0;
}
