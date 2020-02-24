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

bool check(int n){
	for (int i=2; i*i<=n; i++){
		if (n%i==0) return 0;
	}
	return 1;
}
vector<int> pr;
int a[205];
int b[205];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i,2,100){
    	if (check(i)) pr.pb(i);
    }
    for (int i=0; i<pr.size(); i++){
    	for (int j=i+1; j<pr.size(); j++){
    		int y=pr[i]*pr[j];
    		if (y<=200){
    			a[y]=1;
    		}
    	}
    }
    vector<int> v1;
    FOR (i,1,200){
    	if (a[i]) v1.pb(i);
    }
    for (int i=0; i<v1.size(); i++){
    	for (int j=i; j<v1.size(); j++){
    		int y=v1[i]+v1[j];
    		if (y<=200){
    			b[y]=1;
    		}
    	}
    }
    int t;
    cin>>t;
    FOR (z,1,t){
    	int x;
    	cin>>x;
    	if (b[x]){
    		cout<<"YES"<<endl;
    	}
    	else cout<<"NO"<<endl;
    }
    
	
         return 0;
}