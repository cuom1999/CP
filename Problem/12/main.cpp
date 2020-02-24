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
typedef pair < ll, ll > II;

/* Mot du an cua 1 cong ty so S cong viec. Ho co n cong ty con va can chia cac cong viec cho cac cong ty con giai quyet. Theo thong kr, ho
nhan thay cong ty con i hoan tat 1 cong viec trong trung binh t_i ngay. Hay giup giam doc cong ty chia cong viec sao cho thoi
gian hoan tat du an la som nhat */

ll n,S;
ll t[100005],a[100005],c[100005];
ld b[100005];
priority_queue <II,vector<II> , greater<II> > pq;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>S;
    ll S1=S;
    FOR (i,1,n) {cin>>t[i];}// pq.push(II(t[i],i));}
    /*while (S1--){
        II u=pq.top();
        pq.pop();
        pq.push(II(u.first+t[u.second],u.second));
    }
    while (pq.size()){
        II u=pq.top();
        pq.pop();
        a[u.second]=u.first/t[u.second]-1;
    }
    FOR (i,1,n) cout<<a[i]<<" ";
    cout<<endl;*/
    ld R=0;
    FOR (i,1,n) R+=1.0/t[i];
    R=S/R;
    FOR (i,1,n) {b[i]=R/t[i];cout<<fixed<<setprecision(2)<<b[i]<<" ";}
    cout<<endl;
    S1=S;
    FOR (i,1,n) {c[i]=(ll) b[i]-1;pq.push(II((c[i]+1)*t[i],i));S1-=c[i];}
    while (S1--){
        II u=pq.top();
        pq.pop();
        pq.push(II(u.first+t[u.second],u.second));
    }
    while (pq.size()){
        II u=pq.top();
        pq.pop();
        c[u.second]=u.first/t[u.second]-1;
    }
    FOR (i,1,n) cout<<c[i]<<" ";





         return 0;
}
