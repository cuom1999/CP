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
		int val, sum;
		int l, r;
		Node * leftChild;
		Node * rightChild;

		Node (int val, int sum, int l, int r) {
			this->val = val;
			this->sum = sum;
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
			this->leftChild = new Node(1, l, (l + r) / 2);
		}

		void createRight() {
			if (rightChild != NULL) return;
			this->rightChild = new Node(1, (l + r) / 2 + 1, r);
		}

		void down() {
			if (l == r || val = -1) return;
			leftChild->val = val;
			rightChild->val = val;
			val = -1;
		}

		void update(int u, int v, int k) {
			if (v < l || r < u) {
				return;
			}
			if (u <= l && r <= v) {
				val = k;
				sum = r - l + 1;
				return;
			}

			int mid = (l + r) / 2;
			createRight();
			createLeft();

			down();

			leftChild->update(u, v, k);
			rightChild->update(u, v, k);

			sum = leftChild->sum + rightChild->sum;
		}

		void 
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


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	return 0;
}