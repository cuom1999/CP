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
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int n = a.length();

    vector<int> A, B;

    FOR (i, 0, n - 1) {
        if (a[i] == '1') {
            A.pb(i);
        }

        if (b[i] == '1') {
            B.pb(i);
        }
    }
    int m = A.size();
    sort(all(A));
    sort(all(B));

    ll res = 0;
    do {
        do {
            string tmpA = a;
            FOR (i, 0, m - 1) {
                swap(tmpA[A[i]], tmpA[B[i]]);
            }

            if (tmpA == b) {
                FOR (i, 0, m - 1) cout << A[i] << " ";
                cout << endl;
                FOR (i, 0, m - 1) cout << B[i] << " ";
                cout << endl;
                cout << endl;
                res++;
            }
        } while (next_permutation(B.begin(), B.end()));
    } while (next_permutation(A.begin(), A.end()));

    cout << res << endl;
    return 0;
}