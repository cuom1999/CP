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


string Link="data\\";

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


string Number_To_String(int a){
    string s;
    int aa=a;
    while (a){
        int b=a%10;
        s+=b+'0';
        a/=10;
    }
    reverse(all(s));
    if (aa<10) s='0'+s;
    return s;
}

string testcase(int a){
    string s="test";
    s+=Number_To_String(a);
    s+=".in";
    return Link+s;
}


string sol(int a){
    string s="test";
    s+=Number_To_String(a);
    s+=".out";
    return Link+s;
}

map<ll,ll> d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    // Start from here

    FOR (iT,31,34){
        string s=testcase(iT);
        ofstream inp(testcase(iT));
        //cout<<iT<<endl;
        ll n=Rand(1,1000000), L=n+1;
        inp<<n<<" "<<L<<endl;
        vector<int> v;

        FOR (i,1,n){
            v.pb(i);     
        }
        random_shuffle(all(v));
        for (int i=0; i<v.size(); i++){
            inp<<v[i]<<" "; 
        }
        inp.close();
        system(("D:\\DINH\\C++\\Problem\\11\\main.exe <D:\\DINH\\C++\\Problem\\11\\"+testcase(iT)+">D:\\DINH\\C++\\Problem\\11\\"+sol(iT)).c_str());
        //cout<<"D:\\DINH\\C++\\Problem\\11\\main.exe <D:\\DINH\\C++\\Problem\\11\\"+testcase(iT)+">D:\\DINH\\C++\\Problem\\11\\"+sol(iT)<<endl;
    }


         return 0;
}
