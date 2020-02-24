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

int a[100005];
int b[100005];
int n;

bool check(int a, int b, int c, int d){
	if (a>b) swap(a,b);
	if (c>d) swap(c,d);
	if (a>c && b<d) return 0;
	if (d>a && b>c) return 0;
	if (a>d && b<c) return 0;
	if (c>a && b>d) return 0;
	return 1;
}

bool check(){
	FOR (i,1,n/2){
		FOR (j,i+1,n/2){
			if (check(a[b[2*i-1]],a[b[2*i]],a[b[2*j-1]],a[b[2*j]])==0){
				return 0;
			}
		}
	}
	//FOR (i,1,n) cout<<b[i]<<" "; cout<<endl;
	return 1;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
    	cin>>n;
    	FOR (i,1,n){
    		cin>>a[i];
    		b[i]=i;
    	}
    	ll res=0;
    	do{
    		if (check()) res++;
    	}while(next_permutation(b+1,b+n+1));
    	FOR (i,1,n/2) res/=2;
    	FOR (i,1,n/2) res/=i;
    	cout<<res<<endl;
    }
    
	
         return 0;
}