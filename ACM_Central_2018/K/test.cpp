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

ll n,m,k;
ll cnt[104];
ll res;
int cc;
void gen (int j, vector<int> &v){
	//cout<<j<<endl;
	if (j==n+1){
		//for (auto i:v) cout<<i<<" "; cout<<endl;
		FOR (i,1,m){
			cnt[i]=0;
		}
		for (auto i:v){
			cnt[i]++;
		}
		bool q=1;
		FOR (i,1,m) {
			if (cnt[i]%k){
				q=0;
			}
		}
		res+=q;
		return ;
	}
	FOR (i,1,m){
		v.pb(i);
		gen(j+1,v);
		v.pop_back();
	}
}
vector<int> rong;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    gen(1,rong);
    cout<<res<<endl;



    
	
         return 0;
}