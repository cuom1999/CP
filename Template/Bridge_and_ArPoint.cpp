
const int N = 100005;
int n, m;
vector<int> v[N];
int CriticalEdge=0;
bool CriticalNode[N];
int num[N], low[N], Time=0;
// visit 1 first
void visit(int u, int p) {
    int NumChild = 0;
    low[u] = num[u] = ++Time;
    for (auto i: v[u]){
        if (i!=p) {
            if (num[i])
                low[u] = min(low[u], num[i]);
            else {
                visit(i, u);
                NumChild++;
                low[u] = min(low[u], low[i]);

                if (low[i] > num[u])
                    CriticalEdge++; /// Bridge


                if (u==1) {
                    if (NumChild >= 2)
                    CriticalNode[u] = true;
                } else {
                    if (low[i] >= num[u])
                    CriticalNode[u] = true;
                }
            }
        }
    }
}
