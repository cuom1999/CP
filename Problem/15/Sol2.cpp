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
typedef pair < ll, ll > II;

ll m[200005], n[200005];

priority_queue<II, vector<II>, greater<II> > pq;

inline ll calc(int i, ll x){
	return 2*m[i]*x+m[i]+n[i];
}

ll res[200006];

int main()
{//IN;OUT;
    IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    ll C;
    cin>>N>>C;
    FOR (i,1,N){
    	ld x,y;
    	cin>>x>>y;
    	x*=100; y*=100;
    	m[i]=(ll) (x+0.5);
    	n[i]=(ll) (y+0.5);
    	pq.push(II(m[i]+n[i],i));
    	//cout<<m[i]<<" "<<n[i]<<endl;
    }
    while (C--){
    	auto t=pq.top();
    	pq.pop();
    	int i=t.second;
    	res[i]++;
    	pq.push(II(calc(i,res[i]),i));
    }
    ll R=0;
    FOR (i,1,N){
    	R+=res[i]*res[i]*m[i]+res[i]*n[i];
    	// cout<<res[i]<<" ";
    }
    cout<<fixed<<setprecision(2)<< ((ld)R/100.0) <<endl; 

	
         return 0;
}