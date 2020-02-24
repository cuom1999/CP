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

string A,B;
int s[30][1005], p[30][1005];
int cnt[30];

const ll K=1e9+7;
const ll K2=1e9+9;
ll calc (){
	ll now=1;
	ll res=0;
	FOR (i,0,25){
		res=(res+now*1ll*cnt[i]%K)%K;
		now=now*17%K;
	}
	return res;
}

map<int,int> d;
map<int,vector<int>> V;
bool comp(int i, int j, int len){
	FOR (c,0,25){
		if (s[c][i+len-1]-s[c][i-1]!=p[c][j+len-1]-p[c][j-1]) return 0;
	}
	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
		cin>>A;
		cin>>B;
		bool q=1;
			
		FOR (i,'a','z'){
			FOR (j,0,A.size()-1){
				s[i-'a'][j+1]=s[i-'a'][j];
				if (A[j]==i) s[i-'a'][j+1]++;
			}
			FOR (j,0,B.size()-1){
				p[i-'a'][j+1]=p[i-'a'][j];
				if (B[j]==i) p[i-'a'][j+1]++;
			}
		}
		int n=A.size();
		FORD (len,n,1){
			V.clear();
			FOR (i,1,n-len+1){
				FOR (c,0,25){
					cnt[c]=s[c][i+len-1]-s[c][i-1];
				}
				ll u=calc();
				V[u].pb(i);
			}
			int res=INF;
			FOR (i,1,n-len+1){
				FOR (c,0,25){
					cnt[c]=p[c][i+len-1]-p[c][i-1];
				}
				ll u=calc();
				if (V.count(u)) {
					for (auto j:V[u]) {
						if (comp(j,i,len)){
							res=min(res,j);
							break;
						}
					}
				} 
			}
			if (res!=INF){
				FOR (i,res-1,res+len-2) cout<<A[i];
				cout<<endl;
				q=0;
				break;
			}
		}
		if (q) cout<<"NONE"<<endl; 
	}

	
         return 0;
}