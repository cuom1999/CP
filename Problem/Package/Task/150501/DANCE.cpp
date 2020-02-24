#include <bits/stdc++.h>
using namespace std;
long long hang,cot,l,m[11][10000],a[11][10000],s[11][10000],need;
void inp()
{
    cin >> cot >> hang >> l >> need;
   // cout <<cot<<" "<<hang<<" "<<l<<" "<<need<<endl;
    for (long long i = 1 ; i <= hang ; i++)
        for (long long e = 1 ; e <= cot ; e++) cin >> m[i][e];
    for (long long i = 1 ; i <= hang ; i++)
        for (long long e = 1 ; e <= l ; e++) cin >> a[i][e];
}
long long calc(long long h , long long c)
{
    long long s = 0;
    for (long long i = c ; i <= c + l - 1 ; i++)
    {
        s += m[h][i] * a[h][i-c+1];
    }
    return s;
}
void trau()
{
    long long kq = 0;
    for (long long j = 1 ; j <= cot ; j++)
    {
        long long t = 0;
        for (long long i = 1 ; i <= hang ; i++)
        {
            t += calc(i,j);
        }
      //  cout <<"cot :"<< j<<"hang : "<<hang<<" t : "<<t<<endl;
        if (t > need) kq++;
    }
    cout << kq<<endl;
}
main()
{
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    inp();
    trau();
}
