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

struct AhoCorasick {
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define trav(a, x) for(auto& a : x)
    #define sz(x) (int)(x).size()
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    enum {alpha = 26, first = 'A'};
    struct Node {
        // (nmatches is optional)
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
    vector<Node> N;
    vector<int> backp;
    void insert(string& s, int j) {
        assert(!s.empty());
        int n = 0;
        trav(c, s) {
            int& m = N[n].next[c - first];
            if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
            else n = m;
        }
        if (N[n].end == -1) N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
    }
    AhoCorasick(vector<string>& pat) {
        N.emplace_back(-1);
        rep(i,0,sz(pat)) insert(pat[i], i);
        N[0].back = sz(N);
        N.emplace_back(0);

        queue<int> q;
        for (q.push(0); !q.empty(); q.pop()) {
            int n = q.front(), prev = N[n].back;
            rep(i,0,alpha) {
                int &ed = N[n].next[i], y = N[prev].next[i];
                if (ed == -1) ed = y;
                else {
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
                        = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }
    }
    vi find(string word) {
        int n = 0;
        vi res; // ll count = 0;
        trav(c, word) {
            n = N[n].next[c - first];
            res.push_back(N[n].end);
            // count += N[n].nmatches;
        }
        return res;
    }
    vector<vi> findAll(vector<string>& pat, string word) {
        vi r = find(word);
        vector<vi> res(sz(word));
        rep(i,0,sz(word)) {
            int ind = r[i];
            while (ind != -1) {
                res[i - sz(pat[ind]) + 1].push_back(ind);
                ind = backp[ind];
            }
        }
        return res;
    }
};

char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
bool isVowel[200];

string noVowel(string& s) {
    string res;
    for (auto c: s) {
        if (!isVowel[c]) res += c;
    }
    return res;
}

unordered_map<string, string> original;
string s[100005];

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 0, 4) isVowel[vowel[i]] = 1;

    int n;
    cin >> n;

    int numString = 0;

    FOR (i, 1, n) {
        string cur;
        cin >> cur;
        string tmp = noVowel(cur);
        if (original.count(tmp)) {
            if (original[tmp].size() < cur.size()) {
                original[tmp] = cur;
            }
        }
        else {
            numString++;
            original[tmp] = cur;
        }
        s[numString] = tmp;
    }

    FOR (i, 1, numString) cout << s[i] << " ";

    return 0;
}