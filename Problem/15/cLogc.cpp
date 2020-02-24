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

typedef pair < ld, int > DI;
typedef pair < ll, ll > pll;

ld m[200005],n[200005];


priority_queue<DI, vector<DI>, greater<DI>> pq;

ld calc(int i, ll x){
	return (2*m[i]*(ld)x+m[i]+n[i]);
}

ll res[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N; 
    ll C;
    cin>>N>>C;
    FOR (i,1,N){
    	cin>>m[i]>>n[i];
    	pq.push(DI(m[i]+n[i],i));
    }
    while (C--){
    	auto t=pq.top();
    	pq.pop();
    	int i=t.second;
    	res[i]++;
    	//cout<<i<<" "<<res[i]<<endl;
    	pq.push(DI(calc(i,res[i]),i));
    }
    ld R=0;
    FOR (i,1,N) {	
    	R+=res[i]*res[i]*m[i]+res[i]*n[i];
    }
    FOR (i,1,N) cout<<res[i]<<" "; cout<<endl;
    cout<<fixed<<setprecision(2)<<R<<endl;



    
	
         return 0;
}