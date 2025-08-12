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

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int r1, c1, r2, c2;
    scanf("%lld%lld%lld%lld", &r1, &c1, &r2, &c2);
    r1--, c1--, r2--, c2--;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<pair<int, int>> f;
    function<void(int, int)> dfs = [&](int x, int y) {
        if (f.count({x, y})) return;
        f.insert({x, y});
        for (auto d : dirs) {
            if (ok(x + d[0], y + d[1], n, n)) {
                if (a[x + d[0]][y + d[1]] == '0') {
                    dfs(x + d[0], y + d[1]);
                }
            }
        }
    };

    dfs(r2, c2);
    if (f.count({r1, c1})) {
        printf("0\n");
        return;
    }

    set<pair<int, int>> target = f;
    f.clear();
    dfs(r1, c1);

    int ans = (int)1e9 + 7;
    for (auto x : f) {
        for (auto y : target) {
            ans = min(ans, (x.first - y.first) * (x.first - y.first) +
                               (x.second - y.second) * (x.second - y.second));
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
