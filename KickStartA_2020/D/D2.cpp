#include <bits/stdc++.h>

#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define ll long long int
#define all(x) x.begin(),x.end()

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;

struct HashModule {
    ll mod;
    vector<ll> pw,h;
    void init(string s, ll base, ll p){
        mod=p;
        pw.resize(s.length()+1);
        h.resize(s.length()+1);
        pw[0]=1;
        FOR (i,1,s.length()) pw[i]=pw[i-1]*base%mod;
        h[0]=s[0];
        FOR (i,1,s.length()-1){
            h[i]=(h[i-1]*base+s[i])%mod;
        }
    }
    ll query(int l, int r){
        if (!l) return h[r];
        return (h[r]-h[l-1]*pw[r-l+1]+mod*mod)%mod;
    }
};

struct DoubleHash{
    HashModule hm1,hm2;
    void init(string s, ll base1, ll mod1, ll base2, ll mod2){
        hm1.init(s,base1,mod1);
        hm2.init(s,base2,mod2);
    }
    II query(int l, int r){
        return II(hm1.query(l,r),hm2.query(l,r));
    }
};

const ll BASE1 = 4599;
const ll MOD1 = 1e9 + 7;
const ll BASE2 = 3719239;
const ll MOD2 = 1e8 + 7;

int commonPrefix(string& a, string& b) {
    DoubleHash hashA, hashB;
    hashA.init(a, BASE1, MOD1, BASE2, MOD2);
    hashB.init(b, BASE1, MOD1, BASE2, MOD2);

    int lower = 0, upper = (int) min(a.size(), b.size());
    while (lower < upper) {
        int mid = (lower + upper + 1) / 2;
        if (hashA.query(0, mid - 1) == hashB.query(0, mid - 1)) {
            lower = mid;
        }
        else {
            upper = mid - 1;
        }
    }
    return lower;
}

bool cmp(string& a, string& b) {
    // cout << a << " " << b << endl;
    int common = commonPrefix(a, b);
    if (a.size() == common) {
        return true;
    }
    if (b.size() == common) {
        return false;
    }
    // cout << common << endl;
    return a[common] < b[common];
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[i] = i;
        stable_sort(all(pos), [&](int i, int j) {
            // cout << i << " " << j << endl;
            return cmp(s[i], s[j]);
        });

        vector<int> lcp(n); // lcp[i] = lcp(s[pos[i]], s[pos[i - 1]])
        for (int i = 1; i < n; i++) {
            lcp[i] = commonPrefix(s[pos[i]], s[pos[i - 1]]);
        }

        multiset<int> mset;
        vector<int> dp(n + 1), ma(n + 1);
        for (int i = 1; i <= n; i++) {
            mset.insert(lcp[i - 1]);
            if (i >= k) {
                mset.erase(mset.find(lcp[i - k]));
                dp[i] = ma[i - k] + *mset.begin();
            }
            ma[i] = max(ma[i - 1], dp[i]);
        }
        cout << "Case #" << z << ": " << ma[n] << "\n";
    }
    return 0;
}
