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

int a[100005], b[100005];
int m,n,l;
unordered_map<int,int> A;
int solve(int d){
	A.clear();
	int y=2*d;
	FOR (i,1,n){
		A[a[i]%y]++;
	}
	FOR (i,1,m){
		A[((ll)b[i]%y+d)%y]++;
	}
	int res=0;
	for (auto i:A){
		res=max(res,i.second);
	}
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	cin>>n>>l;

	FOR (i,1,n){
		cin>>a[i];
	}

	cin>>m>>l;
	FOR (i,1,m){
		cin>>b[i];
	}
	int res=2;
	FOR (i,0,29) {
		res=max(res,solve(1<<i));
	}

	cout<<res<<endl;




	
         return 0;
}