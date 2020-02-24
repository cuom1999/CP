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

/* z[i] : longest prefix at pos i*/

string s,p;
int z[200005];

void compute_z(string s){
    int n=s.length();
    int x=0,y=0;
    FOR (i,1,n-1){
        z[i]=max(0,min(z[i-x],y-i+1));
        while (i+z[i]<n && s[z[i]]==s[z[i]+i]){
            x=i;y=i+z[i];z[i]++;
        }
    }
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    cin>>p;
    s=p+"#"+s;
    compute_z(s);

    //FOR (i,0,s.length()-1) cout<<z[i]<<" ";
    FOR (i,p.length()+1,s.length()-1) {
        if (z[i]==p.length()) cout<<i-p.length()<<" ";
    }
         return 0;
}
