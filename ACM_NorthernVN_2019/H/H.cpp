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
typedef pair < ll, ll > II;


struct Seg {
    
    struct Node {
        ll sum, cnt;
        int l, r;
        Node * leftChild;
        Node * rightChild;

        Node (ll sum, ll cnt, int l, int r) {
            this->sum = 0;
            this->cnt = 0;
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
            this->leftChild = new Node(0, 0, l, (l + r) / 2);
        }

        void createRight() {
            if (rightChild != NULL) return;
            this->rightChild = new Node(0, 0, (l + r) / 2 + 1, r);
        }

        void update(int u) {
            if (l == r) {
                sum += u;
                cnt++;
                return;
            }
            int mid = (l + r) / 2;
            if (u <= mid) {
                createLeft();
                sum -= leftChild->sum;
                cnt -= leftChild->cnt;
                leftChild->update(u);
                sum += leftChild->sum;
                cnt += leftChild->cnt;
            }
            else {
                createRight();
                sum -= rightChild->sum;
                cnt -= rightChild->cnt;
                rightChild->update(u);
                sum += rightChild->sum;
                cnt += rightChild->cnt;
            }
        }

        II getAns(int u, int v) {
            if (v < l || r < u) return {0, 0};
            if (u <= l && r <= v) return {sum, cnt};
            II res = {0, 0};

            if (leftChild != NULL) {
                II uu = leftChild->getAns(u, v);
                res.first += uu.first;
                res.second += uu.second;
            }
            if (rightChild != NULL) {
                II uu = rightChild->getAns(u, v);
                res.first += uu.first;
                res.second += uu.second;
            }
            return res;
        }
    };

    Node * root;

    Seg(int l = 1, int r = INF) {
        root = new Node(0, 0, l, r);
    }

    ~Seg() {
        delete root;
    }

    void update(int u) {
        root->update(u);
    }

    II getAns(int u, int v) {
        return root->getAns(u, v);
    }
};

ll ans[100005], s[100005];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        Seg seg;
        int n, k, r;
        cin >> n >> k >> r;
        FOR (i, 1, n) {
            cin >> s[i];
        }
        ll sum = 0;
        FOR (i, 1, n) {
            seg.update(s[i]);
            sum += s[i];
            if (i < k) {
                ans[i] = 0;
                continue;
            }
            ll lower = 1, upper = 1e15;

            while (lower < upper) {
                ll mid = (lower + upper + 1) / 2;
                II u;
                if (mid <= INF) {
                    u = seg.getAns(1, mid);
                }
                else {
                    u = {sum, i};
                }
                ll val = u.first + (i - u.second) * mid;
                if (val >= mid * k) {
                    lower = mid;
                }   
                else {
                    upper = mid - 1;
                }
            }
            ans[i] = lower;
        }
        FOR (i, r + 1, n) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}