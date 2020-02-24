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

int z[2000005];

void compute_z(string s){
    int n=s.length();
    FOR (i,0,n-1) z[i]=0;
    int x=0,y=0;
    FOR (i,1,n-1){
        z[i]=max(0,min(z[i-x],y-i+1));
        while (i+z[i]<n && s[z[i]]==s[z[i]+i]){
            x=i;y=i+z[i];z[i]++;
        }
    }
}
string a,l,r,s;
int l1[1000005], r1[1000005] ;
ll d[1000005], fen[1000005];
const ll K=998244353;
int n;
void update(int u, ll v){
	for (int i=u; i<=n; i+=i&-i){
		fen[i]=(fen[i]+v)%K;
	}
}

ll get(int u){
	ll sum=0;
	for (int i=u; i; i-=i&-i){
		sum=(sum+fen[i])%K;
	}
	return sum;
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin>>a>>l>>r;
    s=l+"#"+a;
    compute_z(s);
    FOR (i,l.length()+1,s.length()-1) {
        l1[i-l.length()-1]=z[i];
    }
    //FOR (i,0,a.length()-1) cout<<l1[i]<<" ";
	s.clear();
	s=r+"#"+a;
    compute_z(s);
    FOR (i,r.length()+1,s.length()-1) {
        r1[i-r.length()-1]=z[i];
    }
    //FOR (i,0,a.length()-1) cout<<r1[i]<<" ";

    n=a.length();

    d[0]=1;
    FOR (i,0,n-1){
    	int L=i+l.length()-1;
    	if (l1[i]<l.length()){
    		if (a[l1[i]+i]<l[l1[i]]) L++;
    	}
    	int R=i+r.length()-1;
    	if (r1[i]<r.length()){
    		if (a[r1[i]+i]>r[r1[i]]) R--;
    	}
    	//cout<<i<<" "<<L<<" "<<R<<endl;
    	L++; R++;
    	if (L>R) {
    		d[i+1]=get(i+1);
    		continue;
    	}
    	if (a[i]=='0'){
    		if (l=="0"){
    			d[i+1]=d[i];
    		}
    		d[i+1]=(d[i+1]+get(i+1))%K;
    		//cout<<i+1<<" : "; FOR (q,1,n) cout<<d[q]<<" "; cout<<endl;
    		continue;
    	}
    	int j=i+1;
    	//cout<<j<<" "<<L<<" "<<R<<endl;
    	
    	update(L,d[j-1]);
    	update(R+1,(K-d[j-1])%K);
    	d[j]=get(j);
    	//cout<<j<<" "<<d[j]<<endl;
    	//cout<<j<<" : "; FOR (q,1,n) cout<<d[q]<<" "; cout<<endl;
    }
    //FOR (i,1,n) cout<<d[i]<<" "; 
   	cout<<(d[n]+K)%K<<endl; 

         return 0;
}