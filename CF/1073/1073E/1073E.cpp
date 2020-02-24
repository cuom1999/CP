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
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll K=998244353;

ll f[1055][25][25], d[1055][25][25];
ll vsf[1055][25][25], vsd[1055][25][25];
ll sf[1055][25][25], sd[1055][25][25];

ll vssf[1055][25][25], vssd[1055][25][25];

ll mu[24];
ll k, a[20];

ll calc_f(ll bit, ll n, ll st){
	if (n==-1){
		if (bit==0 && st==0) return 1;
		return 0;
	}
	if (popcnt(bit)>k || (bit&(1<<st))==0) return 0;
	//cout<<bit<<" "<<n<<" "<<st<<endl;
	
	if (vsf[bit][n][st]) return f[bit][n][st];
	vsf[bit][n][st]=1;
	ll Res=0;
	FOR (i,0,9){
		if ((bit & (1<<st)))
			Res=(Res+calc_f(bit,n-1,i)+calc_f(bit-(1<<st),n-1,i))%K;
	}
	return f[bit][n][st]=Res;
}

ll calc_sf(ll bit, ll n , ll st){
	if (n==-1){
		return 0;
	}
	if (popcnt(bit)>k || (bit&(1<<st))==0) return 0;
	if (vssf[bit][n][st]) return sf[bit][n][st];
	vssf[bit][n][st]=1;

	ll Res=0;
	FOR (i,0,9){
		if ((bit & (1<<st))){
			Res=(Res+calc_sf(bit,n-1,i)+calc_sf(bit-(1<<st),n-1,i))%K;
		}	
	}
	Res=(Res+st*mu[n]%K*calc_f(bit,n,st)%K)%K;
	//cout<<bit<<" "<<n<<" "<<st<<" "<<Res<<endl;
	return sf[bit][n][st]=Res;	
}


ll calc_d(ll bit, ll n, ll st){
	if (n==-1){
		if (bit==0 && st==0) return 1;
		return 0;
	}
	if (popcnt(bit)>k || st>a[n] || (bit&(1<<st))==0) return 0;
	
	if (vsd[bit][n][st]) return d[bit][n][st];
	vsd[bit][n][st]=1;
	ll Res=0;
	
	if (st==a[n]){
		Res=(calc_d(bit,n-1,a[n-1])+calc_d(bit-(1<<st),n-1,a[n-1]));
		Res%=K;
		FOR (i,0,a[n-1]-1){
			Res=(Res+calc_f(bit,n-1,i)+calc_f(bit-(1<<st),n-1,i))%K;
		}
	}
	else if (st<a[n]){
		Res=calc_f(bit,n,st);
	}

	return d[bit][n][st]=Res;
}


ll calc_sd(ll bit, ll n, ll st){
	if (n==-1){
		return 0;
	}
	if (popcnt(bit)>k || st>a[n] || (bit&(1<<st))==0) return 0;

	if (vssd[bit][n][st]) return sd[bit][n][st];
	vssd[bit][n][st]=1;
	ll Res=0;
	
	if (st==a[n]){
		Res=(calc_sd(bit,n-1,a[n-1])+calc_sd(bit-(1<<st),n-1,a[n-1]));
		Res%=K;
		FOR (i,0,a[n-1]-1){
			Res=(Res+calc_sf(bit,n-1,i)+calc_sf(bit-(1<<st),n-1,i))%K;
		}
		Res=(Res+st*mu[n]%K*calc_d(bit,n,st)%K)%K;
	}
	else if (st<a[n]){
		Res=calc_sf(bit,n,st);
	}
	
	return sd[bit][n][st]=Res;
}

void pre(ll r){
	int C=-1;
	while (r){
		a[++C]=r%10;
		r/=10;
	}
}

ll calc (ll r){
	if (r==0) return 0;
 	int C=-1;
	FOR (i,0,1024){
		FOR (j,0,20){
			FOR (k,0,10){
				vssf[i][j][k]=vssd[i][j][k]=vsf[i][j][k]=vsd[i][j][k]=0;
			}
		}
	}
	while (r){
		a[++C]=r%10;
		r/=10;
	}
	ll Res=0;
	FOR (i,1,1023){
		if (popcnt(i)<=k){
			FOR (j,1,9){
				FOR (z,0,C-1){
					Res=(Res+calc_sf(i,z,j))%K;
					//if (calc_sf(i,z,j)) cout<<i<<" "<<z<<" "<<j<<" "<<calc_sf(i,z,j)<<endl;
				}
				Res=(Res+calc_sd(i,C,j))%K;
				//if (calc_sd(i,C,j)) cout<<i<<" "<<C<<" "<<j<<" "<<calc_sd(i,C,j)<<endl;
			}
		}
	}
	return Res;
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    mu[0]=1;
    FOR (i,1,18) mu[i]=mu[i-1]*10%K;
    ll l,r;
    cin>>l>>r>>k;
    //cout<<calc(r)<<endl;
    //pre(l-1);
    //cout<<calc_sd(16,11,4)<<endl;
    ll res=(calc(r)-calc(l-1)+K)%K;
    cout<<res<<endl;
	
         return 0;
}