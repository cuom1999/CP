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

int d[5005];


string s,p;
int z[5005][5005];

void compute_z(string &s, int z[]){
    int n=s.length();
    int x=0,y=0;
    z[0] = n;
    FOR (i,1,n-1){
        z[i]=max(0,min(z[i-x],y-i+1));
        while (i+z[i]<n && s[z[i]]==s[z[i]+i]){
            x=i;y=i+z[i];z[i]++;
        }
    }
}

string suff[5005];
vector<int> v[5005];
int pre[5005];
bitset<5005> bs[5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);


    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;

    FOR (i, 0, n - 1) {
    	FOR (j, i, n - 1) {
    		suff[i] += s[j];
    	}

    	compute_z(suff[i], z[i]);
    }

    FOR (i, 0, n - 1) {
    	FOR (j, i, n - 1) {
    		int val = min(j - i, z[i][j - i]);
    		pre[j] = max(pre[j], val);
    	}
    }

    FOR (i, 0, n - 1) {
    	FOR (j, i, i + pre[i] - 1) {
    		bs[j][i] = 1;
    	}
    }

    d[0] = a;

    FOR (i, 1, n - 1) {
    	d[i] = d[i - 1] + a;
    	FOR (j, 0, i - 1) {
    		if (bs[i][j + 1]) {
    			d[i] = min(d[i], d[j] + b);
    		}
    	}
    }

    cout << d[n - 1] << endl;



    return 0;
}