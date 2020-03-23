for (int i = 0; i < (1 << n); ++i)
	f[i] = a[i];
for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
    	if (mask & (1 << i)) {
    		f[mask] += f[mask ^ (1 << i)];
        }
    }
}