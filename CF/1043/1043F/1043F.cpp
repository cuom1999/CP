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

const ll K=1e9+7;

ll mu(ll a, ll n){
	if (n==0) return 1;
	ll q=mu(a,n/2);
	if (n%2==0) return q*q%K;
	return q*q%K*a%K;
}

ll gt[300004],rev[300005];

ll Combi(int n, int k){
	if (k<0 || n<k) return 0;
	return gt[n]*rev[k]%K*rev[n-k]%K;
}

ll d[10][300005];
int cnt[300005], divisible[300005];
int a[300005];
int solve(int i){
	FORD (j,300000,1){
		d[i][j] = Combi(divisible[j], i);
		FOR (k,2,300000/j){
			d[i][j] = (d[i][j]-d[i][j*k]+K)%K ;
		}	
	}
	if (d[i][1]) return 1;
	return 0;
}



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0]=rev[0]=1;
    FOR (i,1,300000){
    	gt[i]=gt[i-1]*1ll*i%K;
    	rev[i]=mu(gt[i],K-2);
    }

    int n;
    cin>>n;
    FOR (i,1,n) cin>>a[i];
    int g=a[1];
    FOR (i,2,n) g=__gcd(g,a[i]);

    if (g>1) {
    	cout<<-1;
    	return 0;
    }

    FOR (i,1,n){
    	cnt[a[i]]++;
    }
    FOR (i,1,300000){
    	FOR (j,1,300000/i){
    		divisible[i]+=cnt[i*j];
    	} 
    }

    int res=0;

    FOR(i,1,7) if (solve(i)){
    	cout<<i<<endl;
    	return 0;
    }




    
	
         return 0;
}