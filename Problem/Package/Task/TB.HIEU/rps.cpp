#include <bits/stdc++.h>

using namespace std;
ifstream fi("rps.inp");
ofstream fo("rps.out");
int n;
char temp;
vector <int> thang[2001];
vector <int> thua[2001];
set <int> t2[2001];
int tt[2001]={0};
int kq=0;
void xuli(int i)
{
    int tg1,tg2;
    for (int k=0;k<thang[i].size();k++)
    {
        tg1=thang[i][k];
        for (int h=0;h<thua[i].size();h++)
        {
            tg2=thua[i][h];
            if (t2[tg2].count(tg1)==0) t2[tg2].insert(tg1);
        }
    }
}
int main()
{
    fi>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
    {
        fi>>temp;
        if (i<j)
        {
            if (temp=='1')
            {
                thang[i].push_back(j);
                thua[j].push_back(i);
            }
            if (temp=='0')
            {
                thang[j].push_back(i);
                thua[i].push_back(j);
            }
        }
    }
    for (int i=1;i<=n;i++)
        xuli(i);
    int tg;
    for (int i=1;i<=n;i++)
        if (tt[i]==0)
    {
        for (int k=0;k<thua[i].size();k++)
        {
            tg=thua[i][k];
            if (t2[i].count(tg)==1) {tt[i]=1;tt[tg]=1;break;}
        }
        if (tt[i]==0) kq++;
    }
    fo<<n-kq;
    return 0;
}
