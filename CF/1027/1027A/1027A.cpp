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

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){ 
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	s='0'+s;
    	bool q=1;
    	FOR(i,1,n/2){ 
    		int a=s[i];
    		int b=s[n+1-i];
    		if (a==b || a==b+2 || a+2==b){ 

    		}
    		else{ 
    			q=0;
    		}
    	}
    	if (q) { 
    		cout<<"YES"<<endl;
    	}
    	else cout<<"NO"<<endl;
    }


         return 0;
}