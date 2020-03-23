// lcp[i] = lcp(sa[i - 1], sa[i]); i = 1 -> n
// sa[0] = n
// lcp[0] = lcp[1] = 0
// lcp(sa[i], sa[j]) = min(lcp[i + 1], ..., lcp[j])

struct SuffixArray {
    vector<int> sa, lcp;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            FOR (i, 0, n - 1) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            FOR (i, 0, n - 1) ws[x[i]]++;
            FOR (i, 1, lim - 1) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            FOR (i, 1, n - 1) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        FOR (i, 1, n - 1) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};
