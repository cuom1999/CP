#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

int SPT[100005][25], SPT2[100005][25];
int n, c[100005], d[100005];

void preRMQ(){
    for (int i=0; (1<<i) <= n ; i++){
        for (int j=1; j+(1<<i)-1<= n; j++){
            if (i==0){
                SPT[j][i] = c[j];
                SPT2[j][i] = d[j] ; 
            }
            else{
                SPT[j][i]=max(SPT[j][i-1],SPT[j+(1<<(i-1))][i-1]);
             	SPT2[j][i]=max(SPT2[j][i-1],SPT2[j+(1<<(i-1))][i-1]);
            }
        }
    }
}

inline int getMaxC(int u, int v){
    int k = flog2(v - u + 1);
    return max(SPT[u][k], SPT[v-(1<<k)+1][k]);
}

inline int getMaxD(int u, int v){
    int k = flog2(v - u + 1);
    return max(SPT2[u][k], SPT2[v-(1<<k)+1][k]);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int t;
	cin >> t;
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int k;
		cin >> n >> k;

		FOR (i, 1, n) {
			cin >> c[i];
		}    

		FOR (i, 1, n) {
			cin >> d[i];
		}
		preRMQ();

		ll res = 0;

		FOR (i, 1, n) {
			int L = 1, R = i;

			while (L < R) {
				int mid = (L + R) / 2;
 				if (getMaxC(mid, i - 1) >= c[i]) {
					L = mid + 1;
				} 
				else {
					R = mid;
				}
			}

			int a, b;
			a = L;

			L = i, R = n;
			while (L < R) {
				int mid = (L + R + 1) / 2;
				if (getMaxC(i, mid) > c[i]) {
					R = mid - 1;
				}
				else {
					L = mid;
				}
			}

			b = L;

			int l1, r1, l2, r2;

			L = 1, R = i;

			while (L < R) {
				int mid = (L + R) / 2;
				// cout << mid << " " << getMaxD(mid, i) << endl;
				if (getMaxD(mid, i) > c[i] + k) {
					L = mid + 1;
				}
				else R = mid;
			}

			l2 = L;

			L = 1, R = i;

			while (L < R) {
				int mid = (L + R + 1) / 2;
				if (getMaxD(mid, i) < c[i] - k) {
					R = mid - 1;
				}
				else {
					L = mid;
				}
			}

			l1 = L;

			L = i, R = n;

			while (L < R) {
				int mid = (L + R + 1) / 2;
				if (getMaxD(i, mid) > c[i] + k) {
					R = mid - 1;
				}
				else {
					L = mid;
				}
			}

			r2 = L;

			L = i, R = n;

			while (L < R) {
				int mid = (L + R) / 2;
				// cout << mid << " " << getMaxD(i, mid) << endl;
				if (getMaxD(i, mid) >= c[i] - k) {
					R = mid;
				}
				else {
					L = mid + 1;
				}
			}

			r1 = L;
 

			// cout << l2 << " " << l1 << " " << r1 << " " << r2 << endl;
			// cout << a << " " << b << endl;
			l2 = max(l2, a);
			r2 = min(r2, b);

			ll cnt = 0;

			bool e1 = abs(getMaxD(l2, i) - c[i]) <= k;
			bool e2 = abs(getMaxD(i, r2) - c[i]) <= k;

			if (e1 && l2 <= l1) {
				cnt += (l1 - l2 + 1) * 1ll * (r2 - i + 1);
			}
			if (e2 && r1 <= r2) {
				cnt += (r2 - r1 + 1) * 1ll * (i - l2 + 1); 
			}
			if (e1 && e2 && l2 <= l1 && r1 <= r2) {
				cnt -= (r2 - r1 + 1) * 1ll * (l1 - l2 + 1);
			}

			res += cnt;
			// cout << cnt << endl;
		}

		cout << res << endl;
	}
	
	return 0;
}