#include "bits/stdc++.h"

// #include "custom/debugger.h"

using namespace std;

class A {
public:
  int b;

  int getB() { return b; }
};

int loop(vector<int> point, int start) {
  set<int> visited;
  int current = start;
  while (visited.count(current) == 0) {
    visited.insert(current);
    current = point[current];
  }
  return current;
}

int main() {
  int n;
  cin >> n;
  vector<int> point(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &point[i]);
    point[i]--;
  }
  int ans;
  for (int i = 0; i < n; i++) {
    ans = loop(point, i);
    printf("%d ", ans + 1);
  }
  printf("\n");
}
