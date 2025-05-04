#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> diags = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<vector<int>> a(k + 1, vector<int>(2));
    bool possible = true;
    for (int i = 0; i < k + 1; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        if (i > 0) {
            int d = abs(a[i][0] - a[i - 1][0]) + abs(a[i][1] - a[i - 1][1]);
            if (d != 2) possible = false;
        }
    }

    set<pair<int, int>> vis;
    function<int(int)> find = [&](int ind) {
        if (ind == k) return 1LL;
        int ret = 0;
        int x = a[ind][0], y = a[ind][1];
        vis.insert({x, y});

        for (auto d : dirs) {
            int fx = x + d[0], fy = y + d[1];
            if (!ok(fx, fy, n, m)) continue;
            if (vis.count({fx, fy})) continue;

            int dx = abs(a[ind + 1][0] - fx);
            int dy = abs(a[ind + 1][1] - fy);
            if (dx + dy != 1) continue;

            vis.insert({fx, fy});
            ret += find(ind + 1);
            ret %= MOD;
            vis.erase({fx, fy});
        }

        vis.erase({x, y});

        return ret;
    };

    int ans = find(0);
    printf("%lld\n", !possible ? 0 : ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
