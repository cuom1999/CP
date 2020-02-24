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
#define INF 10000000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

/* Co k generators. Hoi co bao nhieu n>=2 de khi choi Bau Cua Tom Ca voi n o, nguoi dat tien co EXPECTED GAIN>=0 */
/* SOL: <=> (n-1)^k<=k*n^(k-1) */
ll n,k;
bool check (ll a){
    return (k*log2(a-1)-log2(k)-(k-1)*log2(a))<=0;
}
bool check1 (ld a){
    return (k*log2(a-1)-log2(k)-(k-1)*log2(a))<=0;
}
ld W1;
void calcW1(){
    ld dau=1, cuoi=2,mid;
    while (abs(dau-cuoi)>1e-15){
        mid=(dau+cuoi)/2;
        if (mid*log(mid)<1) dau=mid;
        else cuoi=mid;
    }
    W1=dau;
}
int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    calcW1();
    //cout<<fixed<<setprecision(15)<<W1<<endl;
    while (cin>>k){
    ll dau=2, cuoi=INF,mid;
    while (dau<cuoi){
        mid=(dau+cuoi+1)/2;
        if (check(mid)) dau=mid;
        else cuoi=mid-1;
    }

    ld dau1=2, cuoi1=INF,mid1;
    while (abs(dau1-cuoi1)>1e-6){
        mid1=(dau1+cuoi1)/2.0;
        if (check1(mid1)) dau1=mid1;
        else cuoi1=mid1;
    }
    cout<<dau; //cout<<fixed<<setprecision(10)<<" "<<dau1<<" "<<dau1/k<<endl;


    }
         return 0;
}
