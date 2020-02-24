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
    int n,k;
    cin>>n>>k;
    if (n<=2*k+1){
    	cout<<1<<endl;
    	cout<<(n+1)/2<<endl;
    	return 0;
    }
    int N=(n-(2*k+2));
    int q=N/(2*k+1), r=N%(2*k+1)+2*k+2;
    cout<<q+2<<endl;
    int a=r/2, b=r-a;
    //cout<<a<<" "<<b<<endl;
    cout<<a-k<<" ";
    int A=a+k+1;

    FOR (i,1,q) {
    	cout<<A<<" ";
    	A+=2*k+1;
    }
    cout<<n-b+1+k<<endl;
    
	
         return 0;
}