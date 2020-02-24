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

vector<int> A,B;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int t;
	cin>>t;
	FOR (z,1,t){
		int n,m;
		cin>>n>>m;
		FOR (i,1,n) {
			int x;
			cin>>x;
			if (x) A.pb(x);
		}
		FOR (i,1,m) {
			int x;
			cin>>x;
			if (x) B.pb(x);
		}
		if (A.size()!=B.size()){
			cout<<"Alice"<<endl;
		}
		else{
			sort(all(A));
			sort(all(B));
			bool q=0;
			for (int i=0; i<A.size(); i++){
				if (A[i]!=B[i]) {
					cout<<"Alice"<<endl;
					q=1;
					break;
				}
			}
			if (!q) cout<<"Bob"<<endl;
		}
		A.clear();
		B.clear();
	}    
	
         return 0;
}