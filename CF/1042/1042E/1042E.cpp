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

const ll K=	998244353;

ll mu(ll a, ll n, ll K){
	if (n==0) return 1;
	ll q=mu(a,n/2,K);
	if (n%2==0) return q*q%K;
	return q*q%K*a%K;
}

inline ll inv(ll a){
	return mu(a,K-2,K);
}

struct data{
	ll x,y,v;
	data(ll __x=0, ll __y=0, ll __v=0){
		x=__x;
		y=__y;
		v=__v;
	}
};

bool operator < (data a, data b){
	return a.v<b.v;
}

vector<data> P;


int last[1000005];
ll d[1000005],s[1000005],s1x[1000005], s2x[1000005], s1y[1000005], s2y[1000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    FOR (i,1,n){
    	FOR (j,1,m){
    		ll v;
    		cin>>v;
    		P.pb(data(i,j,v));
    	}
    }
    int r,c;
    cin>>r>>c;
    P.pb(data(0,0,-1));
    sort(all(P));

    //cout<<13*inv(6)%K<<endl;

    for (int i=1; i<P.size(); i++){
    	if (P[i].v==P[i-1].v) {
    		last[i]=last[i-1];
    	}
    	else last[i]=i-1;
    	if (last[i]==0){
    		d[i]=0; 
    	}
    	else{
    		ll I=inv(last[i]);
    		d[i]=s[last[i]]*I%K;

    		d[i]=(d[i]+P[i].x*P[i].x%K)%K;
    		d[i]=(d[i]+P[i].y*P[i].y%K)%K;
    		ll A=P[i].x*s1x[last[i]]%K;
    		ll B=P[i].y*s1y[last[i]]%K;
    		
    		ll C=s2x[last[i]]%K;
    		ll D=s2y[last[i]]%K;
    		//if (i==4) cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    		ll E=(C+D-2*A-2*B)%K*I%K;

    		d[i]=(d[i]+E)%K;
    		d[i]=(d[i]+K)%K;
    	}
    	if (P[i].x==r &&  P[i].y==c) {cout<<d[i]<<endl; return 0;}
    	s1x[i]=(s1x[i-1]+P[i].x)%K;
    	s1y[i]=(s1y[i-1]+P[i].y)%K;
    	s2x[i]=(s2x[i-1]+P[i].x*P[i].x%K)%K;
		s2y[i]=(s2y[i-1]+P[i].y*P[i].y%K)%K;
		s[i]=(s[i-1]+d[i])%K;
    }
	
         return 0;
}