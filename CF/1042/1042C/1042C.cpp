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

vector<II> A,B;
vector<int> C;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
   	int n;
   	cin>>n;
   	FOR (i,1,n) {
   		int x;
   		cin>>x;
   		if (x>0){
   			A.pb(II(x,i));
   		}
   		if (x<0){
   			B.pb(II(-x,i));
   		}
   		if (x==0) C.pb(i);
   	}
   	sort(all(A));
   	sort(all(B));
   	if (B.size()%2==0){
   		for (int i=0; i+1<C.size(); i++){
   			cout<<1<<" "<<C[i]<<" "<<C[i+1]<<endl;
   		}
   		if (C.size() && (A.size()+B.size())) cout<<2<<" "<<C.back()<<endl;
   		for (int i=0; i+1<A.size(); i++){
   			cout<<1<<" "<<A[i].second<<" "<<A[i+1].second<<endl;
   		}
   		for (int i=0; i+1<B.size(); i++){
   			cout<<1<<" "<<B[i].second<<" "<<B[i+1].second<<endl;
   		}
   		if (A.size() && B.size()) cout<<1<<" "<<A.back().second<<" "<<B.back().second<<endl;
   	}
   	else{
   		for (int i=1; i<B.size(); i++){
   			A.pb(B[i]);
   		}
   		if (C.size()){
   			for (int i=0; i+1<C.size(); i++){
   				cout<<1<<" "<<C[i]<<" "<<C[i+1]<<endl;
   			}
   			cout<<1<<" "<<C.back()<<" "<<B[0].second<<endl;
   			if (A.size()) cout<<2<<" "<<B[0].second<<endl;
   			for (int i=0; i+1<A.size(); i++){
   				cout<<1<<" "<<A[i].second<<" "<<A[i+1].second<<endl;
   			}
   		}
   		else{
   			if (A.size())cout<<2<<" "<<B[0].second<<endl;
   			for (int i=0; i+1<A.size(); i++){
   				cout<<1<<" "<<A[i].second<<" "<<A[i+1].second<<endl;
   			}
   		}
   	}
    
	
         return 0;
}