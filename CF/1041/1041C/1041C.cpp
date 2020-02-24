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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

set<II> S;
int day[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,d;
    cin>>n>>m>>d;
	FOR (i,1,n){
		int k;
		cin>>k;
		S.insert(II(k,i));
	}
	int D=0;
	while (S.size()){
		D++;
		auto t=*S.begin();
		int val = t.first;
		int ind= t.second;
		day[ind]=D;
		S.erase(S.begin());
		while (S.size()){
			auto q=S.upper_bound(II(val+d+1,0));
			if (q!=S.end()){
				val=q->first;
				day[q->second]=D;
				S.erase(q);
			}
			else break;
		}
	}
	cout<<D<<endl;
	FOR (i,1,n){
		cout<<day[i]<<" ";
	}
	
         return 0;
}