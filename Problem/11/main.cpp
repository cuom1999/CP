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

/* De bai: Tren soi day do dai L, co n con kien. Con kien thu i nam cach dau trai soi day mot doan a[i]. Khong co 2 con kien nao
nam cung vi tri. Cac con kien dang di chuyen ngau nhien ve hai dau soi day voi van toc 1. Neu 2 con gap nhau thi chung se quay dau
va doi huong(Thoi gian quay dau khong dang ke). Tinh thoi gian ky vong luc con kien cuoi cung roi khoi day*/


int n;
ll L,a[1000005];
/*
ld solve(int i, int j){
    if (i==j) {
        return L/2.0;
    }
    if ((L-a[i])>=a[j]) {
        return (L-a[i])/2.0+solve(i+1,j)/2.0;
    }
    return (a[j])/2.0+solve(i,j-1)/2.0;
}
*/
ll b[1000005];
/*
void test(int m){
    int iT=1;
    ll res=0;
    while (iT<=m){
        iT++;
        ll sum=0;
        FOR(i,1,n){
            int c=rand()%2;
            if (c==0){
                b[i]=a[i];
            }
            else b[i]=L-a[i];
            sum=max(sum,b[i]);
        }
        res+=sum;
    }
    cout<<fixed<<setprecision(8)<<(ld) res/1.0/m<<endl;
}
*/
vector<int> T;
int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    cin>>n>>L;
    FOR (i,1,n){
        cin>>a[i];
    }
    //test(300000);
    sort(a+1,a+n+1);

    int i=1, j=n;
    ld res=0;
    while (i<=j){
        if (i==j){
            res=L/2.0;
            break;
        }
        if ((L-a[i])>=a[j]) {
            i++;
            T.pb(1);
        }
        else{
            j--;
            T.pb(0);
        }
    }
    reverse(all(T));

    for (int ii=0; ii<T.size(); ii++){
        int q=T[ii];
        if (q==1){
            i--;
            res=res/2.0+(L-a[i])/2.0;
        }
        else{
            j++;
            res=res/2.0+(a[j])/2.0;
        }
    }


    cout<<fixed<<setprecision(8)<<res<<endl;;



         return 0;
}
