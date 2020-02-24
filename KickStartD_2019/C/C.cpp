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


struct Seg {
    
    struct Node {
        ll sum;
        int cnt;
        unsigned int l, r;
        Node * leftChild;
        Node * rightChild;

        Node (ll sum, int cnt, unsigned int l, unsigned int r) {
            this->sum = sum;
            this->cnt = cnt;
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
            this->leftChild = new Node(0, 0, l, ((ll)l + r) / 2);
        }

        void createRight() {
            if (rightChild != NULL) return;
            this->rightChild = new Node(0, 0, ((ll)l + r) / 2 + 1, r);
        }

        void update(unsigned int u, int k) {
        	// cout << l << " " << r << " " << u << endl;
            if (l == r) { 
                sum += k * 1ll * ((ll)l - INF);
                cnt += k;
                return;
            }
            unsigned int mid = ((ll)l + r) / 2;
            if (u <= mid) {
                createLeft();
                leftChild->update(u, k);
            }
            else {
                createRight();
                rightChild->update(u, k);
            }
            ll sum1 = 0, sum2 = 0;
            int cnt1 = 0, cnt2 = 0;

            if (leftChild != NULL) {
            	sum1 = leftChild->sum;
            	cnt1 = leftChild->cnt;
            }
            if (rightChild != NULL) {
            	sum2 = rightChild->sum;
            	cnt2 = rightChild->cnt;
            }

            sum = sum1 + sum2;
            cnt = cnt1 + cnt2;
            // cout << l << " " << r << " " << cnt << " " << sum << endl;
        }

        int getCnt(unsigned int u, unsigned int v) {
        	if (v < l || r < u) return 0;
        	// cout << l << " " << r << " " << cnt << endl;
        		
        	if (u <= l && r <= v) {
        		return cnt;
        	}

        	int res = 0;
        	if (leftChild != NULL) {
        		res += leftChild->getCnt(u, v);
        	}
        	if (rightChild != NULL) {
        		res += rightChild->getCnt(u, v);
        	}
        	return res;
        } 

        ll getSum(unsigned int u, unsigned int v) {
        	if (v < l || r < u) return 0;

        	if (u <= l && r <= v) {
        		// cout << l << " " << r << " " << u << " " << v << " " << sum << endl;        	
	        	return sum;
        	}

        	ll res = 0;
        	if (leftChild != NULL) {
        		res += leftChild->getSum(u, v);
        	}
        	if (rightChild != NULL) {
        		res += rightChild->getSum(u, v);
        	}
        	return res;
        } 

        // ll getSum(int k) {
        // 	if (l == r) {
        // 		// cout << l << " " << r << " " << k * 1ll * l << endl;
        // 		return k * 1ll * l;
        // 	}

        // 	if (leftChild != NULL) {
        // 		int cnt1 = leftChild->cnt;
        // 		if (cnt1 >= k) {
        // 			return leftChild->getSum(k);
        // 		}
        // 		else {
        // 			return leftChild->sum + rightChild->getSum(k - cnt1);
        // 		}
        // 	}
        // 	else {
        // 		return rightChild->getSum(k);
        // 	}
        // }
    };

    Node * root;

    Seg(unsigned int l = 1, unsigned int r = 1000000) {
        root = new Node(0, 0, l, r);
    }

    ~Seg() {
        delete root;
    }

    void update(int u, int k) {
    	ll u1 = (ll)u + INF;
        root->update(u1, k);
    }

    ll getSum(int l, int r) {
    	ll l1 = (ll)l + INF;
    	ll r1 = (ll)r + INF;
        return root->getSum(l1, r1);
    }
    int getCnt(int l, int r) {
    	ll l1 = (ll)l + INF;
    	ll r1 = (ll)r + INF;
    	return root->getCnt(l1, r1);
    }
};

struct Data {
	ll x, c;
}data[100005];

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": "; 
		int n, k;
		cin >> k >> n;

		FOR (i, 1, n) {
			cin >> data[i].x;
		}
		FOR (i, 1, n) {
			cin >> data[i].c;
		}

		sort(data + 1, data + n + 1, [] (Data &a, Data &b) {
			return a.x < b.x;
		});


		Seg * seg1 = new Seg(INF, (unsigned int) 3 * INF);
		Seg * seg2 = new Seg(1, (unsigned int) 2 * INF);
		

		FOR (i, 1, n) {
			seg1->update(data[i].c + data[i].x, 1);
		}		

		ll res = 1e18;
		FOR (i, 1, n) {
			seg1->update(data[i].c + data[i].x, -1);

			ll L = 1, R = 2 * INF;

			while (L < R) {
				ll mid = (L + R) / 2;
				int cnt = seg1->getCnt(1, mid + data[i].x) + seg2->getCnt(-INF + 1, mid - data[i].x);
				if (cnt >= k) {
					R = mid;
				}
				else {
					L = mid + 1;
				}
			}

			int cnt1 = seg1->getCnt(1, L + data[i].x);
			int cnt2 = seg2->getCnt(-INF + 1, L - data[i].x);
			int cnt = cnt1 + cnt2;

			ll cost = seg1->getSum(1, L + data[i].x) + seg2->getSum(-INF + 1, L - data[i].x);
			cost += cnt1 * 1ll * -data[i].x + cnt2 * 1ll * data[i].x;

			// cout << L - data[i].x << endl;
			// cout << seg1->getSum(1, L + data[i].x) << " " << seg2->getSum(-INF + 1, L - data[i].x) << endl;
			// cout << cost << endl;
			
			cost -= (cnt - k) * 1ll * L;
			cost += data[i].c;
			res = min(res, cost);
			// cout << i << " " << L << " " << cnt << " " << cost << endl;

			seg2->update(data[i].c - data[i].x, 1);
		}

		cout << res << endl;
	}
	return 0;
}