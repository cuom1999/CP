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

ld x[100005], y[100005];
int n;
inline int test(ld X, ld Y){
	int t=0,tt=0;
	FOR (i,1,n){
		if (sq(x[i]-X)+sq(y[i]-Y)>sq(Y)+eps) {
			return 1;
		}
	}
	return 0;
}

ld calc (int i, int j){
    ld a=x[i], b=y[i], c=x[j], d=y[j];
    if (a==c) 
    	ld Y=sq(a-c)+sq(2*d);return 0;
    if (b==d){
    	ld Y=sq(a-c)+sq(2*d);
    	Y/=(8.0*d);
    	return Y;
    }
    ld T=sqrt(b*d*(sq(a-c)+sq(b-d)));
   	ld u1=2*(a-c)*T+a*a*(b+d)-2*a*b*c-2*a*c*d+b*b*b-b*b*d+b*sq(c)-b*sq(d)+sq(c)*d+d*sq(d);
   	ld u2=2*(c-a)*T+a*a*(b+d)-2*a*b*c-2*a*c*d+b*b*b-b*b*d+b*sq(c)-b*sq(d)+sq(c)*d+d*sq(d);
   	//if (u2>-eps) u1=u2;
   	if (u1>u2) swap(u1,u2);
    return u1/(2*sq(b-d));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    int am=0,du=0;
    FOR (i,1,n) {
    	cin>>x[i]>>y[i];
    	if (y[i]>0) du=1;
    	else am=1;
    }
    if (am&&du) {
    	cout<<-1;
    	return 0;
    }
    if (am){
    	FOR (i,1,n) y[i]=-y[i];
    }
    ld res=1e18;
    FOR (i,1,n){
    	if (test(x[i],y[i]/2)==0) res=min(res,y[i]/2);
    }
    FOR (i,1,n){
    	FOR (j,i+1,n){
    		if (x[i]==x[j]) continue;
    		ld Y=calc(i,j);
    		ld X=sq(x[i])+sq(y[i])-sq(x[j])-sq(y[j])-2*Y*(y[i]-y[j]);
    		X/=(2*(x[i]-x[j]));
    		//cout<<X<<" "<<Y<<endl;
    		if (test(X,Y)==0) res=min(res,Y);
    	}
    }
    cout<<fixed<<setprecision(8)<<res<<endl;
   

    
    
         return 0;
}