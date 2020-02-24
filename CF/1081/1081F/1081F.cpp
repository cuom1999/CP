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

#define LOCAL true

bitset<305> bs;
int n, t;
int cnt = 0;
    
void input() {
    if (!LOCAL) {
        cin >> n >> t;
    }
    else {
        string s;
        cin >> s;
        n = s.size();
        
        FOR (i, 1, n) {
            if (s[i - 1] == '1') bs[i] = 1;
        }
        t = bs.count();
    }
}

int ask(int l, int r) {
    cnt++;
    if (LOCAL) {
        if (rand() % 2) {
            FOR (i, 1, r) {
                bs.flip(i);
            }
        }
        else {
            FOR (i, l, n) {
                bs.flip(i);
            }
        }
        return bs.count();
    }
    else {
        cout << "? " << l << " " << r << endl;
        int res;
        cin >> res;
        return res;
    }
}

void reset(int l, int r) {
    int curT;
    // cout << "Reseting" << endl;
    while (1) {
        FOR (i, 1, 2) curT = ask(l, r);
        if (curT == t) break;
    }
    // cout << "Finish resetting" << endl;
}

int count(int l, int r) { // return count[1, r]
    assert((l + r - n) % 2 == 0);
    assert(l <= r);
    int res;
    while (1) {
        int curT = ask(l, r);
        int diff = curT - t;
        if ((diff - r) % 2) {
            ask(l, r);
            reset(l, r);
        }
        else {
            res = (r - diff) / 2;
            break;
        }
    }
    ask(l, r);
    reset(l, r);
    return res;
}

int count2(int l, int r) {
    assert(l <= r);
    int res;
    while (1) {
        int curT = ask(l, r);
        int diff = curT - t;
        if ((diff - (n - l + 1)) % 2) {
            ask(l, r);
            reset(l, r);
        }
        else {
            res = ((n - l + 1) - diff) / 2;
            break;
        }
    }
    ask(l, r);
    reset(l, r);
    return res;
}

int main()
{
    if (LOCAL) IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));
    input();

    if (n == 1) {
        cout << "! " << t << endl;
        return 0;
    }

    string res;
    int cur = 0;

    vector<int> s(n + 1), a(n + 1);
    if (n % 2 == 0) {
        FOR (i, 1, n) {
            s[i] = count(i, i);
        }
    }
    else {
        FOR (i, 2, n) {
            s[i] = count(i - 1, i);
        }
        s[1] = t - count2(2, n);
    }
    FOR (i, 1, n) {
        a[i] = s[i] - s[i - 1];
        res += (a[i] + '0');
    }
    cout << "! " << res << endl;


    return 0;
}