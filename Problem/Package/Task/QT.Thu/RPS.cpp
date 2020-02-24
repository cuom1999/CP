#include<bits/stdc++.h>

using namespace std;

const int N=2e3+1;

int a[N][N],n;
string s;
vector<int> adj[N];
int main(){
        freopen("RPS.inp", "r", stdin);
        freopen("RPS.out", "w", stdout);
           ios_base::sync_with_stdio(0);
            cin.tie(0);cout.tie(0);
            cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>s;s=" "+s;
             for(int j=1;j<=n;j++)
                if (s[j]=='1') {
                        a[i][j]=1;
                        adj[i].push_back(j);
                }
        }
        int ans=0;
        for(int i=1;i<=n;i++){ bool ok=0;
            for(int j=0;j<adj[i].size();j++){
                    int u=adj[i][j];
            for(int k=0;k<adj[u].size();k++){
                    int v=adj[u][k];
                 if (a[v][i] && v!=u) {
                        ans++;ok=1;
                        break;
                 }
            }
             if (ok) break;
            }
        }
            cout<<ans;
}
