#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<pair<int, int>> midpoints;
vector<int> path;
void dfs(int node, vector<vector<int>>& adj) {
    int cnt = 0;
    path.push_back(node);
    for (auto u : adj[node]) {
        cnt++;
        dfs(u, adj);
    }
    if (cnt == 0) {
        // leaf found
        int len = (int)path.size();
        midpoints.push_back(make_pair(len / 2, path[len / 2]));  // check this
    }
    path.pop_back();
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<vector<int>> adj(n);
    vector<int> parent(n, -1);
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%lld", &p);
        parent[i] = p - 1;
        adj[p - 1].push_back(i);
    }
    priority_queue<pair<int, int>> pq;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
