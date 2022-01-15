#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<int> ans;
void bfs (vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    int n = visited.size();
    int m = visited[0].size();
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        // debug (cur.first, cur.second);
        q.pop();
        visited[cur.first][cur.second] = true;
        for (auto d: dirs) {
            if (ok(cur.first + d.first, cur.second + d.second, n, m) && !visited[cur.first + d.first][cur.second + d.second]) {
                q.push({cur.first + d.first, cur.second + d.second});
                visited[cur.first + d.first][cur.second + d.second] = true;
            }
        }
        int dist = max (n - 1 - cur.first, cur.first);
        dist += max (m - 1 - cur.second, cur.second);
        ans.push_back(dist);
    }
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    ans.clear();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector <bool> (m, false));
    int sum = (n % 2) + (m % 2);
    if (sum == 0) {
        q.push({n / 2, m / 2});
        q.push({n / 2 - 1, m / 2});
        q.push({n / 2, m / 2 - 1});
        q.push({n / 2 - 1, m / 2 - 1});
        visited[n / 2][m / 2] = true;
        visited[n / 2 - 1][m / 2] = true;
        visited[n / 2][m / 2 - 1] = true;
        visited[n / 2 - 1][m / 2 - 1] = true;
    } else if (sum == 1) {
        if (n % 2 == 1) {
            q.push({n / 2, m / 2});
            q.push({n / 2, m / 2 - 1});
            // debug (n / 2, m / 2);
            // debug (n / 2, m / 2 - 1);
            visited[n / 2][m / 2] = true;
            visited[n / 2][m / 2 - 1] = true;
        } else {
            q.push({n / 2, m / 2});
            q.push({n / 2 - 1, m / 2});
            visited[n / 2][m / 2] = true;
            visited[n / 2 - 1][m / 2] = true;
        }
    } else {
            q.push({n / 2, m / 2});
            visited[n / 2][m / 2] = true;
    }
    bfs(visited, q);
    // debug("done");
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
