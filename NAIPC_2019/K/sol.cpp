// Problem         : Tarot Knight (NAIPC 2019)
// Author          : Darcy Best
// Expected Result : AC -- or maybe TLE because of extra log factor
// Complexity      : O(n * G * log(G) * log(MAX)), where G is the number
//                   of distinct GCD's of subsets of a,b and MAX is the
//                   largest a,b.

// The state from one card is either a lattice or checkerboard.
// Combining two cards also gives this property.
// Use Dijkstra to find shortest path to a state that has (0,0) on it
// Note that this is heuristically fast because I stop once I find
// the solution.

// Note: Compile with g++ -O2 -std=c++11 TarotKnight_db2.cc -o db2
// I took the liberty of replacing ints by long longs, so that this
// code works on my machine.  Now it does.
//    --- Danny Sleator <sleator@cs.cmu.edu>

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

typedef pair<ll,bool> pib;

ll gcd(ll a,ll b){
  return b == 0 ? a : gcd(b, a%b);
}

ll factors_of_2(ll x){
  ll ans = 0;
  for(;x % 2 == 0;x/=2) ans++;
  return ans;
}

struct TarotCard {
  ll r,c,a,b,p;
  pib card_grid;
  
  void read(){
    cin >> r >> c >> a >> b >> p;
    card_grid.first  = gcd(a,b);
    card_grid.second = factors_of_2(a) == factors_of_2(b);
  }
  
  bool on_grid(const pib& grid){
    if(grid.first == 0) return r == 0 && c == 0;
    
    if(r % grid.first || c % grid.first) return false;
    if(!grid.second) return true;
    return (r / grid.first) % 2 == (c / grid.first) % 2;
  }
};

pib combine(pib grid1, pib grid2){
  ll g1 = grid1.first * (grid1.second ? 2 : 1);
  ll g2 = grid2.first * (grid2.second ? 2 : 1);
  ll g = gcd(g1,g2);

  ll r1 = grid1.first % g; if(r1 == 0) r1 += g;
  ll r2 = grid2.first % g; if(r2 == 0) r2 += g;
  ll r = min(r1,r2);
  
  return make_pair(r,r != g);
}

int main(){
  ll n; cin >> n;

  vector<TarotCard> A(n);
  for(auto& x : A) x.read();

  TarotCard dest = { abs(A[0].r), abs(A[0].c) };
  
  for(ll i=n-1;i>=0;i--){
    A[i].r = abs(A[i].r - A[0].r);
    A[i].c = abs(A[i].c - A[0].c);
  }

  map<pib,ll> dist;
  priority_queue<pair<ll,pib>,vector<pair<ll,pib> >,greater<pair<ll,pib> > > pq;
  pq.emplace(0, make_pair(0,false));
  dist[make_pair(0,false)] = 0;
  
  while(!pq.empty()){
    pib t = pq.top().second;
    ll d = pq.top().first;
    pq.pop();
    
    if(dist[t] < d) continue;
    if(dest.on_grid(t)) break;
    
    for(ll i=0;i<n;i++)
      if(A[i].on_grid(t)){
    pib now = combine(t, A[i].card_grid);
    if(dist.count(now) == 0 || dist[now] > A[i].p + d){
      dist[now] = A[i].p + d;
      pq.emplace(A[i].p + d, now);
    }
      }
  }

  ll ans = -1;
  for(const auto& x : dist)
    if(dest.on_grid(x.first))
      if(ans == -1 || ans > x.second)
    ans = x.second;
  
  cout << ans << endl;
}
