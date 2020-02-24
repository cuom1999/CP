#include <bits/stdc++.h>

using namespace std;
ifstream fi ("PEARL.INP");
ofstream fo ("PEARL.OUT");

int T;
int64_t L,R;
int ans;

int64_t BienDoi(int64_t x)
{
    int64_t kq=0;
    while (x>0)
    {
        kq+=(x%10)*(x%10);
        x=x/10;
    }
    return kq;
}

bool Check(int64_t x)
{
    if (x==10||x==100||x==1000)
        return true;
    return false;
}

void Xuli(int64_t x)
{
    int z=0;
    while (x!=1 && z!=15)
    {
        z++;
        x=BienDoi(x);
//        fo<<x<<" ";
        if (Check(x))
        {
            ans++;
            return;
        }
    }
//    fo<<endl;
}

int main()
{
    fi>>T;
    for (int k=1; k<=T; k++)
    {
        fi>>L>>R;
        ans=0;
        for (int64_t i=L; i<=R; i++)
            Xuli(i);
        fo<<R-L-ans+1;
    }
}
