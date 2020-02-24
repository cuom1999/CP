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
string res, res1;
int n;

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int r=1, c=1;
    while (r+c<=n){
    	//if (r==n || c==n) break; 
    	cout<<"?"<<" "<<r+1<<" "<<c<<" "<<n<<" "<<n<<endl;
    	//cout<<r+c<<endl;
    	cout.flush();
    	string s;
    	cin>>s;
    	if (s=="YES"){ 
    		r++;
    		res+="D";
    	}
    	else if (s=="NO") { 
    		c++;
    		res+="R";
    	}
    	else return 0;
    }
    if (r==n){ 
    	FOR (i,c+1,n){ 
    		res+="R";
    	}
    }
    if (c==n){ 
    	FOR (i,r+1,n) res+="D";
    }

	if (res.length()==2*n-2)   {cout<<"! "<<res<<endl;    cout.flush(); return 0;}
	int R=r, C=c;
	r=n, c=n;

	while (1){
    	if (r==R && c==C) break;
    	cout<<"?"<<" 1 1 "<<r<<" "<<c-1<<endl;
    	cout.flush();
    	string s;
    	cin>>s;
    	if (s=="YES"){ 
    		c--;
    		res1+="R";
    	}
    	else if (s=="NO") { 
    		r--;
    		res1+="D";
    	}
    	else return 0;
    }
    reverse(all(res1));
    res+=res1;
	if (res.length()==2*n-2)   {cout<<"! "<<res<<endl;    cout.flush(); return 0;}


         return 0;
}
