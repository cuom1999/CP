#include <bits/stdc++.h>

#define ld long double
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
#define sf scanf
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

string s;

void gen(vector<string> &v, string s, int n){
	if (n==0){
		v.pb(s);
		return ;
	}
	s+='0';
	gen(v,s,n-1);
	s.pop_back();
	s+='1';
	gen(v,s,n-1);
}
vector<string> v1,v2;
ll cnt[22][22], cpost[22], cpre[22];
int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    cin>>s;
	int m=s.length();

	int n1=n/2, n2=n-n1;
    gen(v1,string(),n1);
    gen(v2,string(),n2);
    //for (auto i:v) cout<<i<<endl;
    //cout<<v.size()<<endl;
	
	for (auto i:v2){
		int a=0,b=0;
		vector<int> pre, post;
		FOR (j,0,n2-1){
			if (i[j]=='1') a=a*2+1;
			else a=a*2;
			if (s[m-1-j]=='1'){
				b+=(1<<j);
			}
			if (a==b){
				pre.pb(j+1);
			}
		}
		a=b=0;
		FOR (j,0,n2-1){
			if (i[n2-1-j]=='1') a+=(1<<j);
			if (s[j]=='1'){
				b=b*2+1;
			}
			else b=b*2;
			if (a==b){
				post.pb(j+1);
			}
		}
		/*cout<<i<<endl;
		cout<<"pre: ";
		for (auto i:pre){ 
			cout<<i<<" ";
		}
		cout<<endl;
		cout<<"post: ";
		for (auto i:post){
			cout<<i<<" ";
		}
		cout<<endl;*/
		for (auto j:pre){
			for (auto k:post){
				cnt[i][k]++;
				cpre[j]++;
				cpost[k]++;
			}
		}
	}
	for (auto i:v1){
		
	}	
         return 0;
}