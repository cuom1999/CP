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

int a[105],d[105];
vector<int> v[105];
vector<int> R;
char s[105];
int rr=0;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin>>n;
	FOR (i,1,n){
		cin>>a[i];
		d[a[i]]++;
		v[a[i]].pb(i);
	}   
	FOR (i,1,n){
		if (d[a[i]]==0){
			continue;
		}
		else{
			if (d[a[i]]==1){
				R.pb(i);
			}
			else {
				for (auto j:v[a[i]]) s[j]='A';
				if (d[a[i]]>=3){
					rr=v[a[i]][0];
				}
			}
		}

	}
	if (R.size()%2==0){
		for (int i=0 ;i<R.size(); i++){
			if (i%2==0) s[R[i]]='A';
			else s[R[i]]='B';
		}
	}
	else{
		if (rr==0) {cout<<"NO";return 0;}
		else{
			for (int i=0 ;i<R.size(); i++){
				if (i%2==0) s[R[i]]='A';
				else s[R[i]]='B';
			}
			s[rr]='B';
		}
	}
	cout<<"YES"<<endl;
	FOR (i,1,n) cout<<s[i];
	
         return 0;
}