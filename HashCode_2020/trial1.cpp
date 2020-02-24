#include <bits/stdc++.h>
using namespace std;

#define MAXN 100011

string subtasks[6] = {"a_example.txt", "b_read_on.txt",
                      "c_incunabula.txt", "d_tough_choices.txt",
                      "e_so_many_books.txt", "f_libraries_of_the_world.txt"};

string output(int index) {
    char c = (char) (index + 'a');
    string res = "output_";
    res += c;
    res += ".txt";
    return res;
}

struct Lib {
    int signupTime;
    int booksPerDay;
    vector<int> books;
};

Lib LList[MAXN];
int B, L, D;
int N[MAXN];
long long S[MAXN];
int signup_time[MAXN];
double value[MAXN];
vector <int> BList[MAXN];
vector <int> LI;
vector<vector<int>> res;
vector<vector<int>> resMax;
int max_books_per_day;
int p_signup_time, p_value, p_books_per_day;

///
template<typename flow_t = int, typename cost_t = int>
struct MinCostFlow {
    struct Edge {
        cost_t c;
        flow_t f;
        int to, rev;
        Edge(int _to, cost_t _c, flow_t _f, int _rev) : c(_c), f(_f), to(_to), rev(_rev) {}
    };

    int N;
    vector<vector<Edge> > G;
    // MinCostFlow(int _N, int _S, int _T) : N(_N), S(_S), T(_T), G(_N), eps(0) {}
    MinCostFlow(int _N): N(_N), G(_N), eps(0) {}
    void addEdge(int a, int b, flow_t cap, cost_t cost) {
        assert(cap >= 0);
        assert(a >= 0 && a < N && b >= 0 && b < N);
        if (a == b) { assert(cost >= 0); return; }
        cost *= N;
        eps = max(eps, abs(cost));
        G[a].emplace_back(b, cost, cap, G[b].size());
        G[b].emplace_back(a, -cost, 0, G[a].size() - 1);
    }

    flow_t getFlow(Edge const &e) {
        return G[e.to][e.rev].f;
    }

    pair<flow_t, cost_t> minCostMaxFlow(int S, int T) {
        cost_t retCost = 0;
        for (int i = 0; i<N; ++i) {
            for (Edge &e : G[i]) {
                retCost += e.c*(e.f);
            }
        }
        //find max-flow
        flow_t retFlow = max_flow(S, T);
        h.assign(N, 0); ex.assign(N, 0);
        isq.assign(N, 0); cur.assign(N, 0);
        queue<int> q;
        for (; eps; eps >>= scale) {
            //refine
            fill(cur.begin(), cur.end(), 0);
            for (int i = 0; i < N; ++i) {
                for (auto &e : G[i]) {
                    if (h[i] + e.c - h[e.to] < 0 && e.f) push(e, e.f);
                }
            }
            for (int i = 0; i < N; ++i) {
                if (ex[i] > 0){
                    q.push(i);
                    isq[i] = 1;
                }
            }
            // make flow feasible
            while (!q.empty()) {
                int u = q.front(); q.pop();
                isq[u]=0;
                while (ex[u] > 0) {
                    if (cur[u] == G[u].size()) {
                        relabel(u);
                    }
                    for (unsigned int &i=cur[u], max_i = G[u].size(); i < max_i; ++i) {
                        Edge &e = G[u][i];
                        if (h[u] + e.c - h[e.to] < 0) {
                            push(e, ex[u]);
                            if (ex[e.to] > 0 && isq[e.to] == 0) {
                                q.push(e.to);
                                isq[e.to] = 1;
                            }
                            if (ex[u] == 0) break;
                        }
                    }
                }
            }
            if (eps > 1 && eps>>scale == 0) {
                eps = 1<<scale;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (Edge &e : G[i]) {
                retCost -= e.c*(e.f);
            }
        }
        return make_pair(retFlow, retCost / 2 / N);
    }

private:
    static constexpr cost_t INFCOST = numeric_limits<cost_t>::max()/2;
    static constexpr int scale = 2;

    cost_t eps;
    vector<unsigned int> isq, cur;
    vector<flow_t> ex;
    vector<cost_t> h;
    vector<vector<int> > hs;
    vector<int> co;

    void add_flow(Edge& e, flow_t f) {
        Edge &back = G[e.to][e.rev];
        if (!ex[e.to] && f) {
            hs[h[e.to]].push_back(e.to);
        }
        e.f -= f; ex[e.to] += f;
        back.f += f; ex[back.to] -= f;
    }

    void push(Edge &e, flow_t amt) {
        if (e.f < amt) amt = e.f;
        e.f -= amt; ex[e.to] += amt;
        G[e.to][e.rev].f += amt; ex[G[e.to][e.rev].to] -= amt;
    }

    void relabel(int vertex){
        cost_t newHeight = -INFCOST;
        for (unsigned int i = 0; i < G[vertex].size(); ++i){
            Edge const&e = G[vertex][i];
            if(e.f && newHeight < h[e.to] - e.c){
                newHeight = h[e.to] - e.c;
                cur[vertex] = i;
            }
        }
        h[vertex] = newHeight - eps;
    }

    flow_t max_flow(int S, int T) {
        ex.assign(N, 0);
        h.assign(N, 0); hs.resize(2*N);
        co.assign(2*N, 0); cur.assign(N, 0);
        h[S] = N;
        ex[T] = 1;
        co[0] = N-1;
        for (auto &e : G[S]) {
            add_flow(e, e.f);
        }
        if (hs[0].size()) {
            for (int hi = 0; hi>=0;) {
                int u = hs[hi].back();
                hs[hi].pop_back();
                while (ex[u] > 0) { // discharge u
                    if (cur[u] == G[u].size()) {
                        h[u] = 1e9;
                        for(unsigned int i = 0; i < G[u].size(); ++i) {
                            auto &e = G[u][i];
                            if (e.f && h[u] > h[e.to]+1) {
                                h[u] = h[e.to]+1, cur[u] = i;
                            }
                        }
                        if (++co[h[u]], !--co[hi] && hi < N) {
                            for (int i = 0; i < N; ++i) {
                                if (hi < h[i] && h[i] < N) {
                                    --co[h[i]];
                                    h[i] = N + 1;
                                }
                            }
                        }
                        hi = h[u];
                    } else if (G[u][cur[u]].f && h[u] == h[G[u][cur[u]].to]+1) {
                        add_flow(G[u][cur[u]], min(ex[u], G[u][cur[u]].f));
                    } else {
                        ++cur[u];
                    }
                }
                while (hi>=0 && hs[hi].empty()) {
                    --hi;
                }
            }
        }
        return -ex[S];
    }
};
///

int calcScore(const vector<int> &libOrder, vector<vector<int>>& res);
int calcScore2(vector<int> &libOrder, vector<vector<int>>& res);

bool compareLib(int x, int y) {
  double score_x = (LList[x].signupTime * -1.0 / D) * p_signup_time + (value[x]) * p_value + (LList[x].booksPerDay * 1.0 / max_books_per_day) * p_books_per_day;
  double score_y = (LList[y].signupTime * -1.0 / D) * p_signup_time + (value[y]) * p_value + (LList[y].booksPerDay * 1.0 / max_books_per_day) * p_books_per_day;
  return score_x > score_y;
}

long long solve() {
  long long result = 0;

  // double pList[][3] = {
  //   {1.5, 0.5, 0},
  //   {1, 0, 1},
  //   {0, 0, 1},
  //   {0.4, 0.1, 0.3}
  // };

  // for(int i = 0; i < 4; ++i) {
  //   p_signup_time = ;//pList[i][0];
  //   p_value = pList[i][1];
  //   p_books_per_day = pList[i][2];
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      for(int k = 0; k < 3; ++k){
        p_signup_time = 2 * i;
        p_value = 2 * j;
        p_books_per_day = 2 * k;
        sort(LI.begin(), LI.end(), compareLib);
        long long tmp = calcScore2(LI, res);
        if(tmp > result) {
          result = tmp;
          resMax = res;
        }
        cout << tmp << endl;
        // cout << tmp << "\n";
      }
    }
  }
    
  
  return result;
}

void init() {
  long long total_value = 0;
  for(int i = 0; i < B; ++i) {
    total_value += S[i];
  }
  // cout << total_value << "\n";
  long long tmp = 0;
  for(int i = 0; i < L; ++i) {
    tmp = 0;
    for(int j = 0; j < N[i]; ++j) {
      tmp += S[LList[i].books[j]];
    }
    value[i] = tmp * 1.0 / total_value;
    // cout << value[i] << "\n";
  }
  for(int i = 0; i < L; ++i) {
    LI.push_back(i);
  }
}

void readInput() {
  int sub = 5;
  freopen(subtasks[sub].c_str(), "r", stdin);
  freopen(output(sub).c_str(), "w", stdout);
  ios::sync_with_stdio(0);

  cin >> B >> L >> D;

  for(int i = 0; i < B; ++i) {
    cin >> S[i];
  }

  for(int i = 0; i < L; ++i) {
    cin >> N[i] >> LList[i].signupTime >> LList[i].booksPerDay;
    max_books_per_day = max(max_books_per_day, LList[i].booksPerDay);
    for(int j = 0; j < N[i]; ++j) {
      int tmp;
      cin >> tmp;
      LList[i].books.push_back(tmp);
    }
  }

}

int main() {
  readInput();
  init();
  cout << solve();
}

int calcScore(const vector<int> &libOrder, vector<vector<int>>& res) {
    vector<bool> scanned(B), signedUp(L);
    res.clear();

    int curDay = 0;
    int totalScore = 0;

    for (auto index: libOrder) {
        vector<int> toScan;
        int remainTime = D - curDay;

        if (signedUp[index] || LList[index].signupTime >= remainTime) continue;
        int booksCanScan = (remainTime - LList[index].signupTime) 
                            * LList[index].booksPerDay;

        for (auto j: LList[index].books) {
            if (!scanned[j]) {
                toScan.push_back(j);
            }
        }

        sort(toScan.begin(), toScan.end(),[&](int a, int b) {
            return S[a] > S[b];
        });

        while (toScan.size() > booksCanScan) {
            toScan.pop_back();
        }

        for (auto i: toScan) {
            totalScore += S[i];
        }

        curDay += LList[index].signupTime;
        signedUp[index] = 1;
        res.push_back(toScan);

        for (auto j: toScan) {
            scanned[j] = 1;
        }
    }
    return totalScore;
}

int calcScore2(vector<int> &libOrder, vector<vector<int>>& res) {
    vector<bool> scanned(B), signedUp(L);
    res.clear();

    int curDay = 0;
    int totalScore = 0;

    auto verLib = [&](int a) {return a;};
    auto verBook = [&](int a) {return L + a;};
    int source = L + B;
    int sink = source + 1;

    MinCostFlow<int, int> mcmf(sink + 1);

    for (auto index: libOrder) {
        vector<int> toScan;
        int remainTime = D - curDay;

        if (signedUp[index] || LList[index].signupTime >= remainTime) continue;
        int booksCanScan = (remainTime - LList[index].signupTime) 
                            * LList[index].booksPerDay;

        mcmf.addEdge(source, verLib(index), booksCanScan, 0);
        
        // may need to use some heuristics here
        for (auto i: LList[index].books) {
            mcmf.addEdge(verLib(index), verBook(i), 1, -S[i]);
        }        
    }
    for (int i = 0; i < B; i++) {
        mcmf.addEdge(verBook(i), sink, 1, 0);
    }

    totalScore = mcmf.minCostMaxFlow(source, sink).second;

    vector<int> resBooks[100005];

    for (int i = 0; i < L; i++) {
        for (auto e: mcmf.G[verLib(i)]) {
            if (mcmf.getFlow(e) && e.c < 0) {
                resBooks[i].push_back(e.to - L);
            }
        }
    }

    for (auto i: libOrder) {
        res.push_back(resBooks[i]);
    }
    return -totalScore;
}