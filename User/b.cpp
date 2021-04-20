#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
  vector<int> p, rank;
  dsu(int _n) {
    p.resize(_n);
    rank.resize(_n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x!=y) {
      if(rank[x] < rank[y]) {
        p[x] = y;
      } else if(rank[y] < rank[x]) {
        p[y] = x;
      } else {
        p[y] = x;
        rank[x]++;
      }
    }
    return;
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu d(n);

  while(q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if(op==0) {
      d.unite(x, y);
    } else {
      cout << d.belong(x, y) << '\n';
    }
  }
  return 0;
}