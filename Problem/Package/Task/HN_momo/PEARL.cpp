//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "PEARL"
#define PI 3.1415926535897
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int t, l, r, c[1460], d[1460], res= 0, F[1460];

void dfs(int x)
{
    d[x]= 1;
    int a= 0, save= x;
    while(x){
        a+= (x% 10)* (x% 10);
        x/= 10;
    }
    if(!d[a]) dfs(a);
    c[save]= c[a];
}


void lm()
{
    while(l% 1000)
    {
        int x= l, a= 0;
        while(x)
        {
            a+= (x% 10)* (x% 10);
            x/= 10;
        }
        res+= (1- c[a]);
        ++l;
    }
    while(r% 1000)
    {
        int x= r, a= 0;
        while(x)
        {
            a+= (x% 10)* (x% 10);
            x/= 10;
        }
        res+= (1- c[a]);
        --r;
    }
    l/= 1000, r/= 1000;
    forr(i, l, r- 1)
    {
        int x= i, a= 0;
        while(x)
        {
            a+= (x% 10)* (x% 10);
            x/= 10;
        }
        res+= F[a];
    }
    int x= r, a= 0;
    while(x)
    {
        a+= (x% 10)* (x% 10);
        x/= 10;
    }
    res+= (1- c[a]);
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    c[1]= d[1]= 1;

    forr(i, 1, 1458)
    if(!d[i]) dfs(i);


    forr(i, 0, 1215)
    {
        int C= 0;
        forr(j, 0, 999)
        {
            int x= j, a= 0;
            while(x){
                a+= (x% 10)* (x% 10);
                x/= 10;
            }
            C= i+ a;
            F[i]+= (1- c[C]);
        }
    }


    cin>> t;
    while(t--){
        cin>> l>> r;
        res= 0;
        if(r- l<= 1e5){
            forr(i, l, r)
            {
                int x= i, a= 0;
                while(x)
                {
                    a+= (x% 10)* (x% 10);
                    x/= 10;
                }
                if(!c[a]) ++res;
            }
        }
        else lm();

        cout<< res<< "\n";
    }

    /*forr(i, 1, 1458)
    if(c[i]) cout<< i<< "\n";*/

    return 0;
}
