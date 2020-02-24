#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

/* DE BAI:
    n thi sinh tham gia 1 ky thi duoc danh so bao danh tu 1->n. Sau khi co diem thi, ban to chuc cong bo BXH
    theo thu tu tu cao den thap. 2 thi sinh bang diem thi dong hang. OMO di xem BXH chung cuoc va ghi chep lai
    thu hang cua tung nguoi. Tuy nhien luc ve, OMO lai khong tim thay to giay ghi chep dau. Du vay, OMO van nho
    duoc thu hang cua 1 so thi sinh. Ban hay tinh xem co bao nhieu BXH dap ung dung nhu quy che cuoc thi va tri
    nho cua OMO.
    Luu y: Neu co dung 2 nguoi dong hang 1 thi ko co nguoi hang 2. Nguoi diem cao tiep theo se dung hang 3.
*/
const ll K=(ll) 1e9+7;

ll gt[100005],rev[100005],H[100005];

ll mu(ll a, ll n){
    if (n==0) return 1;
    ll q=mu(a,n/2);
    if (n%2==0) return q*q%K;
    return q*q%K*a%K;
}

inline ll Combi(ll n, ll k){
    if (k>n) return 0;
    return gt[n]*rev[n-k]%K*rev[k]%K;
}

vector <ll> S;
ll d[100005],e[100005],t[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0]=1;
    rev[0]=1;
    FOR (i,1,5005){
        gt[i]=gt[i-1]*i%K;
        rev[i]=mu(gt[i],K-2);
    }
    H[0]=1;
    FOR (i,1,5000){
        FOR(j,1,i){
            H[i]=(H[i]+Combi(i,j)*H[i-j]%K)%K;
        }
    }

    ll m,n;
    cin>>n>>m;
    FOR (i,1,m){
        ll a,tt;
        cin>>a>>tt;
        d[tt]++;
        if (d[tt]==1) S.pb(tt);
    }
    d[n+1]=n-m;
    S.pb(n+1);
    sort(S.begin(),S.end());
    ll M=S.size();
    M--;
    e[0]=S[0]-1;
    ll sum=e[0];
    for (ll u=1; u<S.size(); u++){
        //cout<<S[u]<<" ";
        e[u]=S[u]-1-sum-d[S[u-1]];
        sum+=e[u]+d[S[u-1]];
    }
    //for (auto i: S) cout<<i<<" ";
    //cout<<endl;
    FOR (i,0,M){
        if (e[i]<0){
            cout<<0; return 0;
        }
        //cout<<e[i]<< " ";
    }
    //cout<<endl;
    /*
    t[0]=(S[0]-1);
    FOR (i,1,M){
        t[i]=S[i]-S[i-1];
    }   
    FOR (i,0,M) cout<<t[i]-e[i]<<" ";
    cout<<endl;
    */
    ll res=1;
    FOR (i,0,m){
        res=(res*H[e[i]])%K;
        if (e[i]!=0 && i>0) {
            res=(res*2)%K;
        }
    }
    res=(res*gt[n-m])%K;
    FOR (i,0,m){
        res=(res*rev[e[i]])%K;
    }
    cout<<res<<endl;
    //cout<<H[n];


         return 0;
}
