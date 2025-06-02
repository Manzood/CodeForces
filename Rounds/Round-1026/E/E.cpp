#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> v(n), p(n);
    map<int, set<int>> vol, pitch;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &v[i], &p[i]);
        vol[v[i]].insert(i);
        pitch[p[i]].insert(i);
    }

    // pick 0, go from there
    vector<bool> vis(n, false);
    vector<int> order;

    function<void(int, int)> dfs = [&](int node, int choice) {
        if (vis[node]) return;
        vis[node] = true;
        order.push_back(node);
        debug(node, v[node], p[node]);
        vol[v[node]].erase(node);
        pitch[p[node]].erase(node);

        if (choice == 0) {
            for (auto u : vol[v[node]]) {
                dfs(u, !choice);
            }
        } else {
            for (auto u : pitch[p[node]]) {
                dfs(u, !choice);
            }
        }
    };

    vol[v[0]].erase(0);
    pitch[p[0]].erase(0);
    vis[0] = true;
    for (auto u : vol[v[0]]) {
        if (!vis[u]) {
            dfs(u, 1);
            break;
        }
    }

    vector<int> ans;
    for (auto x : order) ans.push_back(x);
    order.clear();
    reverse(ans.begin(), ans.end());

    for (auto u : pitch[p[0]]) {
        if (!vis[u]) {
            dfs(u, 0);
            break;
        }
    }
    ans.push_back(0);
    for (auto x : order) ans.push_back(x);

    bool possible = true;
    for (int i = 2; i < (int)ans.size(); i++) {
        if (v[ans[i]] == v[ans[i - 1]] && v[ans[i]] == v[ans[i - 2]])
            possible = false;
        if (p[ans[i]] == p[ans[i - 1]] && p[ans[i]] == p[ans[i - 2]])
            possible = false;
    }

    if (possible && (int)ans.size() == n) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i] + 1);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
