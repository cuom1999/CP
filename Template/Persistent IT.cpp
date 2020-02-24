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

int ver[200005];
int nVer;
int nNode;

struct node{
    int Min,Max;
    int left,right;
}st[50005*4*30];

void refine (int id){
    st[id].Min=min(st[st[id].left].Min,st[st[id].right].Min);
    st[id].Max=max(st[st[id].left].Max,st[st[id].right].Max);
}

int update(int oldId, int l, int r, int u, int x){
    if (l==r){
        ++nNode;
        st[nNode].Min=st[nNode].Max=x;
        st[nNode].left=st[nNode].right=0;
        return nNode;
    }
    int mid=(l+r)/2;
    int cur=++nNode;

    if (u<=mid){
        st[cur].left=update(st[oldId].left, l, mid, u, x);
        st[cur].right=st[oldId].right;
    }
    else{
        st[cur].right=update(st[oldId].right, mid+1, r, u, x);
        st[cur].left=st[oldId].left;
    }
    refine (cur);
    return cur;
}

II get(int id, int l, int r, int u, int v){
    if (v<l || r<u) return II(0,INF);
    if (u<=l && r<=v){
        return II(st[id].Max,st[id].Min);
    }
    int mid=(l+r)/2;
    II A=get(st[id].left,l, mid, u,v);
    II B=get(st[id].right,mid+1,r,u,v);
    return II(max(A.first,B.first),min(A.second,B.second));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;

    FOR (i,1,n) {
        int x;
        cin>>x;
        ++nVer;
        ver[nVer]=update(ver[nVer-1],1,n,i,x);
    }
    FOR (i,1,q){
        int u,v;
        cin>>u>>v;
        II uu=get(ver[nVer],1,n,u,v);
        cout<<uu.first-uu.second<<endl;
    }


         return 0;
}
