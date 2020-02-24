#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1

using namespace std;

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int n,m;
const ll N=100000;
vector<II> v[50004];

int nVer,nNode;
int ver[100005];

struct node{
    int left,right;
    int val;
}st[100003*4*20];

int update(int oldID, int l, int r, int u){
    if (u==0) return 0;
    if (l==r){
        ++nNode;
        st[nNode].val=st[oldID].val+1;
        //st[nNode].val++;
        //cout<<st[nNode].val<<endl;
        st[nNode].left=st[nNode].right=0;
        return nNode;
    }
    int mid=(l+r)/2;
    int cur=++nNode;

    if (u<=mid){
        st[cur].left=update(st[oldID].left,l,mid,u);
        st[cur].right=st[oldID].right;
    }
    else{
        st[cur].left=st[oldID].left;
        st[cur].right=update(st[oldID].right,mid+1,r,u);
    }
    st[cur].val=st[st[cur].left].val+st[st[cur].right].val;
    //if (l<=4 && r>=4 && u==4) cout<<l<<" "<<r<<" "<<st[cur].val<<" "<<cur<<" "<<oldID<<endl;
    return cur;
}

int get (int id1, int id2, int id3, int id4, int l, int r, int k){
    if (l==r){
        return l;
    }
    int A=st[st[id2].left].val+st[st[id1].left].val;
    A-=(st[st[id3].left].val+st[st[id4].left].val);

    //cout<<l<<" "<<(l+r)/2<<" "<<st[st[id1].left].val<<" "<<st[st[id2].left].val<<" "<<st[st[id3].left].val<<" "<<st[st[id4].left].val<<endl;
    //cout<<l<<" "<<r<<" "<<A<<endl;
    int mid=(l+r)/2;
    if (A>=k){
        return get(st[id1].left,st[id2].left,st[id3].left,st[id4].left,l,mid,k);
    }
    else{
        k-=A;
        return get(st[id1].right,st[id2].right,st[id3].right,st[id4].right,mid+1,r,k);
    }
}

int h[50005], p[50005][19];
int e[50005];

void dfs(int a, int par){
    for (auto i:v[a]){
        if (i.first==par) continue;
        h[i.first]=h[a]+1;
        p[i.first][0]=a;
        e[i.first]=i.second;
        dfs(i.first,a);
    }
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

bool vs[50005];

void dfs2(int a){
    if (vs[a]) return ;
    dfs2(p[a][0]);
    //cout<<a<<" "<<e[a]<<endl;
    ver[a]=update(ver[p[a][0]],1,N,e[a]);
    vs[a]=1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
        cin>>n;
        FOR (i,1,n) {
            v[i].clear();
            vs[i]=0;
            h[i]=0; p[i][0]=0;
            ver[i]=0; nNode=0;
            nVer=0;
        }
        FOR (i,1,n-1){
            int x,y,c;
            cin>>x>>y>>c;
            v[x].pb(II(y,c));
            v[y].pb(II(x,c));
        }
        dfs(1,0);
        init();
        vs[0]=1;
        FOR (i,1,n){
            if (!vs[i]) dfs2(i);
        }
        //cout<<get(1,1,1,1,)
        //cout<<get(ver[2],ver[3],ver[2],ver[2],1,N,1)<<endl;
        //cout<<get(ver[5],ver[0],ver[0],ver[0],1,N,2)<<endl;
        //return 0;
        cin>>m;

        FOR (i,1,m){
            int u,v;
            cin>>u>>v;
            int w=LCA(u,v);
            int len=h[u]+h[v]-2*h[w];
            //cout<<len<<endl;
            if (len%2){
                int A=get(ver[u],ver[v],ver[w],ver[w],1,N,len/2+1);
                cout<<fixed<<setprecision(1)<<A*1.0<<endl;
            }
            else{
                int A=get(ver[u],ver[v],ver[w],ver[w],1,N,len/2+1);
                int B=get(ver[u],ver[v],ver[w],ver[w],1,N,len/2);
                ld C=(A+B)/2.0;
                cout<<fixed<<setprecision(1)<<C<<endl;
            }
            //cout<<A<<" ";
        }
    }


         return 0;
}
