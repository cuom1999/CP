#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
ll t[2000],v[2000];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
vector<int> S;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));

    ll m,n,d;
        cin>>m>>n>>d;
        //if (m>n) swap(m,n);
        if (n==0) return 0;
        ll s=0,ss=0,s1=0;
        FOR (i,1,m) t[i]=1;
        FOR (i,1,m+n) v[i]=i;
        FOR (z,1,60000){bool q=0;
            ll u=0;
            while (1) {ll r=0,r1=0;
                S.clear();

                FOR (i,1,m+n) S.pb(i);
                ll uu=0;
                while (!S.empty()){
                    ll vv=Rand(0,(int) S.size() -1);
                    uu++; v[uu]=S[vv];
                    S.erase(S.begin()+vv);
                }
                //FOR (i,1,m+n) cout<<v[i]<<" "; cout<<endl;

                u++;
                FOR (i,1,m+n-1) {
                    if (t[v[i]]+t[v[i+1]]==0) r++;
                    if (t[v[i]]+t[v[i+1]]==2) r1++;

                }
                if (t[v[1]]+t[v[m+n]]==0) r++;
                if (t[v[1]]+t[v[m+n]]==2) r1++;
                //cout<<r<<endl;

                if (r<=d && r1<=d ) {ss+=u;s+=r;s1+=r1;break;}

                 //{FOR (i,1,m+n) cout<<v[i]<<" ";cout<<endl;cout<<r<<" "<<r1<<" "<<d<<endl;}
                //FOR (i,1,m+n) cout<<v[i]<<" ";cout<<endl;
            }//while (next_permutation(v+2,v+m+n+1));
            //cout<<z<<endl;
        }
        cout<<fixed<<setprecision(8)<<(ld) s1/60000.0<<" "<< (ld) s/60000.0<<endl<<(ld) ss/60000.0<<endl;;

         return 0;
}
