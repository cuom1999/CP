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

string a,l,r;

bool comp(string a, string b){
	if (a.length()<b.length()) return 1;
	if (a.length()==b.length()){
		if (a<=b) return 1;
		return 0; 
	}
	return 0;
}
const ll K=998244353;
ll d[1000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>a>>l>>r;

   	int n= a.length();
   	FOR (i,0,n-1){
   		FOR (j,0,i){
   			string q;
   			FOR (k,j,i) q+=a[k];
   			if (a[j]=='0' && j<i) continue;
   			//cout<<j<<" "<<q<<endl;
   			if (comp(q,r) && comp(l,q)) {
   				if (j==0) d[i]=(d[i]+1)%K;
   				else d[i]=(d[i]+d[j-1])%K;
   			}
   		}
   		//cout<<i<<" "<<d[i]<<endl;
   	}
   	cout<<d[n-1]<<endl;

    
	
         return 0;
}