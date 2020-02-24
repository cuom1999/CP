#include <bits/stdc++.h>
using namespace std;
#define tag "RPS"
#define maxn 2107
int res;
int n;
deque<int> adj[maxn],stak;
int fre[maxn];
int nber[maxn],low[maxn],cnt,cnt_cpnt;
int crush;
void Init()
{
    fill(fre,fre+maxn,1);
    fill(nber,nber+maxn,0);
    cnt=0;
    cnt_cpnt=0;
}
void visit(int u) // u is root
{
    nber[u]=++cnt; low[u]=u; stak.push_front(u);
    for (int v : adj[u])
        if (fre[v])
        {
            if (nber[v]) low[u]=min(low[u],nber[v]);
            else visit(v),low[u]=min(low[u],low[v]);
        }
    if (nber[u]==low[u])
    {
        crush=0;
        ///cout << ++cnt_cpnt << " : ";
        while (stak.front()!=u)
        {
            ///cout << stak.front() << " ";
            ++crush;
            fre[stak.front()]=0;
            stak.pop_front();
        }
        ///cout << u << "\n";
        ++crush;
        fre[u]=0;
        stak.pop_front();
        /// ---->
        if (crush<3) res-=crush;
    }
}
int main()
{
    freopen(tag".inp","r",stdin); freopen(tag".out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int x,y;
    char ch;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        cin >> ch;
        if (ch=='1') adj[i].push_back(j);
    }
    Init();
    res=n;
    for (int u=1;u<=n;u++)
        if (nber[u]==0) visit(u);
    cout << res << "\n";
    return 0;
}
