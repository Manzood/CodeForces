#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int i, int j, vector<vector<int>>& a, vector<vector<bool>>& vis) {
    if (vis[i][j]) return 0;
    vis[i][j] = true;
    int n = (int)a.size();
    int m = (int)a[0].size();
    int retval = a[i][j];
    if (retval == 0) return retval;
    for (auto d : dirs) {
        if (ok(i + d[0], j + d[1], n, m)) {
            retval += dfs(i + d[0], j + d[1], a, vis);
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(i, j, a, vis));
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
