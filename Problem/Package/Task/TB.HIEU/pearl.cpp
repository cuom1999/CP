#include <bits/stdc++.h>

using namespace std;
ifstream fi("pearl.inp");
ofstream fo("pearl.out");
int n;
int64_t L,R;
int kq;
int tt[2001];
void run1(int x)
{
    int tg1=x,tg2=0;
    while (1)
    {
        while (tg1>0)
        {
            tg2+=(tg1%10)*(tg1%10);
            tg1/=10;
        }
        if (tg2<10)
        {
            tt[x]=tt[x-1];
            if (tg2==1 || tg2==7) tt[x]++;
                //fo<<x<<endl;
            return;
        }
        tg1=tg2;tg2=0;
    }
}
bool kt(int64_t x)
{
    int tg=0;
    while (x>0)
    {
        tg+=(x%10)*(x%10);
        x/=10;
    }
    if (tt[tg]>tt[tg-1]) return true;
    return false;
}
int main()
{
    fi>>n;
    tt[0]=0;
    for (int i=1;i<=2000;i++)
        run1(i);
    for (int i=1;i<=n;i++)
    {
        fi>>L>>R;
        kq=0;
        for (int64_t k=L;k<=R;k++)
            if (kt(k)==false) kq++;
        fo<<kq<<endl;
    }
    return 0;
}
