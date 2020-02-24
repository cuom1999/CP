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

set<int> S;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int N = n;
    int m = 0;
    int res = 1;
    for (int i = 2; i <= n / i; i++){
    	int cnt = 0;
    	if (n % i == 0) {
    		res *= i;
    		while (n % i == 0) {
    			n /= i;
    			cnt++;
    		} 
    	}
    	m = max(m, cnt);
    	if (cnt) S.insert(cnt);
    }
    res *= n; 
    if (n > 1) {
    	m = max(m, 1);
    	S.insert(1);
    }

    if (N == 1){
    	cout << 1 << " " << 0 <<endl;
    }
    else{
    	if (res == N) cout << res << " 0";
    	else if (S.size() == 1 && (1 << flog2(m)) == m){
    		cout << res << " " << flog2(m - 1) + 1 << endl;
    	}
    	else{
    		cout << res << " " << flog2(m - 1) + 2 << endl;
    	}
    }
	
         return 0;
}