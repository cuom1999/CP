// return the minimum value
// add line in increasing order

// Min-decreasing order: add (-x, y)  + query(-a)
// Max-decreasing order: add (-x, -y) + query(a)
// Max-increasing order: add (x, -y)  + query(-a)

struct Point {
	ll x, y;
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
		int s = 0, e = (int) v.size()-1;
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
