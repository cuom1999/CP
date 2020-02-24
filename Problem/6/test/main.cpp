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

int pos[20];
int n,m;

bool check(vector<int> &v){
    FOR (a,1,n){
        if (pos[a] && pos[a]!=v[a]){
            return 0;
        }
    }
    vector<int> T;
    FOR (i,1,n) T.pb(v[i]);
    sort(all(T));
    if (T[0]>1) return 0;
    FOR (i,1,n-1){
        if (T[i]!=T[i-1]){
            if (T[i]!=(i+1)) return 0;
        }
    }
    return 0;
}
int sum=0;
void gen (int q, vector<int> &v){
    if (q==n+1) {
        for (auto i:v) cout<<i<<" "; cout<<endl;
        sum++;
    }
    cout<<q<<" : ";
    for (auto i:)
    FOR(i,1,n){
        if (i>1) v.pop_back();
        v.pb(i);
        gen(q+1,v);
    }
}
vector<int> rong;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR (i,1,m){
        int a;
        cin>>a>>pos[a];
    }    

    gen (1,rong);
    cout<<sum<<endl;
    
         return 0;
}