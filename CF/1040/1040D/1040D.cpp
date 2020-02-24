#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define In freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define InF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;


long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}



ll n,k;

ll l=1, r=n;

void solve1(){
	if (r-l <= 8*k) return ; 
	ll mid=(l+r)/2;
	cout<<l<<" "<<mid<<endl;
	cout.flush();
	string s;
	cin>>s;
	if (s=="Yes"){
		l=max(1LL,l-k);
		r=min(n,mid+k);
		solve1();
	}
	else{
		l=max(1LL,mid+1-k);
		r=min(n,r+k);
		solve1();
	}
}

void solve(){
	ll t=Rand(l,r);
	cout<<t<<" "<<t<<endl;
	string s;
	cin>>s;
	if (s=="Yes") return ;

	l=max(1LL,l-k) ; r=min(n,r+k);

	ll mid=(l+r)/2;
	cout<<l<<" "<<mid<<endl;
	cout.flush();
	cin>>s;
	if (s=="Yes"){
		l=max(1LL,l-k);
		r=min(n,mid+k);
		solve();
	}
	else{
		l=max(1LL,mid+1-k);
		r=min(n,r+k);
		solve();
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    cin>>n>>k;
    r=n;
    solve1();
    if (l==r) {
    	cout<<l<<" "<<r<<endl;
    	string s;
    	cin>>s;
    	return 0;
    }
    solve();

         return 0;
}