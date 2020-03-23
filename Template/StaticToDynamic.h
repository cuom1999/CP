// use CHT as the example
// rebuild after insert all necessary set before answer queries
// note the pointers

const int LG = 20;

struct Point {
	ll x, y;
	bool operator < (Point &a) {
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
};

struct CHT {
	vector<Point> v;

	ld cross (Point a, Point b) {return (ld)(b.y - a.y) / (b.x - a.x);}

	void addLine(ll x, ll y) {
		if (v.size() && v.back().x == x && v.back().y == y) return;

		while(v.size() >= 2 && cross(v[v.size()-2], v.back()) > cross(v.back(), (Point){x, y})){
			v.pop_back();	
		}
		v.push_back({x, y});
	}

	ll query(ll x) {
		int s = 0, e = v.size()-1;
		auto f = [&](int p) {
			return v[p].x * x + v[p].y;
		};

		while(s != e){
			int m = (s + e) / 2;
			if(f(m) <= f(m+1)) e = m;
			else s = m + 1;
		}
		return v[s].x * x + v[s].y;
	}
};

CHT merge(CHT &a, CHT &b) {
	CHT res;
	vector<Point> tmp;
	merge(all(a.v), all(b.v), back_inserter(tmp));

	for (auto i: tmp) {
		res.addLine(i.x, i.y);
	}
	return res;
}

struct Container {
	vector<CHT*> group[LG + 1];

	void insert(Container &c) {
		FOR (i, 0, LG) {
			for (auto j: c.group[i]) {
				group[i].pb(j);
			}
		}
	}

	void rebuild() {
		FOR (i, 0, LG) {
			for (int j = 0; j + 1 < group[i].size(); j += 2) {
				CHT *tmp = new CHT();
				*tmp = merge(*group[i][j], *group[i][j + 1]);
				group[i + 1].pb(tmp);
			}
			if (group[i].size() % 2) {
				auto tmp = group[i].back();
				group[i].clear();
				group[i].pb(tmp);
			}
			else {
				group[i].clear();
			}
		}
	}

	void print() {
		FOR (i, 0, LG) {
			if (group[i].size()) {
				cout << i << endl;
				for (auto j: group[i][0]->v) {
					cout << j.x << " " << j.y << endl;
				}
			}
		}
		cout << endl;
	}
};
