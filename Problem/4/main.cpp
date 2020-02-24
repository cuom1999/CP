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

ld lgt[4000005];


inline ld logCombi(ll n, ll k){
    if (k>n) return -1;
    return (ld ) (lgt[n]-lgt[k]-lgt[n-k]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    lgt[1]=0.0;
    FOR (i,2,4000000) lgt[i]=lgt[i-1]+log(i);
    ll m,n,d,d0;

    cin>>m>>n>>d0;
    bool qq=0;
    //if (m==0 && n==0) return 0;
    if (m*n>0){
    if (m>n) {swap(m,n);qq=1;}
    ld sum=0;
    //cout<<d<<endl;
    if (d0<n-m){cout<<"You can't do it!"<<endl; return 0;}
    ll u=max(1LL,n-d0);
    ld s=0;
    ld sum1=0;
    FOR (k,u,m){
        s=max(s,logCombi(m-1,k-1)+logCombi(n-1,k-1)-log(k));
        //sum1+=exp(s);
        //cout<<sum1<<endl;
    }
    //s/=(m-u+1.0);

    FOR (k,u,m){
        ld v=logCombi(m-1,k-1)+logCombi(n-1,k-1)-log(k)-s;
        sum1+=exp(v);
        //cout<<sum1<<endl;
    }

    ld s1=0;
    FOR (k,u,m){
        s1=logCombi(m-1,k-1)+logCombi(n-1,k-1)-log(sum1)-s;
        sum+=exp(s1);
        //cout<<sum<<endl;
    }
    //cout<<sum<<endl;
    //cout<<u<<endl;
    //sum*=2.0;
    //cout<<fixed<<setprecision(8)<<sum<<endl;
    ld resB=(ld)n*1.0-sum;
    ld resA=(ld)resB*1.0+m-n;
    if (abs(resB)<1e-9) resB=0;
    if (abs(resA)<1e-9) resA=0;

    if (qq==0) {cout<<fixed<<setprecision(10)<<(ld) resA<<" "<<resB<<endl;}
    else       {cout<<fixed<<setprecision(10)<<(ld) resB<<" "<<resA<<endl;}

    //cout<<fixed<<setprecision(8)<<(ld) (2.0*m*n)/(m+n-1.0)<<endl;
    //cout<<resA+resB+(2.0*m*n)/(m+n-1.0)<<endl;
    //cout<<sum1<<endl;
    ld M=+lgt[m]+lgt[n]-lgt[m+n-1]+log(sum1)+s;
    M*=-1;
    //cout<<M<<endl;
    if (M>log(1e18)) {cout<<"Too big!"<<endl;}
    else{
        ld res=exp(M);
        cout<<fixed<<setprecision(10)<<res<<endl;
     //   cout<<M<<endl;
    }
    }
    else{
        if (d0<max(m,n)){cout<<"You can't do it!"<<endl; return 0;}

        if (m==0) {
            cout<<fixed<<setprecision(10)<<0.0<<" "<<(ld) n<<endl<<1.0<<endl;
                 //
        }
        else{
            cout<<fixed<<setprecision(10)<<(ld) m<<" "<<0.0<<endl<<1.0<<endl;

        }
    }
         return 0;
}
