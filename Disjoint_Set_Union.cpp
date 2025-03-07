#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class DSU {
  vector<int> rank, parent;

public:
  DSU(int n) {
    rank.resize(n + 1, 1);
    parent.resize(n + 1, 0);

    for(int i = 0; i < n + 1; i++) parent[i] = i;
  }


  int findUltParent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = findUltParent(parent[node]);
  }

  void unionByRank(int node1, int node2) {
    int p1 = findUltParent(node1);
    int p2 = findUltParent(node2);

    if(p1 == p2) return;

    if(rank[p1] > rank[p2]) {
      rank[p1] += rank[p2];
      parent[p2] = p1;
    } else {
      rank[p2] += rank[p1];
      parent[p1] = p2;
    }
  }
};

void testCase() {
  DSU dsu(5);

  dsu.unionByRank(1, 2);
  dsu.unionByRank(2, 3);

  dsu.unionByRank(4, 5);

  // is there any edge b/w 3 & 4
  // cout << dsu.findUltParent(3) << " " << dsu.findUltParent(2) << endl;
  if(dsu.findUltParent(3) ==  dsu.findUltParent(4)) cout << "yes";
  else cout << "no";

}

int main() {
 int t = 1;
 // cin >> t;
 while(t--) testCase();
}
