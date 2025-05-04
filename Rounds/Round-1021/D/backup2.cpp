#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> diags = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int getNode(int i, int j, int m) { return i * m + j; }

// create graph
// count number of ways to choose exactly one vertex for each edge
void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<vector<int>> a(k + 1, vector<int>(2));
    for (int i = 0; i < k + 1; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
    }

    bool possible = true;
    vector<vector<int>> adj(n * m);
    vector<bool> must(n * m, false);
    for (int i = 1; i < k + 1; i++) {
        if (abs(a[i][0] - a[i - 1][0]) + abs(a[i][1] - a[i - 1][1]) != 2)
            possible = false;

        int x = a[i - 1][0], y = a[i - 1][1], d1 = a[i][0] - a[i - 1][0],
            d2 = a[i][1] - a[i - 1][1];
        if (a[i][0] != a[i - 1][0] && a[i][1] != a[i - 1][1]) {
            adj[getNode(x + d1, y, m)].push_back(getNode(x, y + d2, m));
            adj[getNode(x, y + d2, m)].push_back(getNode(x + d1, y, m));
        } else {
            // I don't understand the self loop idea
            must[getNode(x + d1 / 2, y + d2 / 2, m)] = true;
        }
    }

    vector<vector<bool>> vis(n * m, vector<bool>(2, false));
    function<int(int, bool)> dfs = [&](int node, bool choosing) {
        vis[node][choosing] = true;
        if (must[node] && !choosing) return 0LL;

        int ret = 0;
        int cnt = 0;
        for (auto u : adj[node]) {
            if (choosing && !vis[u][0]) {
                ret += dfs(u, 0);
                cnt++;
            }
            if (!must[node] && !choosing && !vis[u][1]) {
                ret += dfs(u, 1);
                cnt++;
            }
        }

        if (cnt && ret == 0) return ret;
        if (!cnt) ret = 1;
        return ret;
    };

    int ans = 0;
    for (int i = 1; i < k + 1; i++) {
        int x = a[i - 1][0], y = a[i - 1][1], d1 = a[i][0] - a[i - 1][0],
            d2 = a[i][1] - a[i - 1][1];
        if (a[i][0] != a[i - 1][0] && a[i][1] != a[i - 1][1]) {
            ans += dfs(getNode(x + d1, y, m), 0);
            ans += dfs(getNode(x + d1, y, m), 1);
            ans += dfs(getNode(x, y + d2, m), 0);
            ans += dfs(getNode(x, y + d2, m), 1);
        } else {
            must[getNode(x + d1 / 2, y + d2 / 2, m)] = true;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
