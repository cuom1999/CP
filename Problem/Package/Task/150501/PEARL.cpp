#include <bits/stdc++.h>
using namespace std;
vector <long long> ruler;
long long ok[12300];long long l , r;string a,b;long long prea[17230],yes[123231]; long long result[20][2001][2];
long long toint(string l)
{
    long long kq = 0;
    for (long long i = 0 ; i < l.size() ; i++) kq =kq*10+ (l[i] - '0');
    return kq;
}
void inp()
{
    cin >> a >> b;
}
long long getsum(long long a)
{
    long long kq = 0;
    while (a != 0) kq += (a%10)*(a%10) , a = a / 10;
    return kq;
}
void trau(long long l , long long r)
{
    long long kq = 0;
    for (long long i = l ; i <= r ; i++) if (ok[getsum(i)] == -1) kq++; //cout<<"i : "<<i<<endl;
    cout << kq <<endl;
}
long long sinh(long long t, long long h)
{
    while (yes[t] != h)
    {
        yes[t] = h;
        t = getsum(t);
        if (t == 1) return 1;
        if (ok[t] != 0) return ok[t];
    }
    return -1;
}
void check()
{
    for (long long i = 1 ; i <= 1458 ; i++)
    {
        ok[i] = sinh(i,i);
        if (ok[i] == 1) ruler.push_back(i);
    }
}
long long dp(long long need, long long cd)
{
   // if (need == 2)
   // cout <<"cd : "<<cd;
    long long kq = 0,st;
    for (long long i = 1 ; i <= cd ; i++)
            for (long long k = 0 ; k <= need ; k++) result[i][k][1] = result[i][k][0] = 0;
    if (cd == a.size())
    {
        for (long long i = 1 ; i <= cd ; i++)
        {
            if (i == 1) st = 1;
            else st = 0;
            long long d = a[i-1] - '0';
            for (long long k = 0 ; k <= need ; k++)
            {
                for (long long e = st ; e <= 9 ; e++)
                {
                    if (k - e*e < 0) break;
                    if (i == 1 && d == e && k == e*e) result[i][k][0]++;
                    if (i == 1 && d > e && k == e*e) result[i][k][1]++;
                    if (i == 1) continue;
                    if (d == e) result[i][k][0] += result[i-1][k - e*e][0];
                    result[i][k][1] += result[i-1][k-e*e][1];
                    if (d > e) result[i][k][1] += result[i-1][k-e*e][0];
                }
               // if (need == 5 && cd == a.size() && k <= 10) cout <<"result["<<i<<"]["<<k<<"][0] : "<<result[i][k][0]<<" and "<<result[i][k][1]<<endl;
            }
        }
        kq = result[cd][need][0] + result[cd][need][1];
    }
    if (cd < a.size())
    {
       // if (need == 2)
        //cout <<"asd"<<endl;
        for (long long i = 1 ; i <= cd ; i++)
        {
            if (i == 1) st = 1;
            else st = 0;
            for (long long k = 0 ; k <= need ; k++)
            {
                for (long long e = st ; e <= 9 ; e++)
                {
                    if (i == 1 && k == e*e) result[i][k][0]++;
                    if (i == 1) continue;
                    if (k - e*e < 0) break;
                    result[i][k][0] += result[i-1][k-e*e][0];
                }
              //  if (need == 2) cout <<"Asd"<<result[i][k][0]<<endl;
            }
        }
        kq = result[cd][need][0] + result[cd][need][1];
      //  if (need == 2) cout <<"cd : "<<cd<<" kq : "<<kq<<endl;
    }
    return kq;
}
void digitdp()
{
    long long kq1 = 0;
    for (long long i = 0 ; i < ruler.size() ; i++)
    {
        kq1 += dp(ruler[i],a.size());
        for (long long e = 1 ; e < a.size() ; e++) kq1 += (dp(ruler[i],e));
    }
  a = b;
  long long g = l;
  long long kq2 = 0;
  for (long long i = 0 ; i < ruler.size() ; i++)
    {
        kq2 += dp(ruler[i],a.size());
        for (long long e = 1 ; e < a.size() ; e++) kq2 += (dp(ruler[i],e));
    }
    if (ok[getsum(g)] == 1)
    cout <<(r - kq2) - (l-kq1)<<endl;
    else
    cout <<(r - kq2) - (l-kq1)+1<<endl;
}
main()
{
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    check();

    int t;
    cin >> t;
    while (t--)
    {
        inp();

    l = toint(a) ; r =toint(b);
    if (r - l + 1 <= 1000000) trau(l,r);
    else
        digitdp();}
}
