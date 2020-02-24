#include <bits/stdc++.h>
using namespace std;
#define NMAX 2005
#define pb push_back
int n;
string s;
vector <int> win[NMAX],lose[NMAX];
bool fuckup[NMAX][NMAX];
bool need[NMAX];
int F[NMAX];
queue <int> q;
inline void bfs(int s){
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(F[u]==0){
            for(int v:win[u]){
                F[v]=1;
                q.push(v);
            }
            for(int v:lose[u]) F[v]=2;
        }
        else{
            for(int v:win[u]){
                if(F[v]==2){
                    need[s]=1;
                    need[u]=1;
                    need[v]=1;
                }
            }
        }
    }
}
int main(){
    freopen("RPS.inp","r",stdin);
    freopen("RPS.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(i!=j+1){
                if(s[j]=='0'){
                    lose[i].pb(j+1);
                }
                else{
                    win[i].pb(j+1);
                    fuckup[i][j+1]=1;
                }
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        memset(F,0,sizeof(F));
        bfs(i);
    }
    for(int i=1;i<=n;i++) res+=need[i];
    cout<<res<<'\n';
}

