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

map<int,int>d;
int x[10];
vector<int> v;
int calc(){
	int now=1;
	int res=0;
	FOR (i,0,5) {
		res+=x[v[i]]*now;
		now*=10;
	}
	return res;
}

int solve(){
	int y=INF;
	v.clear();
	v={1,2,3,4,5,6};
	y=min(y,calc());

	v.clear();
	v={1,2,6,3,4,5};
	y=min(y,calc());

	v.clear();
	v={1,2,5,6,3,4};
	y=min(y,calc());

	v.clear();
	v={1,2,4,5,6,3};
	y=min(y,calc());

	v.clear();
	v={2,1,4,3,6,5};
	y=min(y,calc());

v.clear();
	v={2,1,4,3,6,5};
	y=min(y,calc());
v.clear();
	v={2,1,5,4,3,6};
	y=min(y,calc());
v.clear();
	v={2,1,6,5,4,3};
	y=min(y,calc());
v.clear();
	v={2,1,3,6,5,4};
	y=min(y,calc());
v.clear();


	v={3,5,2,4,1,6};
	y=min(y,calc());
v.clear();
	v={3,5,6,2,4,1};
	y=min(y,calc());
v.clear();
	v={3,5,1,6,2,4};
	y=min(y,calc());
v.clear();
	v={3,5,4,1,6,2};
	y=min(y,calc());
v.clear();
	v={5,3,1,4,2,6};
	y=min(y,calc());
v.clear();
	v={5,3,6,1,4,2};
	y=min(y,calc());
v.clear();
	v={5,3,2,6,1,4};
	y=min(y,calc());
v.clear();
	v={5,3,4,2,6,1};
	y=min(y,calc());
v.clear();
	v={4,6,3,2,5,1};
	y=min(y,calc());
v.clear();
	v={4,6,1,3,2,5};
	y=min(y,calc());
v.clear();
	v={4,6,5,1,3,2};
	y=min(y,calc());
v.clear();
	v={4,6,2,5,1,3};
	y=min(y,calc());
v.clear();
	v={6,4,3,1,5,2};
	y=min(y,calc());
v.clear();
	v={6,4,2,3,1,5};
	y=min(y,calc());
v.clear();
	v={6,4,5,2,3,1};
	y=min(y,calc());
v.clear();
	v={6,4,1,5,2,3};
	y=min(y,calc());
	return y;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin>>n;
	FOR (i,1,n){
		FOR (j,1,6) cin>>x[j];
		swap(x[4],x[5]);
		d[solve()]++;
	}    
	int res=0;
	for (auto i:d) res=max(res,i.second);
	cout<<res<<endl;
         return 0;
}