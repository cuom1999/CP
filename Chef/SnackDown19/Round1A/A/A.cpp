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

int val[500];
string s;
map<string, int> d;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    val['d']=val['f']=1;
    val['j']=val['k']=2;

    int t;
    cin>>t;
    FOR(z,1,t){
    	d.clear();
    	int n;
    	cin>>n;
    	int res=0;
    	FOR (i,1,n){
    		cin>>s;
    		if (d[s]){
    			res+=d[s]/2;
    		}
    		else{
    			int cnt=2;
    			for (int i=1; i<s.size(); i++){
    				if (val[s[i]]==val[s[i-1]]){
    					cnt+=4;
    				}
    				else{
    					cnt+=2;
    				}
    			}
    			res+=cnt;
    			d[s]=cnt;
    		}
    	}
    	cout<<res<<endl;
    }
	
         return 0;
}