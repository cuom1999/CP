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

const int MAXN = 100005;

int t, SA[MAXN], RA[MAXN], c[MAXN], tempRA[MAXN], tempSA[MAXN], n,
behind[MAXN], LCP[MAXN], PLCP[MAXN];
string s;

int S;

void countingSort(int k)
{
	int sum = 0, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	FOR(i,0,n-1)
	if (i+k < n) c[RA[i+k]]++;
	else c[0]++;
	FOR(i,0,maxi-1) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	} 
	FOR(i,0,n-1) {
		int a = 0;
		if (SA[i]+k < n) a = RA[SA[i]+k];
		tempSA[c[a]++] = SA[i];
	} 
	FOR(i,0,n-1) SA[i] = tempSA[i];
}

void suffixArray()
{
	int r;
	FOR(i,0,n-1) SA[i] = i;
	FOR(i,0,n-1) RA[i] = s[i];
	for (int k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		FOR(i,1,n-1) {
			if (RA[SA[i]] != RA[SA[i-1]]) {
				tempRA[SA[i]] = ++r;
				continue;
			} 
			int a, b;
			if (SA[i]+k >= n) a = 0;
			else a = RA[SA[i]+k];
			if (SA[i-1]+k >= n) b = 0;
			else b = RA[SA[i-1]+k];
			if (a == b) tempRA[SA[i]] = r;
			else tempRA[SA[i]] = ++r;
		}
		FOR(i,0,n-1) RA[i] = tempRA[i];
		if (r == n-1) break;
	}
} 
void buildLCP()
{
	behind[SA[0]] = -1;
	FOR(i,1,n-1) behind[SA[i]] = SA[i-1];
	int L = 0;
	FOR(i,0,n-1) {
		if (behind[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (s[i+L] == s[behind[i]+L]) L++;
		PLCP[i] = L;
		L = max(L-1,0);
	}
	FOR(i,0,n-1) LCP[i] = PLCP[SA[i]];
}


int SPT[100005][25];

void preRMQ(){
    for (int i=0; (1<<i) <= n; i++){
        for (int j=1; j+(1<<i)-1 <= n; j++){
            if (i==0){
                SPT[j][i]=LCP[j];
            }
            else{
                SPT[j][i]=min(SPT[j][i-1],SPT[j+(1<<(i-1))][i-1]);
            }
        }
    }
}

inline int getRMQ(int u, int v){
    int k=flog2(v-u+1);
    return min(SPT[u][k],SPT[v-(1<<k)+1][k]);
}

int getLCP(int i, int j) {
	return getRMQ(i + 1, j);
}

int L = 1, R = 0;

struct query{
    int l,r,stt;
}Q[100005];

int cmp(query a,query b){
	if(a.l/S !=b.l/S)
		return (a.l < b.l);
	return ((a.l/S)&1) ? (a.r<b.r) : (a.r>b.r);
}


ll Ans=0;
set<int> pos;


void add(int x){
	pos.insert(x);
	auto it = pos.find(x);
	
	if (it == --(pos.end())) {

	}
	else {
		
	}
}

void sub(int x){
}

ll res[200005];



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int q;
	cin >> n >> q;
	S = n / sqrt(q + 1) + 1;
	
	pos.insert(0);
	pos.insert(n);

	cin >> s;
	suffixArray();
	buildLCP();
	LCP[n] = n - SA[n - 1];
	preRMQ();

	FOR (i,1,q) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].stt=i;
    }
    sort(Q + 1, Q + q + 1, cmp);

    FOR (i,1,q){
        while (R>Q[i].r) {
            sub(SA[R]);
            R--;
        }
        while (R<Q[i].r){
            R++;
            add(SA[R]);
        }

        while (L<Q[i].l) {
            sub(SA[L]);
            L++;
        }
        while (L>Q[i].l){
            L--;
            add(SA[L]);
        }
        res[Q[i].stt]=Ans;
    }
    FOR (i,1,q) pf("%lld \n",res[i]);

	




	
	return 0;
}