#include <bits/stdc++.h>

#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,A,B) for(ll i=A ; i<=B ; i++)
#define FORD(i,A,B) for(int i=A ; i>=B ; i--)
#define ll long long int

using namespace std;


const ll K = 998244353;

vector<vector<ll>> d, g;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int n = a.length();
    
    ll numSame = 0;
    ll numDiff = 0;

    FOR (i, 0, n - 1) {
        if (a[i] == '1') {
            if (a[i] == b[i]) {
                numSame++;
            }   
            else {
                numDiff++;
            }
        }
    }

    d.resize(numDiff + 1);
    FOR (i, 0, numDiff) d[i].resize(numSame + 1);

    g.resize(numDiff + 1);
    FOR (i, 0, numDiff) g[i].resize(numSame + 1);

    d[0][0] = 1;

    int total = numSame + numDiff;

    FOR (n, 1, total) {
        FOR (B, 0, min(numDiff, n)) {
            FOR (C, 0, min(numSame, n)) {
                ll A = n - B - C;
                ll val1 = 0;
                ll val2 = 0;
                ll val3 = 0;
                ll val4 = 0;
                if (A >= 1) {
                    val1 = d[B][C] * A % K * (2 * C + B + 1) % K;
                }
                if (B >= 1) {
                    val2 = d[B - 1][C] * B % K * B % K;
                }
                if (C >= 1) {
                    val3 = d[B][C - 1] * C % K * C % K;
                }
                if (A >= 2) {
                    val4 = d[B][C + 1] * (A * A % K - A) % K;
                }

                if (A || B || C) {
                    g[B][C] = (val1 + val2 + val3 + val4) % K;
                }
            }
        }

        FOR (B, 0, min(numDiff, n)) {
            FOR (C, 0, min(numSame, n)) {
                d[B][C] = g[B][C];
            }
        }
    }


    cout << (d[numDiff][0] + K) % K << endl;
    return 0;
}