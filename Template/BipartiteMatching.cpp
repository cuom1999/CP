// everything is 1-index
// v[i]: adj set of right vertex i
// match[i]: adj of left vertex i

int match[MAXN], vs[MAXN];
vector<int> v[MAXN];

// find an augmenting path
bool findPath(int u, int t) { // u: a right vertex, t: time
	if (vs[u] != t){
		vs[u] = t;
	}
	else return 0;

	for (auto i: v[u]){
		if (!match[i] || findPath(match[i], t)) {
			match[i] = u;
			return 1;
		}
	}
	return 0;
}

int biMatching (int m, int n) {
	FOR (i, 1, max(m,n)) match[i] = vs[i] = 0;

	int cnt=0;

	FOR (i, 1, m) {
		cnt += findPath(i,i);
	}

	return cnt;
}
