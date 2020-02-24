#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;

int res=0;
int n;
vector<int> a[2005];
vector<int> g;
int ex[2005];
int dd[2005];
int low[2005];
int number[2005];
int chay=0;
int dem[2005];
void DFS(int u)
{
    dd[u]=1;
    g.push_back(u);
    chay++;number[u]=chay;
    low[u]=chay;
    FOR(i,0,(int)a[u].size()-1)
    {
        int v=a[u][i];
        if (ex[v]==1) continue;
        if (dd[v]==0)
        {
            dd[v]=1;
            DFS(v);
            low[u]=min(low[v],low[u]);
        }
        else
        low[u]=min(low[u],low[v]);
    }
}
int aa[205][205];
int degam[2005],degduong[2005];
int kt[2005];
char k;
int main()
{
    freopen("RPS.INP","r",stdin);
    freopen("RPS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    if (n>200)
    {
    FOR(i,1,n)
        FOR(j,1,n)
        {
            cin>>k;
            if (i==j) continue;
            if (k=='0')
                a[i].push_back(j);
           // else if (k=='1') a[j].push_back(i);
        }
    FOR(i,1,n)
    if (dd[i]==0)
    {
        DFS(i);
        FOR(i,0,(int)g.size()-1) ex[g[i]]=1;
        g.clear();
    }
    FOR(i,1,n) dem[low[i]]++;
    int mx=0;
    FOR(i,1,n) mx=max(mx,dem[i]);
    FOR(i,1,n) cout<<i<<" "<<low[i]<<endl;
    if (mx>2) cout<<mx;
    else cout<<"0";
    return 0;
    }



    FOR(i,1,n)
        FOR(j,1,n)
        {
            cin>>k;
            if (i==j) continue;
            if (k=='1')
                degduong[i]++,degam[j]++,aa[i][j]=1;

        }

    FOR(i,1,n)
    {
        int kiemtra=1;
        FOR(j,1,n)
        {

            if (kt[j]==1) continue;
            if (degduong[j]==0||degam[j]==0)
                {
                    kiemtra=0;
                    kt[j]=1;
                    FOR(h,1,n)
                    {
                        if (j==h &&kt[h]==1) continue;
                        if (aa[j][h]==1)
                            degam[h]--;else degduong[h]--;
                    }

                }
                if (kiemtra==0) break;
        }
            if (kiemtra) break;
    }
    int ddd=0;
    FOR(i,1,n) if (kt[i]==0) ddd++;
    cout<<ddd;




}
