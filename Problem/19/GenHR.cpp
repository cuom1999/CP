#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("","w",stdout)
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


const string NAME = "ROOKS";

string test(int x) {
	if (x < 10) {
		string s = "input0";
		s += (char) (x + '0');
		return s;
	}
	string s = "input";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

string testOut(int x) {
	if (x < 10) {
		string s = "output0";
		s += (char) (x + '0');
		return s;
	}
	string s = "output";
	int a = x / 10;
	int b = x % 10;
	s += (char) (a + '0');
	s += (char) (b + '0');
	return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
  
 	FOR (i, 0, 40){
 		string cmd = "nlogn <\"DataHR\\input\\" + test(i) + ".txt\">" + "\"DataHR\\output\\"
 						+ testOut(i) + ".txt\"";  
		//cout << cmd << endl; 		
		system(cmd.c_str());
 	}   


         return 0;
}