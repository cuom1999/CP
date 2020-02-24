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

ll L=1,R=0;

int S, n, q, k;

struct query{
    int l, r, stt;
}Q[100005];

int cmp(query a,query b){
	if(a.l/S !=b.l/S)
		return (a.l < b.l);
	return ((a.l/S)&1) ? (a.r<b.r) : (a.r>b.r);
}

ll b[2000005], c[2000005];

ll ans=0;
ll aa[100005], a[100005];
ll res[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q >> k;
    S = n / sqrt(q) + 1; // optimal when S = n/sqrt(q);

    FOR (i, 1, n) cin >> aa[i];
    FOR (i, 1, n) a[i] = a[i - 1] ^ aa[i];
    //FOR (i, 1, n) cout << a[i] << " "; cout << endl;
    FOR (i, 1, q) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].stt = i;
    }
    sort(Q+1, Q+q+1, cmp);

    FOR (i,1,q){
        while (R > Q[i].r) {
        	R--;
        	ans -= b[a[R + 1] ^ k];
        	b[a[R]]--;
        	c[a[R + 1]]--;
        	//cout << L << " " << R << " " << ans << endl;
        }
        while (R < Q[i].r){
            R++;
            b[a[R - 1]]++;
            ans += b[a[R] ^ k];
            c[a[R]]++;
        }
        while (L < Q[i].l) {
        	ans -= c[a[L - 1] ^ k];
        	b[a[L - 1]]--;
        	c[a[L]]--;
        	L++;
        	//cout << L << " " << R << " " << ans << endl;
        }
        while (L > Q[i].l){
            L--;
            c[a[L]]++;
            ans += c[a[L - 1] ^ k];
            b[a[L - 1]]++;
        }

        res[Q[i].stt] = ans;
    }
    FOR (i, 1, q) cout << res[i] << endl;


    return 0;
}
