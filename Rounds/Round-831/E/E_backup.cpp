#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = 0;
vector<int> counted;

int getvalues(int node, vector<vector<int>>& adj, vector<int>& chain,
              vector<int>& subtree, int len) {
    int retval = 1;
    chain[node] = len + 1;
    for (auto u : adj[node]) {
        retval += getvalues(u, adj, chain, subtree, len + 1);
    }
    return subtree[node] = retval;
}

bool getans(int node, vector<vector<int>>& adj, vector<int>& chain,
            vector<int>& subtree) {
    bool retval = true;
    int sum = 0, mx = 0, sum2 = 0, mx2 = 0;
    for (auto u : adj[node]) {
        retval &= getans(u, adj, chain, subtree);
        sum += subtree[u];
        // mx = max(mx, subtree[u]);
        if (mx > subtree[u]) {
            mx = subtree[u];
            // mx2 = counted[u];
        }
        sum2 += counted[u];
        mx2 = max(mx2, counted[u]);
    }
    debug(node, mx2);
    retval &= (chain[node] >= sum - mx);
    if (retval) {
        ans++;
        ans -= (sum2 - mx2);
    }
    return (counted[node] = ans);
}

void solve([[maybe_unused]] int test) {
    ans = 0;
    int n;
    scanf("%lld", &n);
    vector<int> p(n);
    p[0] = -1;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<int> subtree(n, 0);
    vector<int> chain(n, 0);
    counted.assign(n, 0);
    getvalues(0, adj, chain, subtree, 0);
    getans(0, adj, chain, subtree);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
