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
#define ll unsigned long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)
using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
int n=5000,m=5000,q;
ll fen[5005][5005];
void add(int x, int y, ll k){
    for (int i=x; i<=n; i+=i&-i){
        for (int j=y; j<=m; j+=j&-j){
            fen[i][j]+=k;
        }
    }
}

ll get(int x, int y){
    ll res=0;
    for (int i=x; i; i-=i&-i){
        for (int j=y; j; j-=j&-j){
            res+=fen[i][j];
        }
    }
    return res;
}


ll Rand()
{
    return 1 + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand());
}

struct data{
    int x1,y1,x2,y2;
    ll val;
    data(int _x1=0, int _y1=0, int _x2=0, int _y2=0, ll _val=0){
        x1=_x1; y1=_y1;
        x2=_x2; y2=_y2;
        val=_val;
    }
} datas[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    cin>>q;
    FOR (z,1,q){
        int t,x1,y1,x2,y2;
        cin>>t;
        if (t==1){
            cin>>x1>>y1>>x2>>y2;
            if (x1>x2) swap(x1,x2);
            if (y1>y2) swap(y1,y2);

            ll u=Rand();

            datas[z]=data(x1,y1,x2,y2,u);

            add(x1,y1,u);
            add(x1,y2+1,-u);
            add(x2+1,y1,-u);
            add(x2+1,y2+1,u);
        }
        else if (t==2){
            int j;
            cin>>j;
            
            x1=datas[j].x1;
            y1=datas[j].y1;
            x2=datas[j].x2;
            y2=datas[j].y2;
            ll u=-datas[j].val;

            add(x1,y1,u);
            add(x1,y2+1,-u);
            add(x2+1,y1,-u);
            add(x2+1,y2+1,u);
        }
        else{
            cin>>x1>>y1>>x2>>y2;
            ll A=get(x1,y1);
            ll B=get(x2,y2);
            if (A==B){
                cout<<"Y";
            }
            else cout<<"N";
        }
    }


         return 0;
}