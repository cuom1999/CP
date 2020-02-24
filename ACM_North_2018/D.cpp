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

vector<int> v[105];
int e[105][105];
ll res;

void add(vector<int> v){
	for (int i=0; i<v.size(); i++){
		for (int j=i+1; j<v.size(); j++){
			e[v[i]][v[j]]=e[v[j]][v[i]]=1;
		}
	}
	ll y=v.size();
	y=y*(y-1)*(y-2)/6;
	res-=y;
	//cout<<"K"<<" "<<y<<endl;
}
vector<int>V;
int main()
{//IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    if (n==0){
    	cout<<48<<endl;
    }
    if (n==1){
    	cout<<35<<endl;
    }
    if (n==2){
    	cout<<25<<endl;
    }
    if (n==3) {
    	cout<<17<<endl;
    }
    return 0;
    V.clear();
    V.pb(1); V.pb(2); V.pb(3);
    add(V);

	V.clear();
    V.pb(3); V.pb(4); V.pb(5);
    add(V);

    V.clear();
    V.pb(1); V.pb(5); V.pb(6);
    add(V);

    V.clear();
    V.pb(1); V.pb(4); V.pb(7); V.pb(8); V.pb(10);
    add(V);

    V.clear();
    V.pb(3); V.pb(6); V.pb(7); V.pb(9); V.pb(12);
    add(V);

    V.clear();
    V.pb(2); V.pb(5); V.pb(8); V.pb(9); V.pb(11);
    add(V);
    
    V.clear();
    V.pb(2); V.pb(6); V.pb(10);
    add(V);

	V.clear();
    V.pb(4); V.pb(6); V.pb(11);
    add(V);

	V.clear();
    V.pb(4); V.pb(2); V.pb(12);
    add(V);


    

    int N=12;

    FOR (i,1,N){
    	FOR (j,i+1,N){
    		FOR (k,j+1,N){
    			if (e[i][j]+e[i][k]+e[j][k]==3) {
    				cout<<i<<" "<<j<<" "<<k<<endl;
    				res++;
    			}
    		}
    	}
    }
    cout<<res<<endl;
    
    
    





    
	
         return 0;
}