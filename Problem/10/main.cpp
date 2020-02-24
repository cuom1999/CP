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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;

/* Cho a1+a2+...+an=s. Tim Min A=b1*a1^2+b2*a2^2+...+bn*an^2 */

ll b[100005];
priority_queue<II,vector<II> , greater<II> > pq;
ll a[100005],d[100005];
ld T;
ld c[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll S,n;
    cin>>S>>n;
    FOR (i,1,n){
        cin>>b[i];
        pq.push(II(b[i],i));
    }
    ll S1=S;
    ll S2=S;
    while (S2--){
        II u=pq.top();
        pq.pop();
        u.first+=2*b[u.second];
        pq.push(u);
    }
    while (pq.size()){
        II u=pq.top();
        d[u.second]=(u.first/b[u.second]-1)/2;
        pq.pop();
    }
    FOR (i,1,n) cout<<d[i]<<" ";
    cout<<endl;

    FOR (i,1,n) T+=1.0/(b[i]);
    FOR (i,1,n) c[i]=(ld) S*1.0/T/ (b[i]);
    FOR (i,1,n) cout<<fixed<<setprecision(3)<<c[i]<<" ";
    cout<<endl;

    FOR(i,1,n) {a[i]=floor(c[i])-1;S1-=a[i];}
    FOR (i,1,n)  pq.push(II((2*a[i]+1)*b[i],i));
    //cout<<S1<<endl;

    while (S1--){
        II u=pq.top();
        pq.pop();
        u.first+=2*b[u.second];
        pq.push(u);
    }
    while (pq.size()){
        II u=pq.top();
        a[u.second]=(u.first/b[u.second]-1)/2;
        pq.pop();
    }
    FOR (i,1,n) cout<<a[i]<<" ";
    cout<<endl;

         return 0;
}
