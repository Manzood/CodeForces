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
    return x >= 0 && y >= 0 && x < n && y < m;
}

int getNode(int i, int j, int m) { return (i - 1) * m + (j - 1); }

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<vector<int>> a(k + 1, vector<int>(2));
    for (int i = 0; i < k + 1; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
    }

    bool possible = true;
    vector<vector<int>> adj((n + 1) * (m + 1));
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
            if (must[getNode(x + d1 / 2, y + d2 / 2, m)] == true)
                possible = false;
            must[getNode(x + d1 / 2, y + d2 / 2, m)] = true;
            adj[getNode(x + d1 / 2, y + d2 / 2, m)].push_back(
                getNode(x + d1 / 2, y + d2 / 2, m));
        }
    }

    vector<bool> vis((n + 1) * (m + 1), false);
    set<pair<int, int>> seen;
    bool foundMust = false;
    function<pair<int, int>(int)> dfs = [&](int node) {
        pair<int, int> ret = {0, 0};
        if (vis[node]) return ret;
        vis[node] = true;
        if (must[node]) foundMust = true;
        ret.first++;

        for (auto u : adj[node]) {
            pair<int, int> tmp =
                node < u ? make_pair(node, u) : make_pair(u, node);
            if (!seen.count(tmp)) {
                ret.second++;
                seen.insert(tmp);
            }
            pair<int, int> other = dfs(u);
            ret.first += other.first, ret.second += other.second;
        }

        return ret;
    };

    int ans = possible ? 1LL : 0LL;
    for (int i = 0; i < (n + 1) * (m + 1); i++) {
        if (!vis[i] && adj[i].size()) {
            pair<int, int> ret = dfs(i);
            if (ret.second > ret.first) {
                ans = 0;
            } else if (ret.second < ret.first) {
                assert(ret.second == ret.first - 1);
                ans *= ret.first;
                ans %= MOD;
            } else {
                if (!foundMust) {
                    ans *= 2;
                    ans %= MOD;
                }
            }
            foundMust = false;
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
