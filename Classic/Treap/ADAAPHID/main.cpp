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

namespace Treap {
    struct Node {
        Node *l = 0, *r = 0;
        ll val;
        ll sum;
        ll id;
        int y, c = 1;
        Node(ll val) : val(val), y(rand() * rand()), sum(0), id(0) {}
        void recalc();
    };

    int size(Node* n) { return n ? n->c : 0; }
    ll sumOf(Node* n) {
        return n ? n->sum: 0;
    }
    void Node::recalc() { 
        c = size(l) + size(r) + 1;
        sum = sumOf(l) + sumOf(r) + id;
    }

    void print(Node* n) {
        if (n) { print(n->l); cout << n->val << " "; print(n->r); }
    }

    // split n into [0, k] and [k + 1, size(n) - 1]
    pair<Node*, Node*> split(Node* n, int k) {
        if (!n) return {};
        if (size(n->l) >= k) { // "n->val >= k" for lower_bound(k)
            auto pa = split(n->l, k);
            n->l = pa.second;
            n->recalc();
            return {pa.first, n};
        } else {
            auto pa = split(n->r, k - size(n->l) - 1); // and just "k"
            n->r = pa.first;
            n->recalc();
            return {n, pa.second};
        }
    }

    Node* merge(Node* l, Node* r) {
        if (!l) return r;
        if (!r) return l;
        if (l->y > r->y) {
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        } else {
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        }
    }

    Node* insert(Node* t, Node* n, int pos) {
        auto pa = split(t, pos);
        return merge(merge(pa.first, n), pa.second);
    }

    // Example application: move the range [l, r] to index k
    void moveRange(Node*& t, int l, int r, int k) {
        r++;
        Node *a, *b, *c;
        tie(a,b) = split(t, l); tie(b,c) = split(b, r - l);
        if (k <= l) t = merge(insert(a, b, k), c);
        else t = merge(a, insert(c, b, k - r));
    }

    int findPos(Node* n, ll val) {
        if (!n) return 0;
        // cout << n->val << " " << size(n) << " " << val << endl;
        if (n->val <= val) {
            return size(n->l) + 1 + findPos(n->r, val);
        } 
        return findPos(n->l, val);
    }

    ll prefixSum(Node* n, int pos) {
        if (!n || pos <= 0) return 0;
        // cout << n->val << " " << size(n) << " " << sumOf(n) << " " << pos << endl;
        if (size(n->l) >= pos) {
            return prefixSum(n->l, pos);
        }
        return sumOf(n) - sumOf(n->r) + prefixSum(n->r, pos - size(n->l) - 1);
    }   
}


int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    Treap::Node *root = new Treap::Node(0);

    int q;
    cin >> q;

    ll res = 0;
    FOR (z, 1, q) {
        ll key, val;
        cin >> key >> val;
        key ^= res;
        val ^= res;
        Treap::Node* cur = new Treap::Node(key);
        cur->id = cur->sum = val;
            
        int pos = Treap::findPos(root, key);
        root = Treap::insert(root, cur, pos);
        
        // print(root);
        // cout << endl;
        // cout << pos << endl;        
        res = Treap::prefixSum(root, pos + 1);
        cout << key << " " << res << "\n";
    }


    return 0;
}