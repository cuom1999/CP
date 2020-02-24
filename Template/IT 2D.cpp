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

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n;
char tmp[5];
string s;
ll st[4*1025][4*1025];

void update_y(int id_x, int id_y, int lx, int rx, int ly, int ry, int y, ll val){
    if (ly>y || ry<y) return;
    if (ly==ry){
        if (lx==rx){
            st[id_x][id_y]=val;
        }
        else{
            st[id_x][id_y]=st[id_x*2][id_y]+st[id_x*2+1][id_y];
        }
        //cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<" "<<st[id_x][id_y]<<endl;
        return ;
    }
    int mid=(ly+ry)/2;
    update_y(id_x, id_y*2, lx, rx, ly, mid, y, val);
    update_y(id_x, id_y*2+1, lx, rx, mid+1, ry, y, val);
    st[id_x][id_y]=st[id_x][id_y*2]+st[id_x][id_y*2+1];
    //cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<" "<<st[id_x][id_y]<<endl;
}

void update_x(int id_x, int lx, int rx, int x, int y, ll val){
    if (lx>x || rx<x) return ;
    if (lx==rx){
        //cout<<lx<<" "<<rx<<" AA"<<endl;
        update_y(id_x, 1, lx, rx, 0, n-1, y, val);
        return ;
    }
    int mid=(lx+rx)/2;
    update_x(id_x*2, lx, mid, x, y, val);
    update_x(id_x*2+1, mid+1,rx, x,y, val);
    update_y(id_x,1, lx, rx, 0,n-1,y,val);
    //update_y(id_x*2+1,1,0,n-1,y,val);
}

ll query_y (int id_x, int id_y, int ly, int ry, int y1, int y2){
    if (ly>y2 || ry<y1) return 0;
    if (y1<=ly && ry<=y2){
        //cout<<id_x<<" "<<ly<<" "<<ry<<" "<<st[id_x][id_y]<<endl;
        return st[id_x][id_y];
    }
    int mid=(ly+ry)/2;
    return query_y(id_x, id_y*2, ly, mid, y1, y2)+query_y(id_x, id_y*2+1, mid+1, ry, y1, y2);
}

ll query_x(int id_x, int lx, int rx, int x1, int x2, int y1, int y2){
    if (lx>x2 || rx<x1) return 0;
    if (x1<=lx && rx<=x2) {
        //cout<<lx<<" "<<rx<<" "<<id_x<<endl;
        return query_y(id_x, 1, 0, n-1, y1, y2);
    }
    int mid=(lx+rx)/2;
    return query_x(id_x*2, lx, mid, x1,x2,y1,y2)+ query_x(id_x*2+1, mid+1, rx, x1,x2,y1,y2);
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    //cin>>n;
        sf("%d",&n);
        while (1){
            sf("%s",tmp);
            s=tmp;
            if (s=="END") break;
            if (s=="SET"){
                int x,y; ll c;
                //cin>>x>>y>>c;
                sf("%d %d %lld",&x,&y,&c);
                update_x(1,0,n-1,x,y,c);
            }
            else{
                int x1,x2,y1,y2;
                //cin>>x1>>y1>>x2>>y2;
                sf("%d %d %d %d",&x1,&y1,&x2,&y2);
                //cout<<query_x(1,0,n-1,x1,x2,y1,y2)<<endl;
                pf("%lld\n",query_x(1,0,n-1,x1,x2,y1,y2));
            }
        }

         return 0;
}
