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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

struct node{
    vector<II> left, right;//left : suffix (value, cnt)
    ll cnt;
}st[400005];
int a[100005];

void debug(int id, int l, int r){
    cout<<id<<" "<<l<<" "<<r<<endl;
    cout<<"L: ";
    for (auto i:st[id].left) cout<<"("<<i.first<<" "<<i.second<<") "; cout<<endl;
    cout<<"R: ";
    for (auto i:st[id].right) cout<<"("<<i.first<<" "<<i.second<<") "; cout<<endl;
    cout<<"cnt: "<<st[id].cnt<<endl;
}

inline void add(int id, int id1, int id2){
    if (!st[id1].left.size()) {
        st[id] = st[id2];
        return ;
    }
    if (!st[id2].left.size()){
        st[id] = st[id1];
        return; 
    }
    node res;

    res.cnt = st[id1].cnt + st[id2].cnt;

    II u = st[id1].left.back();
    for (int i=0; i+1<st[id1].left.size(); i++){
        res.left.pb(st[id1].left[i]);
    }
    for (int i=0; i+1<st[id2].right.size(); i++){
        res.right.pb(st[id2].right[i]);
    }

    for (auto i:st[id2].left) {
        int g = __gcd(i.first,u.first);
        if (g!=u.first){
            res.left.pb(u);
            u.second=i.second;
        }
        else{
            u.second+=i.second;
        }
        u.first=g; 
    }
    res.left.pb(u);


    u = st[id2].right.back();

    for (auto i:st[id1].right) {
        int g = __gcd(i.first,u.first);
        if (g!=u.first){
            res.right.pb(u);
            u.second=i.second;
        }
        else{
            u.second+=i.second;
        }
        u.first=g; 
    }
    res.right.pb(u);

    int rt = st[id2].left.size()-1;

    int cur1 = 0 ;

    for (auto i: st[id2].left) cur1+=i.second;

    for (int lt=0; lt<st[id1].right.size(); lt++){
        int cur = st[id1].right[lt].second;
        while(rt>=0 && __gcd(st[id2].left[rt].first,st[id1].right[lt].first)==1){
            cur1-=st[id2].left[rt].second;
            rt--;
        }
        if (rt<0) break;
        res.cnt += cur*1ll*cur1;
    }
    st[id] = res;
}

void build (int id, int l, int r){
    if (l==r){
        st[id].left.pb(II(a[l],1)); 
        st[id].right.pb(II(a[l],1));
        if (a[l]>1) st[id].cnt=1;
        return ;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    add(id,id*2,id*2+1);
}

//a[u]=v
        
void update(int id, int l, int r, int u, int v){
    if (u<l || r<u) return ;
    if (l==r){
        node res;
        res.left.pb(II(v,1)); 
        res.right.pb(II(v,1));
        if (v>1) res.cnt=1;
        else res.cnt=0;
        st[id] = res;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    add(id,id*2,id*2+1);
}

void get(int id, int l, int r, int u, int v){
    if (v<l || r<u) return;
    if (u<=l && r<=v){
        add(0,0,id);
        return;
    }
    int mid=(l+r)/2;
    get(id*2, l, mid, u, v);
    get(id*2+1, mid+1, r, u, v);
}


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    FOR (i,1,n) cin>>a[i];
    build (1,1,n);

    FOR (z,1,q){
        int t,x,y;
        cin>>t>>x>>y;
        if (t==1){
            update(1,1,n,x,y);
        }
        else{
            get(1,1,n,x,y);
            cout<<st[0].cnt<<endl;
            st[0] = node();
        }
    }    
    
         return 0;
} 