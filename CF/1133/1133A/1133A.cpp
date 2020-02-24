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

int hourToMin(II a) {
	return a.first * 60 + a.second;
} 

II minToHour(int a) {
	return II(a / 60, a % 60);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s1;
  	string s2;

  	cin >> s1 >> s2;

  	II t1, t2;

  	t1.first = (s1[0] - '0') * 10 + (s1[1] - '0');
  	t1.second = (s1[3] - '0') * 10 + (s1[4] - '0');

	t2.first = (s2[0] - '0') * 10 + (s2[1] - '0');
  	t2.second = (s2[3] - '0') * 10 + (s2[4] - '0');

  	int T1 = hourToMin(t1);
  	int T2 = hourToMin(t2);

  	int mid = (T1 + T2) / 2;

  	t1 = minToHour(mid);

  	if (t1.first < 10) {
  		cout << 0 << t1.first;
  	}
  	else cout << t1.first;

  	cout << ":";

	if (t1.second < 10) {
  		cout << 0 << t1.second;
  	}
  	else cout << t1.second;
    
	
    return 0;
}