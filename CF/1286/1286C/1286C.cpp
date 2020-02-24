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

vector<string> ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    vector<string> res;
    string s;
    int m = (r - l + 1) * (r - l + 2) / 2;
    FOR (i, 1, m) {
        cin >> s;
        res.pb(s);
    }
    return res;
}

vector<char> big[105][3];


void process(vector<string>& v, int n, int t) {
    vector<string> bucket[105];
    for (auto &s: v) {
        bucket[s.size()].pb(s);
    }
    
    vector<char> res[105];
    multiset<char> remain;
    for (auto i: bucket[1]) remain.insert(i[0]);
    int pos = 0;
    FORD (i, n - 1, 1) {
        pos++;        
        if (remain.size() <= 2) {
            for (auto j: remain) {
                res[pos].pb(j);
            }
            break;
        }
        vector<int> cnt(27), cnt1(27);
        for (auto &s: bucket[i]) {
            for (auto j: s) {
                cnt[j - 'a']++;
            }
        }
        FOR (j, 1, pos - 1) {
            for (auto k: res[j]) {
                cnt[k - 'a'] -= min(j, i);
            }
        }
        for (auto c: remain) {
            cnt1[c - 'a'] += n + 1 - i;
        }
        
        FOR (j, 0, 25) {
            if (cnt[j] != cnt1[j]) {
                res[pos].pb(j + 'a');
                // cout << j << " ";
            }
        }
        if (res[pos].size() == 1) {
            res[pos].pb(res[pos][0]);
        }
        for (auto j: res[pos]) {
            remain.erase(remain.find(j));
        }

    }
    if (n == 1) {
        res[1].pb(v[0][0]);
    }
    FOR (i, 1, n) {
        // for (auto j: res[i]) cout << j << " "; cout << endl;
        big[i][t] = res[i];
    }
} 

char res[105];

char rest(vector<char>& v, char c) {
    if (v.size() == 1) return c;
    if (v[0] == c) return v[1];
    return v[0];
}

// get from 1 to m
void getAll(int m) {
    vector<string> v1 = ask(1, m);
    if (m == 1) {
        res[1] = v1[0][0];
        return;
    }
    process(v1, m, 1);
    vector<string> v2 = ask(1, m - 1);
    process(v2, m - 1, 2);
    vector<int> cnt(26);
    FOR (i, 1, m) {
        for (auto j: big[i][1]) {
            cnt[j - 'a']++;
        }
        for (auto j: big[i][2]) {
            cnt[j - 'a']--;
        }
    }
    FOR (i, 0, 25) {
        if (cnt[i]) {
            res[m] = i + 'a';
            break;
        }
    }
    vector<int> num;
    vector<vector<char>> charSet;

    int j = m - 1;
    int i = 1;
    while(1) {
        num.pb(i);
        if (j > i) num.pb(j);
        i++; j--;
        if (i > j) break;
    }
    char last = res[m];
    FOR (i, 1, m) {
        charSet.pb(big[i][1]);
        charSet.pb(big[i][2]);
    }

    FOR (i, 0, m - 2) {
        // cout << num[i] << " " << last << " - ";
        // for (auto j: charSet[i]) cout << j << " ";
        // cout << endl;
        res[num[i]] = rest(charSet[i], last);
        last = res[num[i]];
    }
}


int main()
{//IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<string> a = ask(1, n);
    if (n == 1) {
        cout << "! " << a[0][0] << endl;
        return 0;
    }

    process(a, n, 0);
    int mid = n / 2;
    getAll(mid);
    FOR (i, 1, mid) {
        res[n + 1 - i] = rest(big[i][0], res[i]);
    }

    if (n % 2) {
        res[mid + 1] = big[mid + 1][0][0];
    }
    cout << "! "; 
    FOR (i, 1, n) cout << (char) res[i];
    cout << endl;



    return 0;
}