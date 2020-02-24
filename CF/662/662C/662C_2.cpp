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

int n, m;

const int K=1e9+7;

ll mu(ll a, ll n){
    if (n==0) return 1;
    ll q=mu(a,n/2);
    if(n%2==0) return q*q%K;
    return q*q%K*a%K;
}

const int I2=mu(2,K-2);
const int N=1<<20;

void FWT(int *a, int n, bool inv, int op){//1 xor  2 and   3 or      inv==0 DFT -> inv =1
	 for (int i = 1; 2 * i <= n; i <<= 1) {
        for (int j = 0; j < n; j += 2 * i) {
            for (int k = 0; k < i; k++) {
                int x=a[j+k]; int y=a[i+j+k];
                if(!inv){
                    if(op==1)a[j+k]=(x+y)%K,a[i+j+k]=(x-y+K)%K;
                    if(op==2)a[j+k]=(x+y)%K;
                    if(op==3)a[i+j+k]=(x+y)%K;
                }else{
                    if(op==1)a[j+k]=1ll*I2*(x+y)%K,a[i+j+k]=1ll*I2*(x-y+K)%K;
                    if(op==2)a[j+k]=(x-y+K)%K;
                    if(op==3)a[i+j+k]=(y-x+K)%K;
                }
            }
		}
	}
}

void multiply(int *a,int *b,int *c,int n,int op){
	static int A[N],B[N];
	for(int i=0;i<n;i++)A[i]=a[i],B[i]=b[i];
	FWT(A,n,0,op);FWT(B,n,0,op);
	for(int i=0;i<n;i++)c[i]=1ll*A[i]*B[i]%K;
	FWT(c,n,1,op);
}

inline min(int a, int b) {
	if (a < b) return a;
	return b;
}

int a[100004];
int A[N], B[N];
int C[N];
ll d[N];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		char c;
    		cin >> c;
    		if (c == '0') {
    			a[j] <<= 1;
    		}
    		else {
    			a[j] <<= 1;
    			a[j]++;
    		}
    	}
    }
    int M = (1 << n);
    FOR (i, 0, M - 1) {
        A[i] = min(popcnt(i), n - popcnt(i));
    }
    FOR (i, 1, m) {
        B[a[i]]++;
    }

    multiply(A, B, C, M, 1);
    int res = INF;

    FOR (i, 0, M - 1) res = min(res, C[i]);

    cout << res << endl;


    return 0;
}