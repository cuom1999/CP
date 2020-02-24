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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

typedef complex<double> base;
void fft(vector<base> &a, bool inv)
{
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for(int i=1; i<n; i++)
    {
        int bit = (n >> 1);
        while(j >= bit)
        {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++)
    {
        roots[i] = base(cos(ang * i), sin(ang * i));
    }
    /* In NTT, let prr = primitive root. Then,
    int ang = ipow(prr, (mod - 1) / n);
    if(inv) ang = ipow(ang, mod - 2);
    for(int i=0; i<n/2; i++){
    roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
    }
    Others are same. If there is /= n, do *= ipow(n, mod - 2).
    In XOR convolution, roots[*] = 1.
    */
    for(int i=2; i<=n; i<<=1)
    {
        int step = n / i;
        for(int j=0; j<n; j+=i)
        {
            for(int k=0; k<i/2; k++)
            {
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}
vector<ll> multiply(vector<ll> &v, vector<ll> &w)
{
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2;
    while(n < v.size() + w.size()) n <<= 1;
    fv.resize(n);
    fw.resize(n);
    fft(fv, 0);
    fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    n=v.size()+w.size()-1;
    vector<ll> ret(n);
    for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

const int N=100005;

int subCD[N], cenDad[N], cenRoot;
vector<int> v[N], cenChild[N];
set<int> s[N];

int dfsCD(int a, int p){
	subCD[a]=1;
	for (int i:s[a]){
		if (i!=p){
			dfsCD(i,a);
			subCD[a]+=subCD[i];
		}
	}
	return subCD[a];
}

int centroid(int a, int p, int n){
	for (auto i:s[a]){
		if (i!=p && subCD[i]>n/2){
			return centroid(i,a,n);
		}
	}
	return a;
}

//call centroidDecomposition(1,0)
void centroidDecomposition(int a, int p){
	int n = dfsCD(a,p);
	int cen = centroid(a,p,n);
	cenDad[cen] = p;
	if(p) cenChild[p].pb(cen);
	else cenRoot = cen;

	for (int i:s[cen]){
		s[i].erase(cen);
		centroidDecomposition(i,cen);
	}
}

vector<ll> add(vector<ll> &A, vector <ll> &B){
	int m = A.size();
	if (m<B.size()) m=B.size();
	if (m==0) {
		vector<ll> res;
		res.pb(0);
		return res;
	}
	//for (auto i:A) cout<<i<<" "; cout<<"A"<<endl;
	//for (auto i:B) cout<<i<<" "; cout<<"B"<<endl;
		
	vector<ll> res = B;
	res.resize(m);
	for (int i=0; i<A.size() && i<m; i++){
		res[i]+=A[i];
	}
	//for (auto i:res) cout<<i<<" "; cout<<"C"<<endl;
	return res;
}


int h[N];
int p[N][20];
int n;

void dfs(int a, int par){
	p[a][0]=par;
	for (int i:v[a]){
		if (i!=par){ 
			h[i]=h[a]+1;
			dfs(i,a);
		}
	}
}

void init(){
    FOR (i,1,18){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,17,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}

    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

int dist(int u, int v){
	int a = LCA(u,v);
	return h[u]+h[v]-2*h[a];
}

vector<ll> A;

void calc(int a, int p){
	int u = dist(a,p);
	if (u+1>A.size()) A.resize(u+1);
	A[u]++;

	for (auto i:cenChild[a]){
		calc(i,p);
	}
}

ll cnt[N];

void dfs(int a){
	vector<ll> S0,S1;
	for (auto i:cenChild[a]){
		A.clear();
		calc(i,a);
		for (int j=1; j<A.size(); j++){
			cnt[j]+=A[j];
		}
		
		S0 = add(S0, A);

		vector<ll> Q = multiply(A,A);
		S1 = add(S1, Q);
	}
	if (cenChild[a].size()){
		S0 = multiply(S0,S0);
		for (int i=0; i<S1.size(); i++) S1[i]=-S1[i];
		S0 = add(S0,S1);
		for (int i=0; i<S0.size(); i++) S0[i]/=2;
	}
	for (int i=1; i<S0.size(); i++){
		cnt[i]+=S0[i];
	}

	for (auto i:cenChild[a]) dfs(i);
}

int prime[N];

void sieve(int n){
	for (int i=2; i<=n; i++){
		FOR (j,2,n/i){
			prime[i*j]=1;
		}
	}
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>n;
    FOR (i,1,n-1) {
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    FOR (i,1,n){
    	for (auto j:v[i]) s[i].insert(j);
    }
	centroidDecomposition(1,0);
	h[1]=1;
    dfs(1,0);
    init();
    dfs(cenRoot);
    sieve(50000);
    ll res=0;
    FOR (i,2,n) {
    	if (!prime[i]) {
    		res+=cnt[i];
    	}
    }
    cout<<fixed<<setprecision(8)<<res*2.0/n/(n-1)<<endl;



    return 0;
}
