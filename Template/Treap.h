namespace Treap {
    struct Node {
        Node *l = 0, *r = 0;
        int val, y, c = 1;
        Node(int val) : val(val), y(rand() * rand()) {}
        void recalc();
    };

    int size(Node* n) { return n ? n->c : 0; }
    void Node::recalc() { c = size(l) + size(r) + 1; }

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

}
