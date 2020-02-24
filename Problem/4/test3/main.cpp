#include <iostream>
#include <bits/stdc++.h>

#define ld __float128
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
    if (k>n) return -1.0;
    return  (lgt[n]-lgt[k]-lgt[n-k]);
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    lgt[1]=0.0;
    FOR (i,2,4000000) lgt[i]=lgt[i-1]+(ld) log2(i);
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
        s=max(s,logCombi(m-1,k-1)+logCombi(n-1,k-1)-(ld) log2(k));
        //sum1+=exp(s);
        //cout<<sum1<<endl;
    }
    //s/=(m-u+1.0);

    FOR (k,u,m){
        ld v=logCombi(m-1,k-1)+logCombi(n-1,k-1)-log2(k)-s;
        long double v1=v;
        sum1+=pow(2,v1);
        //cout<<sum1<<endl;
    }

    ld s1=0;
    FOR (k,u,m){
        long double sum2=sum1;
        long double s1=logCombi(m-1,k-1)+logCombi(n-1,k-1)-log2(sum2)-s;

        sum+=pow(2,s1);

        //cout<<sum<<endl;
    }
    //cout<<sum<<endl;
    //cout<<u<<endl;
    //sum*=2.0;
    //cout<<fixed<<setprecision(8)<<sum<<endl;
    ld resB=(ld)n*1.0-sum;
    ld resA=(ld)resB*1.0+m-n;
    long double resA1,resB1;
    resA1=resA;resB1=resB;

    if (abs(resB1)<1e-9) resB1=0;
    if (abs(resA1)<1e-9) resA1=0;

    if (qq==0) {cout<<fixed<<setprecision(10)<<resA1<<" "<<resB1<<endl;}
    else       {cout<<fixed<<setprecision(10)<<resB1<<" "<<resA1<<endl;}

    //cout<<fixed<<setprecision(8)<<(ld) (2.0*m*n)/(m+n-1.0)<<endl;
    //cout<<resA+resB+(2.0*m*n)/(m+n-1.0)<<endl;
    //cout<<sum1<<endl;
    long double sum2=sum1;
    ld M=+lgt[m]+lgt[n]-lgt[m+n-1]+log2(sum2)+s;
    M*=-1;
    //cout<<M<<endl;
    if (M>log2(1e18)) {cout<<"Too big!"<<endl;}
    else{
        long double M1=M;
        ld res=pow(2,M1);
        long double res1=res;
        cout<<fixed<<setprecision(10)<<res1<<endl;
     //   cout<<M<<endl;
    }
    }
    else{
        if (d0<max(m,n)){cout<<"You can't do it!"<<endl; return 0;}

        if (m==0) {
            cout<<fixed<<setprecision(10)<<0.0<<" "<<n<<endl<<1.0<<endl;
                 //
        }
        else{
            cout<<fixed<<setprecision(10)<<m<<" "<<0.0<<endl<<1.0<<endl;

        }
    }
         return 0;
}
