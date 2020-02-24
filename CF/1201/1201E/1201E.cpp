#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n, m;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, -2, 2, 1, -1, 1, -1};

struct Game {

	struct State {
		int whiteX, whiteY, blackX, blackY;
		bool whiteNext;
		void print() {
			cout << whiteX << " " << whiteY << " " << blackX << " " << blackY << " " << whiteNext << endl;
		}
		bool isDone() {
			if (minmax(abs(whiteX - blackX), abs(whiteY - blackY)) == minmax(1, 2)) {

			}
			else if (whiteX == n / 2 && whiteY == m / 2) {
				return 1;
			}
			else if (blackX == n / 2 + 1 && blackY == m / 2) {
				return 1;
			}
			else if (whiteX == blackX && whiteY == blackY) {
				return 1;
			}
			return 0;
		}
	};

	State curState;

	struct AI {
		bool playFirst;
		int startWhiteX, startWhiteY;
		int startBlackX, startBlackY;

		vector<State> adj[45][45][45][45][2], adj_rev[45][45][45][45][2];
		bool win[45][45][45][45][2];
		bool lose[45][45][45][45][2];
		bool vs[45][45][45][45][2];
		int deg[45][45][45][45][2];

		AI(int x1, int y1, int x2, int y2, bool playFirst) {
			startWhiteX = x1;
			startWhiteY = y1;
			startBlackX = x2;
			startBlackY = y2;
			this->playFirst = playFirst;
			memset(win, 0, sizeof(win));
			memset(lose, 0, sizeof(lose));
			memset(vs, 0, sizeof(vs));
			memset(deg, 0, sizeof(deg));
		}

		void addEdge(State u, State v) {
			adj[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext].pb(v);
			deg[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext]++;
			adj_rev[v.whiteX][v.whiteY][v.blackX][v.blackY][v.whiteNext].pb(u);
		}

		bool check(int x1, int y1, int x2, int y2) {
			return (1 <= x1 && x1 <= n && 1 <= x2 && x2 <= n && 1 <= y1 && y1 <= m && 1 <= y2 && y2 <= m);
		}

		bool check(State u) {
			return check(u.whiteX, u.whiteY, u.blackX, u.blackY);
		}

		void initStates() {
			// cout << n << " " << m << endl;
			FOR (x1, 1, n) {
				FOR (y1, 1, m) {
					FOR (x2, 1, n) {
						FOR (y2, 1, m) {
							FOR (u, 0, 1) {
								// cout << x2 << " " << y2 << endl;
									
								bool &winState = win[x1][y1][x2][y2][u];
								bool &loseState = lose[x1][y1][x2][y2][u];
								if (minmax(abs(x1 - x2), abs(y1 - y2)) == minmax(1, 2)) {
									
								}
								else if (x1 == n / 2 && y1 == m / 2) {
									if (u) {
										winState = 1;
									}
									else {
										loseState = 1;
									}
								}
								else if (x2 == n / 2 + 1 && y2 == m / 2) {
									if (u) {
										loseState = 1;
									}
									else {
										winState = 1;
									}
								}
								else if (x1 == x2 && y1 == y2) {
									loseState = 1;
								}
							}
						}
					}
				}
			}
		}

		void addAllEdges() {
			FOR (x1, 1, n) {
				FOR (y1, 1, m) {
					FOR (x2, 1, n) {
						FOR (y2, 1, m) {
							FOR (u, 0, 1) {
								State s = {x1, y1, x2, y2, u};

								if (u) { // white next
									FOR (i, 0, 7) {
										State s1 = {x1 + dx[i], y1 + dy[i], x2, y2, u ^ 1};
										if (check(s1)) {
											addEdge(s, s1);
										}
									}
								}
								else {
									FOR (i, 0, 7) {
										State s1 = {x1, y1, x2 + dx[i], y2 + dy[i], u ^ 1};
										if (check(s1)) {
											addEdge(s, s1);
										}
									}
								}
							}
						}
					}
				}
			}
		}

		bool isWin(State u) {
			return win[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext];
		}
		
		bool isLose(State u) {
			return lose[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext];
		}	

		bool isVisited(State u) {
			return vs[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext];
		}

		void dfs(State u) {
			vs[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext] = 1;
			
			for (auto v: adj_rev[u.whiteX][u.whiteY][u.blackX][u.blackY][u.whiteNext]) {
				if (!isVisited(v)) {
					if (isLose(u)) {
						win[v.whiteX][v.whiteY][v.blackX][v.blackY][v.whiteNext] = 1;
					}
					else if (--deg[v.whiteX][v.whiteY][v.blackX][v.blackY][v.whiteNext] == 0) {
						lose[v.whiteX][v.whiteY][v.blackX][v.blackY][v.whiteNext] = 1;
					}
					else continue;
					dfs(v);
				}		
			}
		}

		bool solveAllStates() {
			addAllEdges();
			initStates();

			FOR (x1, 1, n) {
				FOR (y1, 1, m) {
					FOR (x2, 1, n) {
						FOR (y2, 1, m) {
							FOR (u, 0, 1) {
								State s = {x1, y1, x2, y2, u};
								if (isWin(s) || isLose(s)) {
									dfs(s);
								}
							}
						}
					}
				}
			}
			State res = {startWhiteX, startWhiteY, startBlackX, startBlackY, playFirst};
			return isWin(res);
		}

		void makeMove(State s) {
			// s.print();
			if (playFirst) {
				cout << s.whiteX << " " << s.whiteY << endl;
			}
			else {
				cout << s.blackX << " " << s.blackY << endl;
			}
		}

		State play(State cur) {
			auto &v = adj[cur.whiteX][cur.whiteY][cur.blackX][cur.blackY][cur.whiteNext];
			for (auto s: v) {
				if (isLose(s)) {
					makeMove(s);
					return s;
				}
			}
			int r = rand() % v.size();
			makeMove(v[r]);
			return v[r];
		}
	};



	bool playWithPeople(int x1, int y1, int x2, int y2, bool u) {
		AI Cuom(x1, y1, x2, y2, u);
		curState = {x1, y1, x2, y2, 1};

		auto res = Cuom.solveAllStates();
		
		// State tmp = {6, 3, 2, 2, 0};
		// cout << Cuom.isWin(tmp) << endl;
		// return 0;

		if (u == 1 && res == 0) return 0; 
		// cout << res << endl;

		if (u == 1) {
			cout << "WHITE" << endl;
		}
		else {
			cout << "BLACK" << endl;
		}

		bool nextPlayer = 1;

		while(!curState.isDone()) {
			// curState.print();
			// cout << Cuom.isWin(curState) << " " << Cuom.isLose(curState) << endl;
			if (nextPlayer == Cuom.playFirst) curState = Cuom.play(curState);
			else {
				int x, y;
				cin >> x >> y;
				if (u) {// white first
					curState.blackX = x;
					curState.blackY = y;
					curState.whiteNext ^= 1;
				}
				else {
					curState.whiteX = x;
					curState.whiteY = y;
					curState.whiteNext ^= 1;
				}
			}
			nextPlayer ^= 1;
		}
		// if (nextPlayer) {
		// 	cout << "Cuom wins" << endl;
		// }
		// else {
		// 	cout << "You win" << endl;
		// }
		return 1;
	}

};

int main()
{//IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	cin >> n >> m;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	Game g;
	if (!g.playWithPeople(x1, y1, x2, y2, 1)) {
		g.playWithPeople(x1, y1, x2, y2, 0);
	}


	return 0;
}