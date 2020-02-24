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

ll solve(ll numC, ll numO) {
    if (numO < 0 || numC < 0 || (numO + numC) % 2) return 1e18;
    ll res = 1e18;

    //ope6 = 0
    if (numO >= numC) {
        res = min(res, f * numC + costDelOpen[2] * (numO - numC) / 2);
    } 

    //ope7 = 0
    if (numO <= numC) {
        res = min(res, f * numO + costDelClose[2] * (numC - numO) / 2);
    } 

    ll num5 = numO % 2;

    numC -= num5;
    numO -= num5;

    res = min(res, num5 * f + costDelOpen[2] * (numO / 2) + costDelClose[2] * (numC / 2));
    return res;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int numTest;
    cin >> numTest;
    FOR (zz, 1, numTest) {
        parenStack.clear();

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

        /*
            x close, y open
            Observation: (x, y) -> (x - 1, y), (x, y - 1), (x - 1, y + 1), (x + 1, y - 1)
                                (x - 1, y - 1), (x - 2, y), (x, y - 2)
            The first four can happen at most once
        */
        ll res = 1e18;
        FOR (num1, 0, 1) {
            FOR (num2, 0, 1) {
                FOR (num3, 0, 1) {
                    FOR (num4, 0, 1) {
                        ll tmpClose = -num1 + -num3 + num4;
                        ll tmpOpen = -num2 + num3 + -num4;
                        tmpClose = tmpClose + numClose;
                        tmpOpen = tmpOpen + numOpen;

                        ll tmpCost = num1 * costDelClose[1] + num2 * costDelOpen[1] + num3 * b + num4 * a;
                        res = min(res, solve(tmpClose, tmpOpen) + tmpCost);
                    }
                }
            }
        }


        cout << res << endl;
    }

    return 0;
}