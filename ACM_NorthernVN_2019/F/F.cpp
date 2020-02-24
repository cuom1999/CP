#include <bits/stdc++.h>
using namespace std;
long long w[305][305],f[305][305],kq[305][305],a[30005][4];
long long vis[305],pre,n,m;
vector <int> edge[305];
vector <long long> ruler;
void bfs(long long u , long long t)
{
    long long cur = ruler.size();
    for (long long i = pre ; i < cur ; i++)
    {
        long long v = ruler[i];
        f[u][v] = t-1;
        for (auto node : edge[v])
        {
            if (vis[node] != u)
            {
                ruler.push_back(node);
                vis[node] = u;
            }
        }
    }
    pre = cur;
    if (pre != ruler.size())
        bfs(u , t + 1);
}
int main()
{
    long long u,v,t;
    cin >> n >> m;
    for (long long i = 1 ; i <= m ; i++)
    {
        cin >> u >> v;
        cin >> t;
        if (w[u][v] == 0)
        {
            edge[u].push_back(v);
            edge[v].push_back(u);
            w[u][v] = w[v][u] = t;
        }    
        else
            w[u][v] = w[v][u] = min(w[u][v] , t);
        if (u > v) swap(u,v);
        kq[u][v] = w[u][v];
        a[i][1] = u;
        a[i][2] = v;
        a[i][3] = w[u][v];
    }
    for (long long i = 1 ; i <= n ; i++)
    {
        for (long long e = 1 ; e <= n ; e++)
        {
            kq[i][e] = 1e18;
        }
        kq[i][i] = 0;
    }
    for (long long i = 1 ; i <= n ; i++)
    {
        pre = 0;
        ruler.push_back(i);
        vis[i] = i;
        bfs(i,1);
        f[i][i] = 0;
        ruler.clear();
    }
    long long re = 0;
    for (long long t = 1 ; t <= m ; t++)
    {
        long long u = a[t][1];
        long long v = a[t][2];
        long long w = a[t][3];
        for (int i = 1 ; i <= n ; i++)
        {
            for (int e = i + 1 ; e <= n ; e++)
            {
                kq[i][e] = min(kq[i][e] , min((f[v][e] + f[u][i] + 1),(f[u][e] + f[v][i] + 1))*w);
            }
        }
    }
    int ok = 0;
        for (long long i = 1 ; i <= n ; i++)
        {
            for (long long e = i + 1 ; e <= n ; e++)
            {
                if (kq[i][e] != 1e18)
                {
                    re += kq[i][e];
                    
                    if (re >= 1000000000)
                    {
                        ok = 1;
                        re %= 1000000000;
                    }
                }
            }
        }
        if (ok == 0)
        {
            cout <<re;
            exit(0);
        }
    t = 0;
    long long asd = re;
    while (asd != 0)
    {
        t++;
        asd /= 10;
    }
    if (re == 0) t = 1;
    for (int i = 1 ; i <= 9 - t ; i++) cout <<0;
    cout <<re;
}