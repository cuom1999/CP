#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=205;
int t;
bool f[N];
//=====================================================================
void file()
{
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
//=====================================================================
string convert(int x)
{
    string str;
    while(x>0)
    {
        char k=(x%10)+48;
        x/=10;
        str=k+str;
    }
    return str;
}
int cal(string x)
{
    int sum=0;
    fo(i,0,x.length()-1)
    {
        int tmp=x[i]-48;
        sum+=tmp*tmp;
    }
    return sum;
}
//=====================================================================
bool bd(int k,int x)
{
    string str=convert(x);
    int tmp=cal(str);
    if(tmp==1)
    {
        return true;
    }
    if(k>100)
    {
        return false;
    }
    return bd(k+1,tmp);
}
//=====================================================================
void solve()
{
    fo(i,1,200) f[i]=bd(1,i);
    while(t--)
    {
        int l,r,res;
        res=0;
        cin>>l>>r;
        fo(i,l,r)
        {
            string str=convert(i);
            int tmp=cal(str);
            str=convert(tmp);
            tmp=cal(str);
            str=convert(tmp);
            tmp=cal(str);
            if(!f[tmp]) res++;
        }
        cout<<res<<endl;
    }
}
//=====================================================================
void read()
{
    cin>>t;
    solve();
}
//=====================================================================
int main()
{
    file();
    read();
}
//=====================================================================

