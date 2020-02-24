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


string Number_To_String(int a){
    string s;
    while (a){
        int b=a%10;
        s+=b+'0';
        a/=10;
    }
    reverse(all(s));
    return s;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    system("D: && \"cd \"D:\\DINH\\C++\\Problem\\Minimum Difference\\Minimum Difference\\testcases\" \"");
    FOR (i,1,24){
    	//cout<<i<<endl;
    	string s=Number_To_String(i);
    	string t="test";
    	t+=s; t+=".txt";
    	s+=".in";
    	system(("D: && cd \"D:\\DINH\\C++\\Problem\\Minimum Difference\\Minimum Difference\\testcases\" && rename "+s+" "+t).c_str());
    	//cout<<(string)("D: && \"cd \"D:\\DINH\\C++\\Problem\\Minimum Difference\\Minimum Difference\\testcases\" \" && rename "+s+" "+t)<<endl;
    }
	
         return 0;
}