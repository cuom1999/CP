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

int a[200005];
stack<int> s;
int dd[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    FOR (i,1,k){
    	cin>>a[i];
    	dd[a[i]]=1;
    }
    int C=1;

    FOR (i,1,k){
    	if (a[i]==C){
    		C++;
    		while (s.size() && s.top()==C) {
    			s.pop();
    			C++;
    		}
    	}
    	else{
    		s.push(a[i]);
    	}
    }
    int ind=k;
    while(s.size()){
    	int u=s.top();
    	s.pop();
    	if (u<C) {
    		cout<<-1;
    		return 0;
    	}
    	FORD (i,u-1,C){
    		if (dd[i]) {
    			cout<<-1;
    			return 0;
    		}
    		a[++ind]=i;
    	}
    	C=u+1;
    }
    FORD (i,n,C) a[++ind]=i;

    FOR (i,1,n) cout<<a[i]<<" ";

    
	
         return 0;
}