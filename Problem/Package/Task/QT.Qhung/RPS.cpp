#include <bits/stdc++.h>

using namespace std;
    const int maxn=2005;
    vector < int > adj[maxn];
    char c[maxn][maxn];
    int n,sum;
    bool used[maxn];
int main()
{
    freopen("RPS.inp","r",stdin);
    freopen("RPS.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin>>c[i][j];
            if (c[i][j]=='1')
                adj[i].push_back(j);
        }
    memset(used,true,sizeof(used));
    for (int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end());
    sum=0;
    bool kt;
    for (int i=1; i<=n; i++)
    {
      if (used[i]==true)
        {
           kt=true;
           for (int j=0; j<adj[i].size(); j++)
               {
                int u=adj[i][j];
                if (kt==false)
                    break;
                for (int k=0; k<adj[u].size(); k++)
                     {
                     int v=adj[u][k];
                     if (binary_search(adj[v].begin(),adj[v].end(),i))
                     {
                         used[i]=false;
                         used[u]=false;
                         used[v]=false;
                         kt=false;
                         break;
                     }
                     }
               }
        }
    }
    for (int i=1; i<=n; i++)
        if (used[i]==false)
          sum=sum+1;
    cout<<sum;
}
