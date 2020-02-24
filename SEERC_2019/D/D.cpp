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
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    sort(all(s));
    int n = s.size();
    if (s[0] == s[s.size() - 1]) {
        cout << "NO";
    }
    else {
        vector<int> cnt(500);
        for (auto i: s) {
            cnt[i]++;
        }   
        char c = '0';
        char bigC = '0';
        int maxVal = -1;
        FOR (i, 'a', 'z') {
            maxVal = max(maxVal, cnt[i]);
            if (cnt[i] > 1 && cnt[i] <= n / 2) {
                c = i;
            }
            if (cnt[i] > n / 2) {
                bigC = i;
            }
        }
        if (maxVal == 1) {
            cout << "YES\n";
            cout << s << endl;
            return 0;
        }
        if (bigC != '0') {
            if (cnt[bigC] == n - 1) {
                cout << "NO\n";
                return 0;
            }
            string res;
            FOR (i, 1, n / 2) {
                res += bigC;
            }
            cnt[bigC] -= n / 2;
            string tmp;
            FOR (i, 'a', 'z') {
                if (i != bigC) {
                    FOR (j, 1, cnt[i]) {
                        tmp += i;
                    }
                }
            }
            char last = tmp.back();
            tmp.pop_back();
            FOR (i, 1, cnt[bigC]) {
                tmp += bigC;
            }
            tmp += last;
            res += tmp;
            cout << "YES" << endl << res << endl;
        }
        else {
            char c;
            FOR (i, 'a', 'z') {
                if (cnt[i] > 1) {
                    c = i;
                    break;
                }
            }
            string tmp;
            FOR (i, 'a', 'z') {
                if (i != c) {
                    FOR (j, 1, cnt[i]) {
                        tmp += i;
                    }
                }
            }
            tmp.insert(tmp.begin() + n / 2, c);
            FOR (i, 1, cnt[c] - 1) {
                tmp += c;
            }
            cout << "YES" << endl << tmp << endl;
        }
    }

    return 0;
}