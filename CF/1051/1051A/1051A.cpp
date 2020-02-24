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
vector<int> A,B,C;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
    	cin>>s;
    	A.clear();
    	B.clear();
    	C.clear();
    	for (int i=0; i<s.length(); i++){
    		if (s[i]>='1' && s[i]<='9'){
    			A.pb(i);
    		}
    		else if (s[i]>='a' && s[i]<='z'){
    			B.pb(i);
    		}
    		else{
    			C.pb(i);
    		}
    	}
    	int a=A.size(), b=B.size(), c=C.size();
    	if (a){
    		if (b){
    			if (c){
    				cout<<s<<endl;
    			}
    			else{
    				if (a>1) s[A[0]]='A';
    				else s[B[0]]='A';

    				cout<<s<<endl;
    			}
    		}
    		else{
    			if (c){
    				if (a>1) s[A[0]]='a';
    				else s[C[0]]='a';
    				cout<<s<<endl;
    			}
    			else{
    				s[A[0]]='A';
    				s[A[1]]='a';
    				cout<<s<<endl;
    			}
    		}
    	}
    	else{
    		if (b){
    			if (c){
    				if (b>1) s[B[0]]='1';
    				else s[C[0]]='1';
    				cout<<s<<endl;
    			}
    			else{
    				s[B[0]]='1';
    				s[B[1]]='A';
    				cout<<s<<endl;
    			}
    		}
    		else{
    			if (c){
    				s[C[0]]='1';
    				s[C[1]]='a';
    				cout<<s<<endl;
    			}
    		}
    	}
    }

	
         return 0;
}