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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;


priority_queue<II>pq;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;   
 	cin>>n;
 	FOR (i,1,n){
 		int x;
 		cin>>x;
 		pq.push(II(x,1));
 	}
 	FOR (i,1,n){
 		int x;
 		cin>>x;
 		pq.push(II(x,0));
 	}
 	int c=1;
 	ll res=0;
 	while (pq.size()){
 		auto t=pq.top();
 		pq.pop();
 		//cout<<t.first<<" "<<c<<endl;
 		if (t.second==c){
 			if (c==1) res+=(ll)t.first;
 			else res-=(ll)t.first;
 		}
 		//cout<<res<<endl;
 		c^=1;
 	}
 	cout<<res<<endl;

	
         return 0;
}