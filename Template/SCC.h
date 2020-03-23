const int N=100005;

vector<int> v[N];

int num[N],low[N],vs[N];
int TIME,res;
vector<int> SCC[100005], STACK;

void dfs(int a){
    low[a]=num[a]=++TIME;
    STACK.pb(a);
    for (auto i:v[a]){
        if (!num[i]) dfs(i);
        if (!vs[i]) low[a]=min(low[a],low[i]);
    }

    if (num[a]==low[a]) {
        res++;
        while (STACK.size()){
            int b=STACK.back(); SCC[res].pb(b);
            STACK.pop_back();
            vs[b]=1;
            if (b==a) break;
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    sf("%d %d",&n,&m);
    FOR (i,1,m){
        int x,y;
        sf("%d%d",&x,&y);
        v[x].pb(y);
    }
    FOR(i,1,n){
        if (!num[i]) dfs(i);
    }
    //cout<<res<<endl;
    pf("%d",res);
    /*FOR (i,1,res){
        cout<<i<<" : ";
        for (auto j:SCC[i]) cout<<j<<" "; cout<<endl;
    }*/

    return 0;
}
