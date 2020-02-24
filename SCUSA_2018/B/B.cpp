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

int calc(ld x){
	x/=440;
	x=pow(x,12);
	x=log2(x);
	int u= (round)(x);
	u = (u%12+12)%12;
	return u;
}

string s[12] ={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
string ss[12] ={"A","Bb","B","C","Db","D","Eb","E","F","Gb","G","Ab"};
vector<int> G,C,Eb,F,Gm;
int cnt[15];
ld x[100005];
string nt[100005];
int q;
string res;
void solve(vector<int>G, string ss){
	bool b=0;
	FOR (i,0,11) if (cnt[i]) b=1;
    
	FOR (i,0,11){
    	if (cnt[i]){
    		bool qq=0;
    		for(auto j:G){
    			if (i==j) qq=1;
    		}
    		if (!qq) b=0; 
    	}
    }
    if (b){
    	q++;
    	res=ss;
    }
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    G={10,0,2,3,5,7,9};
    C={3,5,7,8,10,0,2};
    Eb={6,8,10,11,1,3,5};
    F={9,11,0,2,4,5,7};
    Gm={10,0,1,3,5,6,8};

    int n;
    cin>>n;
    FOR (i,1,n){
    	cin>>x[i];
    	int y=calc(x[i]);
    	y=(y%12+12)%12;
    	cnt[y]++;
    	nt[i]=s[y];
    }
	solve(G,"G major");
	solve(C,"C major");
	solve(Eb,"Eb major");
	solve(F,"F# minor");
	solve(Gm,"G minor");
	
    if (q==1){
    	cout<<res<<endl;
    	if (res[0]=='E' || res[3]=='i'){
    		FOR (i,1,n){
    			int y=calc(x[i]);
    			nt[i]=ss[y];
    		}
    	}
    	FOR (i,1,n){
    		cout<<nt[i]<<endl;
    	}
    }
    else{
    	cout<<"cannot determine key"<<endl;
    }




    
         return 0;
}