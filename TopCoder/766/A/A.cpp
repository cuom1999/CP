#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

struct Alibi{
	string findMurderer(string murderRoom, int murderTime, vector <int> eventTime, vector <string> eventPerson, vector <string> eventRoom) {
		map<string, set<string>> s;
		map<string, string> room;
		string name[6] = {"White", "Green", "Peacock", "Plum", "Scarlett", "Mustard"};
		FOR (i, 0, 5) {
			s["Hall"].insert(name[i]);
			room[name[i]] = "Hall";
		}

		for (int i = 0; i < eventRoom.size(); i++) {
			if (eventTime[i] <= murderTime) {
				s[room[eventPerson[i]]].erase(eventPerson[i]);
				s[eventRoom[i]].insert(eventPerson[i]);
				room[eventPerson[i]] = eventRoom[i];
			}
		}
		if (s[murderRoom].size() == 1) return *s[murderRoom].begin();
		return "";
	}
};

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	Alibi a;
	cout << a.findMurderer("Library",
10,
{3, 7},
{"Plum", "Plum"},
{"Library", "Library"});

	return 0;
}