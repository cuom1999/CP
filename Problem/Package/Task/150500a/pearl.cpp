#include <bits/stdc++.h>

using namespace std;

#define TASK "pearl"

#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define FORU(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define IT(t, i, v) for(vector<t>::iterator i = (v).begin(); i != (v).end(); i++)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAXD = 19; // 10^18
const int MAXS = 9*9*18; //999999999999999999

int digit[MAXD+3];

long long dp[MAXD+3][MAXS+3][2];

void parse(long long n){
	FORU(i, 1, MAXD) digit[i] = n % 10, n /= 10;
}

int sumDigit(int n){
	int ret = 0;
	while(n) ret += (n % 10)*(n % 10), n/=10;
	return ret;
}

long long count(int idx, int sum, bool tight){
	if(!idx)
		return !sum;
	if(dp[idx][sum][tight] != -1)
		return dp[idx][sum][tight];
	long long ret = 0;
	int upper = tight ? digit[idx] : 9;
	FORU(i, 0, upper){
		bool newTight = tight && (i == digit[idx]);
		if(sum < i*i) break;
		ret += count(idx - 1, sum - i*i, newTight);
	}
	return (dp[idx][sum][tight] = ret);
}

bool isDiverge[MAXS+3];
bool Have[MAXS+3];
int Stack[MAXS+3];

void checkDiverge(int n, bool& r){
	int Top = 0;
	// cout << n;
	while(1){
		if(n == 1){
			r = 0;
			break;
		}
		if(Have[n]){
			r = 1;
			break;
		}
		Have[n] = 1, Stack[++Top] = n;
		n = sumDigit(n);
	}
	// cout << " " << r << endl;
	FORU(i, 1, Top) Have[Stack[i]] = 0;
}

long long get(long long n){
	if(n == 0) return 0;
	parse(n);
	memset(dp, -1, sizeof(dp));
	long long cnt = 0;
	FORU(i, 1, MAXS)
		if(isDiverge[i])
			cnt += count(MAXD, i, 1);
	return cnt;
}

main(){
	#ifndef ONLINE_JUDGE
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
	#endif
	// int xxx = 2941999;
	// for(int loop = 1; loop <= 100; loop++){
	// 	cout << xxx << endl;
	// 	xxx = sumDigit(xxx);
	// }
	// return 0;
	FORU(i, 1, MAXS) checkDiverge(i, isDiverge[i]);
	int TC;
	cin >> TC;
	while(TC--){
		long long L, R;
		cin >> L >> R;
		cout << get(R) - get(L - 1) << endl;
	}
}