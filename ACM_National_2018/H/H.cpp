#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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
typedef pair < ll, ll > II;

const ll K = 100003;

ll mu (ll a, ll n){
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}
ll c[1005];
ll S = 0;
ll gt[5005];
ll n, m;
    
II calc(){
	ll P = 1;
    ll Q = 1;
    FOR (i, 1, n){
    	FOR (j, i + 1, n)  P = P * (c[i] - i - c[j] + j) % K;
    }
    FOR (i, 1, n){
    	Q = Q * gt[c[i] + n - i] % K;
    }
    ll cnt = 0;
    FOR (i, 1, S){
    	ll j = i;
    	if (j % K == 0) {
    		cnt++;
    		j /= K;
    	}
    	P = P * 1ll * j % K;  
    }
    P = P * mu(Q, K - 2) % K;
    return II(cnt, P); 
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    gt[0] = 1;
    FOR (i, 1, 3000){
    	gt[i] = gt[i - 1] * 1ll * i % K;
    }

    cin >> n >> m;


    FOR (i, 1, n){
    	cin >> c[i];
    	S += c[i];
    }

    if (m == n && m == 1){
        cout << "0 0" <<endl;
        return 0;
    }


    II u = calc();
    ll res0 = u.first;
    ll res1 = u.second;
    ll S1 = S;

    FOR (i, 1, n){
    	c[i] = m - c[i];
    }

    reverse(c + 1, c + n + 1);
    S = m * n - S; 

    u = calc();
    res0 += u.first;
    res1 = res1 * u.second % K;

    S--;
    S1--;

    ll cnt = 0;
    FOR (i, S + 1, S + S1){
        ll j = i;
        if (i % K == 0){
            cnt++;
            j /= i;
        }
        res1 = res1 * 1ll * j % K;
    }
    FOR (i, 1, S1){
        ll j = i;
        if (i % K == 0){
            cnt--;
            j /= i;
        } 
        res1 = res1 * mu(j, K-2) % K;
    }

    res0 += cnt;

    cout << res0 << " " << res1 <<endl; 



	
         return 0;
}