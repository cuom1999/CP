#include <bits/stdc++.h>

using namespace std;
ifstream fi ("pearl.inp");
ofstream fo ("pearl.out");
int t;
long long l,r;
int d[1500];
long long check(long long x)
{
    int sum=0;
    long long k=x;
    while (k>0)
    {
        int v=k%10;
        sum=sum+v*v;
        k=k/10;
    }
    if(sum==1) return 1;
    if(d[sum]==1) return 0;
    return sum;
}
int main()
{
    fi>>t;
    for (int p=1;p<=t;p++)
    {
        long long l,r;
       int dem=0;
       fi>>l>>r;
       for (long long i=l;i<=r;i++)
            {
                for (int i=1;i<=1500;i++)
                    d[i]=0;
                if(i<1500) d[i]=1;
                long long a=i;
                while(1)
                {
                    a=check(a);
                    if(a==0) {dem++;break;}
                    else d[a]=1;
                    if(a==1) break;
                }
            }
            fo<<dem<<endl;
    }
    return 0;
}
