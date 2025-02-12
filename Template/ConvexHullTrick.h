// return the minimum value
// add line in increasing order of a

// Min-decreasing order: add(-a, b)  ___  min = query(-x)
// Max-decreasing order: add(-a, -b) ___  max = -query(x)
// Max-increasing order: add(a, -b)  ___  max = -query(-x)

struct Point {
    long long x, y;
};

struct CHT {
    vector<Point> pts;

    double cross (Point a, Point b) {return (double)(b.y - a.y) / (b.x - a.x);}

    void addLine(long long x, long long y) {
        if (pts.size() && pts.back().x == x && pts.back().y == y) return;

        while(pts.size() >= 2 && cross(pts[pts.size()-2], pts.back()) > cross(pts.back(), (Point){x, y})){
            pts.pop_back();   
        }
        pts.push_back({x, y});
    }

    long long query(long long x) {
        int s = 0, e = (int) pts.size()-1;
        auto f = [&](int p) {
            return pts[p].x * x + pts[p].y;
        };

        while(s != e){
            int m = (s + e) / 2;
            if(f(m) <= f(m + 1)) e = m;
            else s = m + 1;
        }
        return pts[s].x * x + pts[s].y;
    }
};


// int cur = 0;

// long long query(long double x) {
//     auto f = [&](int p) {
//         return pts[p].x * x + pts[p].y;
//     };

//     if (cur >= pts.size()) cur = pts.size() - 1;

//     while (cur + 1 < pts.size()){
//         if (f(cur) > f(cur + 1)) cur++;
//         else break;
//     }
//     return pts[cur].x * x + pts[cur].y;
// }
