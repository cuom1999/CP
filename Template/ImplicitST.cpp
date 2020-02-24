
struct Seg {
    
    struct Node {
        ll val;
        int l, r;
        Node * leftChild;
        Node * rightChild;

        Node (ll val, int l, int r) {
            this->val = val;
            this->l = l;
            this->r = r;
            leftChild = rightChild = NULL;
        }

        ~Node() {
            if (leftChild != NULL) {
                delete leftChild;
            }
            if (rightChild != NULL) delete rightChild;
        }

        void createLeft() {
            if (leftChild != NULL) return;
            this->leftChild = new Node(INF, l, (l + r) / 2);
        }

        void createRight() {
            if (rightChild != NULL) return;
            this->rightChild = new Node(INF, (l + r) / 2 + 1, r);
        }

        void update(int u, ll k) {
            if (l == r) {
                val = k;
                return;
            }
            int mid = (l + r) / 2;
            if (u <= mid) {
                createLeft();
                leftChild->update(u, k);
                val = min(val, leftChild->val);
            }
            else {
                createRight();
                rightChild->update(u, k);
                val = min(val, rightChild->val);
            }
        }

        ll getMin(int u, int v) {
            if (v < l || r < u) return 1e18;
            if (u <= l && r <= v) return val;
            ll res = 1e18;
            if (leftChild != NULL) res = min(res, leftChild->getMin(u, v));
            if (rightChild != NULL) res = min(res, rightChild->getMin(u, v));
            return res;
        }
    };

    Node * root;

    Seg(int l = 1, int r = 1000000) {
        root = new Node(INF, l, r);
    }

    ~Seg() {
        delete root;
    }

    void update(int u, ll k) {
        root->update(u, k);
    }

    ll getMin(int u, int v) {
        return root->getMin(u, v);
    }
};
