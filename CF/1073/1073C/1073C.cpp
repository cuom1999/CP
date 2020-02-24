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


string s;
int n;
int x,y;
int X[200005], Y[200006];

bool solve(int len){
	for (int i=1; i+len-1<=n; i++){
		if (abs(x-X[n]+X[i+len-1]-X[i-1])+abs(y-Y[n]+Y[i+len-1]-Y[i-1])<=len) return 1;
	}
	return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    
    cin>>x>>y;

    FOR (i,1,n){
    	X[i]=X[i-1]; Y[i]=Y[i-1];
    	if (s[i-1]=='U'){
    		Y[i]++;
    	}
    	if (s[i-1]=='D'){
    		Y[i]--;
    	}
    	if (s[i-1]=='L'){
    		X[i]--;
    	}
    	if (s[i-1]=='R'){
    		X[i]++;
    	}
    }
    if (abs(x)+abs(y)>n){
    	cout<<-1; return 0;
    }
    if ((x+y-n)%2) {
    	cout<<-1;
    	return 0;
    }
    int l=0, r=n;
    while(l<r){
    	int mid=(l+r)/2;
    	if (solve(mid)){
    		r=mid;
    	}
    	else{
    		l=mid+1;
    	}
    }
    cout<<l;


    
	
         return 0;
}