#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> visited;
vector<int> ans;

void dfs(int v, vector<vector<int>>& adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u, adj);
    }
    ans.push_back(v);
}

void topological_sort(vector<vector<int>>& adj) {
    int n = (int)adj.size();
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i, adj);
    }
    reverse(ans.begin(), ans.end());
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> b(n);
    for (auto& x : b) {
        scanf("%lld", &x);
    }
    int low = 0, high = n;
    for (int i = 0; i < n; i++) {
        if (b[i] > i + 1) {
            // k >= i + 1 and k < b[i]
            low = max(low, i + 1);
            high = min(high, b[i] - 1);
        } else {
            // k < i + 1 and k >= b[i]
            low = max(low, b[i]);  // check this
            high = min(high, i);
        }
    }
    // debug(high, low);
    assert(high == low);  // CHANGE THIS
    // found k, hopefully
    vector<vector<int>> adj(n);
    vector<int> start;
    for (int i = 0; i < n; i++) {
        if (b[i] <= n && b[i] > 0) {
            adj[b[i] - 1].push_back(i);
        } else {
            start.push_back(i);
        }
    }
    int cnt = 0;
    int last = (int)start.size() - 1;
    set<int> used;
    for (auto x : start) {
        used.insert(x);
        if ((int)adj[x].size() > 0) {
            last = x;
            cnt++;
        }
    }
    assert(cnt < 2);
    // do the dfs to get the topologically sorted order
    vector<int> a(n, 0);
    cnt = 0;
    for (int i = 0; i < (int)start.size(); i++) {
        if (start[i] == last) continue;
        a[cnt++] = start[i] + 1;
    }
    a[(int)start.size() - 1] = last + 1;
    topological_sort(adj);
    int ind = (int)start.size();
    for (auto x : ans) {
        if (used.count(x)) continue;
        a[ind++] = x + 1;
        used.insert(x);
        for (auto u : adj[x]) {
            assert(!used.count(u));
            a[ind++] = u + 1;
            used.insert(u);
        }
        // if (!used.count(x)) a[ind++] = x + 1;
        // assert(a[ind - 1] > 0);
    }
    // assert(ind == n);
    debug(a);
    printf("%lld\n", low);
    set<int> fin;
    for (auto x : a) {
        assert(fin.count(x) == 0);
        assert(x > 0 && x <= n);
        printf("%lld ", x);
        fin.insert(x);
    }
    vector<int> c(n);
    int l1 = n + 1, l2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= low) {
            c[a[i] - 1] = l1;
            l2 = a[i];
        } else {
            c[a[i] - 1] = l2;
            l1 = a[i];
        }
    }
    debug(start, a, low, c, b);
    for (int i = 0; i < n; i++) {
        assert(c[i] == b[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
