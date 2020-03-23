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

ll L=1,R=0;

int S,n,q;
int a[200005],cnt[2000005];

struct query{
    int l,r,stt;
}Q[200005];

int cmp(query a,query b){
	if(a.l/S !=b.l/S)
		return (a.l < b.l);
	return ((a.l/S)&1) ? (a.r<b.r) : (a.r>b.r);
}


ll Ans=0;

void add(int x){
    Ans-=cnt[x]*1LL*cnt[x]*x;
    cnt[x]++;
    Ans+=cnt[x]*1LL*cnt[x]*x;
}

void sub(int x){
    Ans-=cnt[x]*1LL*cnt[x]*x;
    cnt[x]--;
    Ans+=cnt[x]*1LL*cnt[x]*x;
}
ll res[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //cin>>n>>q;
    sf("%d %d",&n,&q);
    S=sqrt(n); // optimal when S = n/sqrt(q);
    FOR (i,1,n) sf("%d",&a[i]);
    FOR (i,1,q) {
        //cin>>Q[i].l>>Q[i].r;
        sf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].stt=i;
    }
    sort(Q+1,Q+q+1,cmp);

    FOR (i,1,q){
        while (R>Q[i].r) {
            sub(a[R]);
            R--;
        }
        while (R<Q[i].r){
            R++;
            add(a[R]);
            //cout<<R<<" "<<Ans<<endl;
        }

        while (L<Q[i].l) {
            sub(a[L]);
            L++;
            //cout<<Ans<<endl;
        }
        while (L>Q[i].l){
            L--;
            add(a[L]);
        }

        res[Q[i].stt]=Ans;
    }
    //FOR (i,1,q) cout<<res[i]<<endl;
    FOR (i,1,q) pf("%lld \n",res[i]);



         return 0;
}
