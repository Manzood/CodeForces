#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> is_leaf;
vector <bool> is_bud;
vector <bool> visited;
vector <int> leaves;
vector <int> buds;

void dfs (int node, vector <vector <int>>& adj) {
    if (visited[node]) return;
    visited[node] = true;
    if ((int) adj[node].size() == 1) {
        is_leaf[node] = true;
        leaves.push_back (node);
    }
    bool bud = true;
    for (auto u: adj[node]) {
        dfs (u, adj);
        if (!is_leaf[u]) {
            bud = false;
        }
    }
    if (bud && !is_leaf[node]) is_bud[node] = true;
    if (is_bud[node]) buds.push_back (node);
}


int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <vector <int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%lld%lld", &u, &v);
            u--; v--;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }

        visited.resize (n);
        visited.assign (n, false);
        is_leaf.resize (n);
        is_leaf.assign (n, false);
        is_bud.resize (n);
        is_bud.assign (n, false);
        leaves.resize (0);
        buds.resize (0);

        dfs (0, adj);

        for (int i = 0; i < (int) buds.size(); i++) {
            // try to use up each leaf, starting with the ones that do not have buds as parents
        }
    }
}
