#include <bits/stdc++.h>

using namespace std;

multiset<pair<int,int> > s;
vector<int> p[4001];
int n,a[4],ans;
bool kt[4001],tra[4001];

void tinh()
{
    if(s.count(make_pair(a[3],a[1]))>0)
    {
        tra[a[1]]=true; tra[a[2]]=true; tra[a[3]]=true;
    }
}

void dfs(int k, int n)
{
    if(n>3) {tinh(); return;}
    if(!kt[k]) return;
    kt[k]=false;
    a[n]=k;
    for(int i=0; i<p[k].size(); ++i) dfs(p[k][i],n+1);
    kt[k]=true;
}

int main()
{
    freopen("RPS.INP","r",stdin);
    freopen("RPS.OUT","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        string str;
        cin>>str;
        str=' '+str;
        for(int j=1; j<=n; ++j)
            if(str[j]=='1')
        {
            p[i].push_back(j);
            s.insert(make_pair(i,j));
        }
    }
    int ans=n;
    memset(kt,true,sizeof(kt));
    memset(tra,false,sizeof(tra));
    for(int i=1; i<=n; ++i) dfs(i,1);
    for(int i=1; i<=n; ++i) if(!tra[i]) --ans;
    cout<<ans;
}
