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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> v[300005];
vector<II> E;
int big[300005];

bitset<300005> bs[1100];
int dd[300005];

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    FOR (i, 1, n) {
        sort(all(v[i]));
        vector<int> tmp;
        for (int j = 0; j < v[i].size(); j++) {
            if (!j || v[i][j] != v[i][j - 1]) {
                tmp.pb(v[i][j]);
            }
        }
        v[i] = tmp;
    }

    ll res = 0;
    FOR (i, 1, n) {
        res += v[i].size() * 1ll * (v[i].size() - 1);
        for (auto j:v[i]) {
            if (i<j) E.pb(II(i,j));
        }
    }

    int u=sqrt(n)+1;
    int C=0;

    FOR (i,1,n){
    	if (v[i].size()>=u){
    		big[i]=++C;
    		for (int j=0; j<v[i].size(); j++){
    			bs[C][v[i][j]]=1;
    		}
    	}
    }

    ll cnt=0;

    FOR (i,1,n){
    	if (big[i]){
    		for (auto j:E) if (bs[big[i]][j.first] && bs[big[i]][j.second]) {
                cnt++;
                // cout << i << " " << j.first << " " << j.second << endl;
            }
    	}
    	else{
    		for (int j=0; j<v[i].size(); j++){
    			int a=v[i][j];
    			if (big[a]){
	    			for(int k=j+1; k<v[i].size(); k++){
	    				int b=v[i][k];
	    				if (bs[big[a]][b]) {
	    					// cout << i << " " << a << " " << b << endl;
                            cnt++;
	    				}
	    			}
	    		}
	    		else{
	    			for (auto q:v[a]){
	    				dd[q]=1;
	    			}
	    			for (int k=j+1; k<v[i].size(); k++){
	    				int b=v[i][k];
	    				if (dd[b]) {
                            // cout << i << " " << b << " " << a << endl;
	    					cnt++;
	    				}
	    			}
	    			for (auto q:v[a]){
	    				dd[q]=0;
	    			}
	    		}
    		}
    	}
    }

    // cout << cnt << endl;
    cout<<res-2*cnt<<endl;
	
         return 0;
}