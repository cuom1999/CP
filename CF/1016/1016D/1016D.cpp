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

int a[105],b[105];

int x[105][105];
int n,m;
int c[105],d[105];
int solve(int bit){
    int C=0,D=0; 
    FOR (i,1,n) {c[i]=(bool) (a[i]&(1<<bit)); C+=c[i]; }
    FOR (i,1,m) {d[i]=(bool) (b[i]&(1<<bit)); D+=d[i];}
    //cout<<bit<<" "<<C<<" "<<D<<endl;
    //if (bit==1) cout<<C<<" "<<D<<endl;
    if ((C+D)%2) return 0;
    return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR (i,1,n){ 
        cin>>a[i];
    }
    FOR (i,1,m){ 
        cin>>b[i];
    }
    FOR (i,0,30){ 
        if (!solve(i)) {cout<<"NO"<<endl; return 0;}
    }
    //cout<<n<<" "<<m<<endl;
    cout<<"YES"<<endl;
    FOR (i,1,n-1){ 
        FOR (j,1,m-1) cout<<0<<" ";
        cout<<a[i]<<endl;
    }
    int B=0;
    FOR (i,1,m-1) {cout<<b[i]<<" ";B^=b[i];}
    B^=a[n];
    cout<<B<<endl;
    

         return 0;
}