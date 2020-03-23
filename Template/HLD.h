
/// Remember dfs and hld first

const ll N=100005;

int nChain=1, chainHead[N], chainInd[N],p[N][20],sub[N],pos[N],h[N];
int nBase;
int n;
vector<int> v[N];
vector<int> Base;

void dfs(int a, int par){
    sub[a]=1;
    for (auto i:v[a]){
        if (i==par) continue;
        p[i][0]=a;
        h[i]=h[a]+1;
        dfs(i,a);
        sub[a]+=sub[i];
    }
}

void hld(int a, int par){
    if (chainHead[nChain]==0) chainHead[nChain]=a;
    chainInd[a]=nChain;
    pos[a]=++nBase;
    Base.pb(a);

    int mx=-1;
    for (auto i:v[a]){
        if (i!=par){
            if (mx==-1 || sub[mx]<sub[i]) mx=i;
        }
    }
    if (mx>-1) hld(mx,a);
    for (auto i:v[a]){
        if (i!=par && i!=mx){
            nChain++;
            hld(i,a);
        }
    }
}

int query(int a, int u){ // u la LCA cua a
    int ac=chainInd[a];
    int uc=chainInd[u];
    int res=0;
    while (1){
        if (uc==ac){
            res=max(res,get(1,1,n,pos[u],pos[a]));
            break;
        }
        res=max(res,get(1,1,n,pos[chainHead[ac]],pos[a]));
        a=p[chainHead[ac]][0];
        ac=chainInd[a];
    }
    return res;
}

void init(){
    FOR (i,1,18){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}

int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,17,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}
