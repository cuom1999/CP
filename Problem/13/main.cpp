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

/* Cho mang a. Co 2 operations :
1 k b: gan a[k]=b
2 l r: Tinh so tap con khac rong cua a[l]->a[r] co tong chia het cho 2.
*/

int fen[100005];
int n,q;

void add(int u, int v){
    for (int i=u; i<=n ;i+=i&-i){
        //cout<<i<<endl;
        fen[i]+=v;
    }
}

int sum(int u){
    int res=0;
    for (int i=u;i ; i-=i&-i) res+=fen[i];
    return res;
}

int sum (int u, int v){
    return sum(v)-sum(u-1);
}

const ll K=1e9+7;
int a[100005];
ll mu[100005];
int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    mu[0]=1;
    FOR (i,1,100000) mu[i]=mu[i-1]*2%K;
    cin>>n>>q;
    FOR (i,1,n) {
        cin>>a[i];
        if (a[i]%2) add(i,1);
    }
    int cnt=0;
    FOR (i,1,q){
        int t;
        cin>>t;
        if (t==1){
            int k,b;
            cin>>k>>b;
            if (a[k]%2==0) {
                if (b%2) {
                    add(k,1);
                }
            }
            else{
                if (b%2==0) add(k,-1);
            }
            a[k]=b;
        }
        else{
            int l, r;
            cnt++;
            cin>>l>>r;
            //if (cnt!=5612) continue;
            if (sum(l,r)){
                cout<<(mu[r-l]+K-1)%K<<endl;
            }
            else{
                cout<<(mu[r-l+1]+K-1)%K<<endl;
            }
            //cout<<l<<" "<<r<<" "<<a[l]<<endl;
        }
    }




         return 0;
}
