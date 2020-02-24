#include <bits/stdc++.h>

using namespace std;

#define TASK "split"

#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define FORU(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define IT(t, i, v) for(vector<t>::iterator i = (v).begin(); i != (v).end(); i++)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 3e4 + 4;
const int A = 1e4 + 4;
const int K = 111;
const int oo = 1e9;

int n, k;
int cur;
int left_ptr = 1, right_ptr = 0;
int a[N];
int cnt[A];

int res = 0;
int dp[K][N];

inline int Cost(int L, int R){
	while(left_ptr > L) res += cnt[a[--left_ptr]]++;
	while(right_ptr < R) res += cnt[a[++right_ptr]]++;

	while(left_ptr < L) res -= --cnt[a[left_ptr++]];
	while(right_ptr > R) res -= --cnt[a[right_ptr--]];

	return res;
} 

void Solve(int L, int R, int L_pos, int R_pos){
	if(L > R) return;
	int mid = (L + R) / 2;
	int y = min(mid, R_pos);
	int cand;
	int best;
	dp[cur][mid] = oo;
	FORU(i, L_pos, y){
		int v = Cost(i, mid);
		if(dp[cur][mid] > (cand = dp[cur-1][i-1] + Cost(i, mid))){
			dp[cur][mid] = cand;
			best = i;
		}
	}
	Solve(L, mid-1, L_pos, best);
	Solve(mid+1, R, best, R_pos);
}

main(){
	#ifndef ONLINE_JUDGE
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
	#endif
	scanf("%d%d", &n, &k);
	FORU(i, 1, n){
		scanf("%d", &a[i]);
		dp[1][i] = Cost(1, i);
	}
	for(cur = 2; cur <= k; cur++) Solve(cur, n, cur, n);
	printf("%d", dp[k][n]);
}