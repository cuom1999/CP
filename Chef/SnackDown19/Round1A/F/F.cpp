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

map<int,int> d;
vector<int> V;

inline int abs(int x){
	if (x<0) return -x;
	return x;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
		int n;
		cin>>n;
		int mi=-1;
		d.clear();
		V.clear();
		FOR (i,1,n){
			int x;
			cin>>x;
			if (x==-1) continue;
			mi=max(mi,x);
			x-=i;
			if (d[x]) continue;
			else {
				d[x]=1;
				V.pb(x);
			}
		}    
		sort(all(V));
		if (V.size()<=1){
			cout<<"inf"<<endl;
		}
		else{
			int res=V[1]-V[0];
			for (int i=2; i<V.size(); i++){
				res=__gcd(res,V[i]-V[0]);
			}
			if (res>=mi) {
				cout<<res<<endl;
			}
			else{
				cout<<"impossible"<<endl;
			}
		}
	}
	
         return 0;
}