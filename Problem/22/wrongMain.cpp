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

// HKR: Parentheses Operations (HKR_Work)

ll a, b, c, d, e, f;
string s;

vector<char> parenStack;
ll costDelOpen[3], costDelClose[3]; // min cost to del i open/close parenthesis once (i = 1, 2)

// calc min cost if there's only 1 type left
ll calcCost(int type, ll num) { 
	if (type == 0) { //open
		return (num / 2 * costDelOpen[2]) + (num % 2) * costDelOpen[1];
	}
	else { //close
		return (num / 2 * costDelClose[2]) + (num % 2) * costDelClose[1];
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;

    cin >> a >> b >> c >> d >> e >> f;

    //remove unnecessary parentheses

    for (int i = 0; i < s.length(); i++) {
    	if (s[i] == '(') {
    		parenStack.pb(s[i]);
    	} 
    	else {
    		if (!parenStack.size() || parenStack.back() == ')') {
    			parenStack.pb(s[i]);
    		}
    		else {
    			parenStack.pop_back();
    		}
    	}
    }


    ll numOpen = 0, numClose = 0;

    for (int i = 0; i < parenStack.size(); i++) {
    	if (parenStack[i] == ')') numClose++;
    	else numOpen++;
    }

    //calculate min cost to del 1 or 2 parentheses once

    costDelClose[1] = min(c, d);
    costDelOpen[1] = min(c, e);

    costDelClose[2] = min(b, costDelClose[1] * 2); //only apply if there are at least 2 close paren
    costDelOpen[2] = min(a, costDelOpen[1] * 2);

    ll costDel2_2 = min(f * 2, costDelClose[2] + costDelOpen[2]); // del 2 C and 2 O once

    ll num2_2 = min(numOpen / 2, numClose / 2);

    ll res = num2_2 * costDel2_2;

    cout << numOpen << " " << numClose << endl;
    

    numOpen -= num2_2 * 2;
    numClose -= num2_2 * 2;
    FOR (i, 1, 2) cout << costDelOpen[i] << " "; cout << endl;
	FOR (i, 1, 2) cout << costDelClose[i] << " "; cout << endl;
	cout << costDel2_2 << endl;

    if (numOpen == 0) {
    	res += calcCost(1, numClose);
    }
    else if (numOpen == 1) {
    	if (numClose == 0) {
    		res += calcCost(0, numOpen);
    	}
    	else {
    		res += min(f + calcCost(1, numClose - 1), costDelOpen[1] + calcCost(1, numClose));
    	}
    }
    else {
    	if (numClose == 0) {
    		res += calcCost(0, numOpen);
    	}
    	else {//numClose = 1
    		res += min(f + calcCost(0, numOpen - 1), costDelClose[1] + calcCost(0, numOpen));
    	}
    }

    cout << res << endl;






    return 0;
}