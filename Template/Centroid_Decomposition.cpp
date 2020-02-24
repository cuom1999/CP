
const int N=100005;

int subCD[N], cenDad[N], cenRoot;
vector<int> v[N], cenChild[N];
set<int> s[N];

int dfsCD(int a, int p){
	subCD[a]=1;
	for (int i:s[a]){
		if (i!=p){
			dfsCD(i,a);
			subCD[a]+=subCD[i];
		}
	}
	return subCD[a];
}

int centroid(int a, int p, int n){
	for (auto i:s[a]){
		if (i!=p && subCD[i]>n/2){
			return centroid(i,a,n);
		}
	}
	return a;
}

//call centroidDecomposition(1,0)
void centroidDecomposition(int a, int p){
	int n = dfsCD(a,p);
	int cen = centroid(a,p,n);
	cenDad[cen] = p;
	if(p) cenChild[p].pb(cen);
	else cenRoot = cen;

	for (int i:s[cen]){
		s[i].erase(cen);
		centroidDecomposition(i,cen);
	}
}

// in main
FOR (i,1,n){
	for (auto j:v[i]) s[i].insert(j);
}
centroidDecomposition(1,0);