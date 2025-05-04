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

void dfs(int ind, vector<vector<int>>& ways, vector<vector<int>>& last,
         vector<vector<int>>& a, map<pair<int, int>, int> points) {
    int k = (int)a.size();
    int i = a[ind][0], j = a[ind][1], n = (int)ways.size(),
        m = (int)ways[0].size();

    for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (ok(x, y, n, m)) {
            if (last[x][y] == ind - 1) ways[i][j] += ways[x][y];
        }
    }
    if (ind == k - 1) return;

    function<bool(int, int)> hasNext = [&](int curX, int curY) {
        int targetX = a[ind + 1][0], targetY = a[ind + 1][1];
        for (auto d : dirs) {
            int x = curX + d[0], y = curY + d[1];
            if (x == targetX && y == targetY) return true;
        }
        return false;
    };

    auto areAdjacent = [](pair<int, int> a, pair<int, int> b) {
        for (auto d : diags) {
            if (a.first + d[0] == b.first && a.second + d[1] == b.second)
                return true;
        }
        return false;
    };

    for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (ok(x, y, n, m) && hasNext(x, y)) {
            if (x + d[0] == a[ind + 1][0] && y + d[1] == a[ind + 1][1]) {
                ways[x][y] = ways[i][j];
                last[x][y] = ind;
                int cnt = 0;
                for (auto cur : dirs) {
                    if (ok(x + cur[0], y + cur[1], n, m)) {
                        if (points.count({x + cur[0], y + cur[1]})) cnt++;
                    }
                }
                if (cnt == 4) ways[x][y] = 0;
            } else {
                // not a line
                vector<int> surrounding;
                int cnt = 0;
                for (auto cur : dirs) {
                    if (ok(x + cur[0], y + cur[1], n, m)) {
                        if (points.count({x + cur[0], y + cur[1]})) {
                            surrounding.push_back(
                                points[{x + cur[0], y + cur[1]}]);
                            cnt++;
                        }
                    }
                }
                sort(surrounding.begin(), surrounding.end());
                if (cnt == 3) {
                    if (surrounding[0] != ind) {
                        // ways * 3 / 2
                    }
                } else {
                }
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<vector<int>> a(k + 1, vector<int>(2));
    for (int i = 0; i < k + 1; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
    }
    vector<vector<int>> ways(n, vector<int>(m, 0));
    vector<vector<int>> last(n, vector<int>(m, -2));
    ways[a[0][0]][a[0][1]] = 1;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
