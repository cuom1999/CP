#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Rep(i,a,b) for (int i=a; i<b; i++)
#define Ford(i,a,b) for (int i=a; i>=b; i--)
const int N=2005;
int n,kq,f[N],dx[N];
string s;
vector<int>ke[N];
queue <int> q;
bool bfs(int d)
{
    while (!q.empty()) q.pop();
    f[d]=0; dx[d]=d; q.push(d);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        Rep(i,0,ke[u].size())
        {
            int v=ke[u][i];
            if (v==d && f[u]==2) return true;
            if (dx[v]!=d)
            {
                f[v]=f[u]+1;
                dx[v]=d;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("rps.inp","r",stdin);
    freopen("rps.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> s;
        For(j,1,n) if (s[j-1]=='1')
            ke[i].push_back(j);
    }
    For(i,1,n) if (bfs(i)) kq++;
    cout << kq;
}
