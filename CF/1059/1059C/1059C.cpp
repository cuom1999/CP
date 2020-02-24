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

void solve (int n, int c){
	if (n==3) {
		cout<<c<<" "<<c<<" "<<3*c<<endl;
		return ;
	}
	if (n==2){
		cout<<c<<" "<<2*c;
		return ;
	}
	if (n==1) {
		cout<<c;
		return;
	}
	int m=n/2;
	FOR (j,1,n-m){
		cout<<c<<" ";
	}
	solve(m,c*2);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    solve(n,1);
	
         return 0;
}