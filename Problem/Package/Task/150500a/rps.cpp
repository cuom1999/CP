#include <bits/stdc++.h>

using namespace std;

#define TASK "rps"

#define REP(i, a, b) for(i = (a); i < (b); i++)
#define FORU(i, a, b) for(i = (a); i <= (b); i++)
#define FORD(i, a, b) for(i = (a); i >= (b); i--)
#define IT(t, i, v) for(vector<t>::iterator i = (v).begin(); i != (v).end(); i++)

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e3 + 3;

int n, i, j;
int dfn[N];
int Low[N];
int a[N][N];

bool avail[N];

int Stack[N];
int Top = 0;
int cnt = 0;
int res = 0;

char s[N];

void Dfs(int u){
	dfn[u] = ++cnt;
	Low[u] = dfn[u];
	Stack[++Top] = u;
	for(int v = 1; v <= n; v++){
		if(!a[u][v]) continue;
		if(!avail[v]) continue;
		if(dfn[v]) Low[u] = min(Low[u], dfn[v]);
		else{
			// cout << u << " " << v << endl;
			Dfs(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if(Low[u] == dfn[u]){
		int v, len = 0;
		do{
			++len;
			v = Stack[Top--];
			avail[v] = 0;
		} while(v != u);
		// cout << "*" << len << endl;
		// if(len==1) cout <<"*"<<u<<endl;
		if(len > 1) res += len;
	}
}

void fastscan(int &number) 
{ 
    register int c;
    number = 0;  
    for (; (c <'0' || c >'9'); c=getchar());
    for (; (c>='0' && c<='9'); c=getchar()) 
        number = number *10 + c - 48;  
} 

main(){
	#ifndef ONLINE_JUDGE
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
	#endif
	scanf("%d", &n);
	// fastscan(n);
	FORU(i, 1, n){
		scanf("%s", s + 1);
		FORU(j, 1, n) a[i][j] = (s[j]=='1');
		// FORU(j, 1, n) fastscan(a[i][j]);
		// FORU(j, 1, n) a[i][j] = (s[j*2-1]=='1');
		// FORU(j, 1, n) cout << a[i][j] << " ";cout<<endl;
	}
	FORU(i, 1, n) avail[i] = 1;
	FORU(i, 1, n)
		if(!dfn[i])
			Dfs(i);
	printf("%d", res);
}