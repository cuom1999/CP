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
typedef pair < ll, ll > II;

struct HashModule {
    ll mod;
    vector<ll> pw,h;
    void init(string s, ll base, ll p){
        mod=p;
        pw.resize(s.length()+1);
        h.resize(s.length()+1);
        pw[0]=1;
        FOR (i,1,s.length()) pw[i]=pw[i-1]*base%mod;
        h[0]=s[0];
        FOR (i,1,s.length()-1){
            h[i]=(h[i-1]*base+s[i])%mod;
        }
    }
    ll query(ll l, ll r){
        if (!l) return h[r];
        return (h[r]-h[l-1]*pw[r-l+1]+mod*mod)%mod;
    }
};

struct DoubleHash{
    HashModule hm1,hm2;
    void init(string s, ll base1, ll mod1, ll base2, ll mod2){
        hm1.init(s,base1,mod1);
        hm2.init(s,base2,mod2);
    }
    II query(ll l, ll r){
        return II(hm1.query(l,r),hm2.query(l,r));
    }
};

DoubleHash dhash;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    dhash.init(s,2311LL,(ll) (1e9+7), 1992LL, (ll) (1e8+7));
         return 0;
}
