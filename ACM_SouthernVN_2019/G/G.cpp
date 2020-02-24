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

typedef pair < int, int > II;
typedef pair < ll, II > III;

ll l[100005];
map<ll, vector<int> > v;

struct Quad {
    vector<int> v;

    Quad() {
        v.resize(4);
    }

    bool operator < (const Quad& q) {
        FOR (i, 0, 3) {
            if (v[i] < q.v[i]) return true;
            if (v[i] > q.v[i]) return 0;
        }
        return 0;
    }
};

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n; ll s;
    cin >> n >> s;

    FOR (i, 1, n) {
        cin >> l[i];
        v[l[i]].pb(i);
    }

    ll area = -1;
    Quad res;
    vector<III> len;

    for (auto i: v) {
        if (i.second.size() >= 4 && i.first <= s / i.first) {
            Quad u;
            u.v = {i.second[0], i.second[1], i.second[2], i.second[3]};
                
            if (area < i.first * i.first) {
                area = i.first * i.first;
                res = u;
            }
            else if (area == i.first * i.first) {
                // res = min(res, u);
                if (u < res) res = u;
            }
        }

        if (i.second.size() >= 2) {
            len.pb({i.first, {i.second[0], i.second[1]}});
        }
    }

    int j = (int) len.size() - 1;

    for (int i = 0; i < len.size(); i++) {
        while (j >= 1 && len[j].first > s / len[i].first) {
            j--;
        }
        
        if (i >= j) break;


        ll curArea = len[i].first * len[j].first;
        Quad u;
        u.v = {len[i].second.first, len[i].second.second, len[j].second.first, len[j].second.second};
        sort(all(u.v));

        if (curArea == area) {
            // res = min(res, u);
            if (u < res) res = u;
        }
        else if (curArea > area) {
            res = u;
            area = curArea;   
        }
    }

    if (area == -1) cout << -1 << endl;
    else for (auto i: res.v) cout << i << " ";

    return 0;
}