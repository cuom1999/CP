#include <bits/stdc++.h>

using namespace std;

int T,F[1000001];
int64_t minl,maxr,L[101],R[101];

bool kt(int x)
{
    int d=0;
    while (x>=10)
    {
        int64_t tong=0; d++;
        while (x>0) {int nho=x%10; tong+=nho*nho; x/=10;}
        x=tong;
    }
    if (x==1 || x==7) return false; else return true;
}

void xuly1()
{
    F[minl-1]=0;
    for (int i=minl; i<=maxr; i++)
        if (kt(i)) F[i]=F[i-1]+1; else F[i]=F[i-1];
    for (int i=1; i<=T; i++) cout<<F[R[i]]-F[L[i]-1]<<"\n";
}

void xuly2()
{
    for (int i=1; i<=T; i++)
    {
        int dem=0;
        for (int j=L[i]; j<=R[i]; j++)
            if (kt(j)) dem++;
        cout<<dem<<"\n";
    }
}

int main()
{
    freopen("PEARL.inp","r",stdin);
    freopen("PEARL.out","w",stdout);
    cin>>T; minl=1e9; maxr=-1e9;
    for (int i=1; i<=T; i++)
    {
        cin>>L[i]>>R[i]; minl=min(minl,L[i]); maxr=max(maxr,R[i]);
    }
    if (maxr<=1e6) xuly1(); else xuly2();
}
