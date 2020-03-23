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



int main()
{//IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    int p;
    cin >> s >> p;

    ll res = 0;
    int n = s.size();
    // find all substr with len <= 20
    FOR (i, 0, n - 1) {
        int val = 0;        
        for (int j = i; j < n && j < i + 20; j++) {
            val = val * 10 + s[j] - '0';
            val %= p;
            if (val == 0) {
                res++;
            }
        }
    }
    if (n <= 20) {
        cout << res << endl;
        return 0;
    }

    int pw2 = 1;
    int pw5 = 1;
    
    while (p % 2 == 0) {
        p /= 2;
        pw2 *= 2;
    }

    while (p % 5 == 0) {
        p /= 5;
        pw5 *= 5;
    }
    // find all position that a substr can end at
    int curVal2 = 0, curVal5 = 0;
    vector<bool> canEnd(n);

    FOR (i, 0, n - 1) {
        curVal2 = curVal2 * 10 + s[i] - '0';
        curVal2 %= pw2;

        curVal5 = curVal5 * 10 + s[i] - '0';
        curVal5 %= pw5;

        if (curVal2 == 0 && curVal5 == 0 && i >= 19) {
            canEnd[i] = 1;
            // cout << i << endl;
        }
    }

    // calc suffix
    vector<ll> suffixSum(n + 1);
    ll curPow = 1;
    FORD (i, n - 1, 0) {
        suffixSum[i] = curPow * (s[i] - '0') + suffixSum[i + 1];
        suffixSum[i] %= p;
        curPow = curPow * 10 % p;
        // cout << i << " " << suffixSum[i] << endl;
    }

    // j - i >= 20
    vector<ll> cnt(p + 1);
    FORD (i, n - 21, 0) {
        // update
        if (canEnd[i + 20]) {
            cnt[suffixSum[i + 21]]++;
        }

        res += cnt[suffixSum[i]];
    }

    cout << res << endl;
    return 0;
}