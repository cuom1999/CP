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

const int N = 29;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int u = Rand(0, (1 << 30) - 1);
int v = Rand(0, (1 << 30) - 1);
int cnt = 0;

int query(int A, int B) {
	cnt++;
	if ((A ^ u) > (B ^ v)) return 1;
	if ((A ^ u) == (B ^ v)) return 0;
	return -1;
}

void test() {
	
	int A = 0, B = 0;
    int prev = 2;

	FORD (i, N, 0) {
    	int c1, c2;
    	if (prev != 2) c1 = prev;
    	else {
    		c1 = query(A, B);
    	}
    	c2 = query(A + (1 << i), B + (1 << i));

    	if (c1 != -1 && c2 != -1) {
    		int c3 = query(A, B + (1 << i));
    		if (c3 == 1) {
    			A += (1 << i);
    			B += (1 << i);
    		}
    		prev = c1;
    	}
    	else if (c1 != 1 && c2 != 1) {
    		int c3 = query(A, B + (1 << i));
    		
    		if (c3 == 1) {
    			A += (1 << i);
    			B += (1 << i);
    		}
    		prev = c1;
    	}
    	else if (c1 == 1){
    		A += (1 << i);
    		prev = 2;
    	}
    	else {
    		B += (1 << i);
    		prev = 2;
    	}
    }
    if (A == u && B == v) cout << "True " << cnt << endl;
    else cout << "F" << endl; 
}

int main()
{//IN;
	//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //cout << u << " " << v << endl;
    //test();
    //return 0;
    int A = 0, B = 0;
    int prev = 2;

    FORD (i, N, 0) {
    	int c1, c2;
    	if (prev != 2) c1 = prev;
    	else {
    		cout << "? " << A << " " << B << endl;
    		cin >> c1;
    	}
    	cout << "? " << (A + (1 << i)) << " " << (B + (1 << i)) << endl;
    	cin >> c2;
    	if (c1 != -1 && c2 != -1) {
    		cout << "? " << A << " " << (B + (1 << i)) << endl;
    		int c3;
    		cin >> c3;
    		if (c3 == 1) {
    			A += (1 << i);
    			B += (1 << i);
    		}
    		prev = c1;
    	}
    	else if (c1 != 1 && c2 != 1) {
    		cout << "? " << A << " " << (B + (1 << i)) << endl;
    		int c3;
    		cin >> c3;
    		if (c3 == 1) {
    			A += (1 << i);
    			B += (1 << i);
    		}
    		prev = c1;
    	}
    	else if (c1 == 1){
    		A += (1 << i);
    		prev = 2;
    	}
    	else {
    		B += (1 << i);
    		prev = 2;
    	}
    }
    cout << "! " << A << " " << B << endl; 
    
	
    return 0;
}