#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forv(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n,dx[2001],times=1,dem,dd[2001],tr[2001];
vector<int>ke[2001];
char c;
void dfs(int u,int p,int x)
{
   dx[u]=times;
   x++;
   for(int v:ke[u])
   {
      if(x<3)
      {
         if(dx[v]!=times)
         {
            tr[v]=u;
            dfs(v,p,x);
         }
      }
      else
      if(x==3&&v==p)
      {
         if(!dd[u]) dem++,dd[u]=1;
         if(!dd[v]) dem++,dd[v]=1;
         if(!dd[tr[u]]) dem++,dd[tr[u]]=1;
      }
   }
}
void xl()
{
   For(x,1,n)
      {
         times++;
         dfs(x,x,0);
      }
   cout<<dem;
}
int main()
{
    freopen("rps.inp","r",stdin);
    freopen("rps.out","w",stdout);
   cin>>n;
   For(i,1,n)
      For(j,1,n)
      {
         c=getchar();
         if(c=='\n') c=getchar();
         if(i==j) continue;
         if(c=='1') ke[i].push_back(j);
      }
   xl();
}
