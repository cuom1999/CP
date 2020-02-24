
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

ld m[200005], n[200005];

ll res[200005];

priority_queue<DI, vector<DI>, greater<DI>> pq;

ld calc(int i, ll x){
	return (2*m[i]*(ld)x+m[i]+n[i]);
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int N; ll C;
 	cin>>N>>C;
 	FOR (i,1,N){
 		cin>>m[i]>>n[i];
 	}   
 	
 	ld M=0;
 	
 	ld T=0,T1=0;
 	FOR (i,1,N) T+=1.0/m[i];
 	FOR (i,1,N){
 		T1+=n[i]/m[i];
 	}
 	M=(T1+2*C)/T;
 	
 	ll K=0;
 	if (C>=200000){
	 	FOR (i,1,N){
	 		ld T=(M-n[i])/(2*m[i]);
	 		K=min(K,(ll)(T)-1) ;
	 		res[i]=max((ll)(T-100),0LL);
	 	}
	 	//cout<<Q<<endl;
	 	//cout<<K<<endl;
	 	K=-K;
	 	FOR (i,1,N){
	 		res[i]=max(0LL,res[i]-K);
	 	}
	 	FOR (i,1,N) C-=res[i];
	}
 	//cout<<C<<endl;

	FOR (i,1,N){
    	pq.push(DI(calc(i,res[i]),i));
    }
    while (C--){
    	auto t=pq.top();
    	pq.pop();
    	int i=t.second;
    	res[i]++;
    	pq.push(DI(calc(i,res[i]),i));
    }
    ld R=0;
    FOR (i,1,N) {
    	R+=res[i]*res[i]*m[i]+res[i]*n[i];
    }
    //FOR (i,1,N) cout<<res[i]<<" "; cout<<endl;
    cout<<fixed<<setprecision(8)<<R<<endl;



	
         return 0;
}