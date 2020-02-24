#include <bits/stdc++.h>

using namespace std;
const long N=9*9*19;
long long f[20][N];
long d[N];
vector<long>v;
long S(long long x)
{
    long res=0;
    while(x>0)
    {
        res+=(x%10)*(x%10);
        x/=10;
    }
    return res;
}
void kkk(long x)
{
    if(d[x]==1)
        return;
    d[x]=-1;
    long s=S(x);
    if(d[s]==-1)
    {
        d[x]=0;
        return;
    }
    kkk(s);
    d[x]=d[s];
}
void kt()
{
    f[0][0]=1;
    for(long i=1;i<=19;++i)
    {
        for(long j=0;j<N;++j)
        {
            for(long k=0;k<=9;++k)
            {
                if(j>=k*k)
                    f[i][j]+=f[i-1][j-k*k];
            }
        }
    }
    d[1]=1;
    for(long i=1;i<N;++i)
    {
        kkk(i);
        if(d[i])
            v.push_back(i);
    }
}
long long zz(long long x)
{
    stringstream st;
    st<<x;
    string s=st.str();
    long res=0,n,k,g;
    long long ans=0;
    n=s.size();
    for(long j=0;j<v.size();++j)
    {
        res=v[j];
        for(long i=0;i<n;++i)
        {
            k=s[i]-'0';
            if(k==0)continue;
            g=1e9;
            for(long z=0;z<k;++z)
            {
                if(z*z>res)continue;
                g=z*z;
                if(res>=g)
                ans=ans+f[n-i-1][res-g];
            }
            res=res-k*k;
        }
    }
    return ans;
}
void lam()
{
    long t;
    cin>>t;
    long long l,r,ans;
    while(t--)
    {
        cin>>l>>r;
        ans=zz(r+1)-zz(l);
        ans=(r-l+1)-ans;
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    kt();
    lam();
    return 0;
}
