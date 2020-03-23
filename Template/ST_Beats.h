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
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

struct node{
    int max, secondMax, maxNum, lz;
    ll sum;
}st[4000005];

int a[1000005];

inline int max(int a, int b){
    if (a<b) return b;
    return a;
}

inline int min(int a, int b){
    if (a<b) return a;
    return b;
}

inline void update(int id){
    st[id].max = st[id*2].max;
    
    if (st[id*2].max==st[id*2+1].max){
        st[id].maxNum = st[id*2].maxNum + st[id*2+1].maxNum;
        st[id].max = st[id*2].max;
        st[id].secondMax = max(st[id*2].secondMax,st[id*2+1].secondMax);
    }
    else if (st[id*2].max>st[id*2+1].max){
        st[id].maxNum = st[id*2].maxNum;
        if (st[id*2].secondMax>st[id*2+1].max){
            st[id].secondMax = st[id*2].secondMax;
        }
        else{
            st[id].secondMax = st[id*2+1].max;
        }
    }
    else{
        st[id].maxNum = st[id*2+1].maxNum;
        st[id].max = st[id*2+1].max;
        if (st[id*2+1].secondMax>st[id*2].max){
            st[id].secondMax = st[id*2+1].secondMax;
        }
        else{
            st[id].secondMax = st[id*2].max;
        }
    }

    st[id].sum = st[id*2].sum + st[id*2+1].sum;
}

void build (int id, int l, int r){
    if (l==r){
        st[id].max = a[l];
        st[id].secondMax = -1;
        st[id].sum = a[l];
        st[id].maxNum = 1;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    update(id);
    st[id].lz=-1;
}

void down(int id, int l, int r){
    if (l==r || st[id].lz==-1) return ;
    int x = st[id].lz;
    if (st[id*2].max>x){
        st[id*2].sum-= st[id*2].maxNum*1ll*(st[id*2].max-x);
        st[id*2].max = x;
        st[id*2].lz = x;
    }
    if (st[id*2+1].max>x){
        st[id*2+1].sum-= st[id*2+1].maxNum*1ll*(st[id*2+1].max-x);
        st[id*2+1].max = x;
        st[id*2+1].lz = x;
    }
    st[id].lz=-1;
}

// a[l]->a[r] = min(a[i],x);
void update1(int id, int l, int r, int u, int v, int x){
    if (v<l || r<u || st[id].max<=x){
        return ;
    }
    if (u<=l && r<=v && st[id].secondMax<x){
        st[id].sum-= st[id].maxNum*1ll*(st[id].max-x);
        st[id].max = x;
        st[id].lz = x;
        return ;
    }
    down(id,l,r);
    int mid=(l+r)/2;
    update1(id*2,l,mid,u,v,x);
    update1(id*2+1,mid+1,r,u,v,x);
    update(id);
}

int getMax(int id, int l, int r, int u, int v){
    if(v<l || r<u) return -1;
    if (u<=l && r<=v) return st[id].max;
    down(id,l,r);
    int mid=(l+r)/2;
    return max(getMax(id*2,l,mid,u,v),getMax(id*2+1,mid+1,r,u,v));
}

ll getSum(int id, int l, int r, int u, int v){
    if (v<l || r<u) return 0;
    if (u<=l && r<=v) return st[id].sum;
    down(id,l,r);
    int mid = (l+r)/2;
    return getSum(id*2,l,mid,u,v)+getSum(id*2+1,mid+1,r,u,v);
}


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    sf("%d",&t);
    FOR (zz,1,t){
        int n,m;
        sf("%d%d",&n,&m);
        FOR (i,1,n) sf("%d",&a[i]);
        build (1,1,n);

        FOR (z,1,m){
            int t;
            sf("%d",&t);
            if (t==0){
                int l,r,x;
                sf("%d%d%d",&l,&r,&x);
                update1(1,1,n,l,r,x);
            }
            else if (t==1){
                int l,r;
                sf("%d%d",&l,&r);
                pf("%d\n",getMax(1,1,n,l,r));
            }
            else{
                int l,r;
                sf("%d%d",&l,&r);
                pf("%lld\n",getSum(1,1,n,l,r));
            }
        }
    }
        
    
         return 0;
}