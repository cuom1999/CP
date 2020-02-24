// n: number of vertices
const int MAXN = 300005;

vector<II> ver;

vector<int> v[MAXN];
bool visited[MAXN], marked[MAXN];


int numTriangles() {
	FOR (i, 1, n) {
		ver.pb({v[i].size(), i});
	}

	sort(all(ver));

	reverse(all(ver));

    ll cnt = 0;
    for (auto p: ver) {
        int i = p.second;

        for (auto j: v[i]) {
            if (visited[j]) continue;
            marked[j] = 1;
        }
        
        for (auto j: v[i]) {
        	if (!marked[j]) continue;

            for (auto u: v[j]) {
                if (marked[u]) cnt++; // (i, j, u)
            }
            marked[j] = 0;
        }       
        visited[i] = 1;
    }

	return cnt;
}