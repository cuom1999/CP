void preRMQ() {
	for (int i = 0; (1 << i) <= n ; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			if (i == 0) {
				SPT[j][i]=a[j];
			}
			else{
				SPT[j][i]=min(SPT[j][i-1],SPT[j+(1<<(i-1))][i-1]);
			}
		}
	}
}

inline ll getRMQ(ll u, ll v){
	ll k = flog2(v-u+1);
	return min(SPT[u][k], SPT[v-(1<<k)+1][k]);
}