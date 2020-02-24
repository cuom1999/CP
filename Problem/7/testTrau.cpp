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
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int MAXS = 9*9*18;

int sumDigit(ll n){
    int ret = 0;
    while(n) ret += (n % 10)*(n % 10), n/=10;
    return ret;
}

bool isDiverge[MAXS+3];
bool Have[MAXS+3];
int Stack[MAXS+3];

void checkDiverge(int n, bool& r){
    int Top = 0;
    // cout << n;
    while(1){
        if(n == 1){
            r = 0;
            break;
        }
        if(Have[n]){
            r = 1;
            break;
        }
        Have[n] = 1, Stack[++Top] = n;
        n = sumDigit(n);
    }
    // cout << " " << r << endl;
    FOR(i, 1, Top) Have[Stack[i]] = 0;
}


int main()
{//OUT;
    //IN;
    //freopen("input.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    //int n;
    
    FOR(i, 1, MAXS) checkDiverge(i, isDiverge[i]);

    int t;
    cin>>t;
    FOR (z,1,t){
        ll r=0;
        ll l1,r1;
        cin>>l1>>r1;
        FOR (i,l1,r1){
            r+=isDiverge[sumDigit(i)];           
        }
        cout<<r<<endl;
    }
         return 0;
}
