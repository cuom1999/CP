#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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
typedef pair < ll, ll > II;


struct Node{
    ll max, secondMax, maxNum, lz;
    int maxIndex;
}st[400005];

int a[100005];

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
        st[id].maxIndex = st[id * 2].maxIndex;
    }
    else if (st[id*2].max>st[id*2+1].max){
        st[id].maxNum = st[id*2].maxNum;
        st[id].maxIndex = st[id * 2].maxIndex;
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
        st[id].maxIndex = st[id * 2 + 1].maxIndex;
        if (st[id*2+1].secondMax>st[id*2].max){
            st[id].secondMax = st[id*2+1].secondMax;
        }
        else{
            st[id].secondMax = st[id*2].max;
        }
    }
}

void build (int id, int l, int r){
    // cout << id << " " << l << " " << r << " B" << endl;
    if (l==r){
        st[id].max = a[l];
        st[id].secondMax = -1e18;
        st[id].maxNum = 1;
        st[id].maxIndex = l;
        // cout << id << " " << st[id].max << endl;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    update(id);
    // cout << l << " " << r << " " << st[id].max << endl;
    st[id].lz=-1;
}

void down(int id, int l, int r){
    if (l==r || st[id].lz == -1) return ;
    int x = st[id].lz;
    if (st[id*2].max > x){
        st[id*2].max = x;
        st[id*2].lz = x;
    }
    if (st[id*2+1].max>x){
        st[id*2+1].max = x;
        st[id*2+1].lz = x;
    }
    st[id].lz=-1;
}

// a[l]->a[r] = min(a[i],x);
void update1(int id, int l, int r, int u, int v, ll x){
    // cout << id << " " << l << " " << r << " " << u << " " << v << endl;
    if (v<l || r<u || st[id].max<=x){
        return;
    }
    if (u <= l && r <= v && st[id].secondMax < x){
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

II getMax(int id, int l, int r, int u, int v){
    if(v<l || r<u) return {-1e18, -1e18};
    if (u<=l && r<=v) {
        return {st[id].maxIndex, st[id].max};
    }
    down(id,l,r);
    int mid=(l+r)/2;
    II u1 = getMax(id * 2,l,mid,u,v);
    II u2 = getMax(id * 2+1,mid+1,r,u,v);

    if (u1.second == u2.second) {
        return {u1.first, u1.second};
    }
    if (u1.second > u2.second) {
        return u1;
    }
    return u2;
}

ll res[100005];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    ll p;
    cin >> n >> p;

    vector<II> v;
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] = -a[i];
    }

    build(1, 1, n);

    ll currTime = 0;

    FOR (i, 1, n) {
        int person = st[1].maxIndex;
        ll time = st[1].max;
        time = min(time, currTime);
        // cout << person << " " << time << endl;
        update1(1, 1, n, person + 1, n, time - p);
        update1(1, 1, n, person, person, -1e17);
        // cout << p << endl;
        res[person] = -time + p;
        currTime = -res[person];
        // cout << p << " " << time << endl;
    }

    FOR (i, 1, n) cout << res[i] << " ";
    return 0;
}