#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
            mx = max(mx, a[i][j]);
        }
    }

    int ans = mx;
    vector<vector<int>> up(n, vector<int>(m, 0)), down(n, vector<int>(m, 0)),
        left(n, vector<int>(m, 0)), right(n, vector<int>(m, 0));
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) up[i][j] += up[i - 1][j];
            if (j > 0) left[i][j] += left[i][j - 1];
            if (a[i][j] == mx) {
                up[i][j]++;
                left[i][j]++;
                tot++;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i < n - 1) down[i][j] += down[i + 1][j];
            if (j < m - 1) right[i][j] += right[i][j + 1];
            if (a[i][j] == mx) {
                down[i][j]++;
                right[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            if (i > 0) cnt += up[i - 1][j];
            if (j > 0) cnt += left[i][j - 1];
            if (i < n - 1) cnt += down[i + 1][j];
            if (j < m - 1) cnt += right[i][j + 1];
            if (a[i][j] == mx) cnt++;
            if (cnt == tot) ans = mx - 1;
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
