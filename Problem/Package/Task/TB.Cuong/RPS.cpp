#include <bits/stdc++.h>

using namespace std;
ifstream fi ("RPS.INP");
ofstream fo ("RPS.OUT");

int const maxn=2001;
int N;
char a[maxn][maxn];
vector <int> g[maxn];
vector <bool> d(maxn,true);
int dem=0;
bool Check;

void NhapDL()
{
    fi>>N;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
        {
            fi>>a[i][j];
            if (a[i][j]=='1')
            {
//                fo<<i<<" "<<j<<endl;
                g[i].push_back(j);
            }
        }
}

void BFS(int s)
{
    queue <int> q;
    q.push(s);
    d[s]=false;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int j=0; j<g[u].size(); j++)
        {
            int v=g[u][j];
            if (v==s)
            {
                Check=true;
                break;
            }
            if (d[v]==true)
            {
                dem++;
                q.push(v);
                d[v]=false;
            }
        }
        if (g[u].size()==0) dem--;
    }
    dem=dem+1;
//    fo<<dem<<endl;
}

void Xuli()
{
    Check=false;
    for (int i=1; i<=N; i++)
        if (d[i]==true)
        {
            BFS(i);
        }
    if (dem>2 && Check==true)
        fo<<dem<<endl;
    else
        fo<<0;
}

int main()
{
    NhapDL();
    Xuli();
}
