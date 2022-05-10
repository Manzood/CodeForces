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
    vector <vector <int>> a(n, vector <int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = a[i][j];
            int y = j - 1;
            for (int x = i - 1; x >= 0; x--) {
                if (y < 0) break;
                cur += a[x][y];
                y--;
            }
            y = j + 1;
            for (int x = i - 1; x >= 0; x--) {
                if (y >= m) break;
                cur += a[x][y];
                y++;
            }
            y = j - 1;
            for (int x = i + 1; x < n; x++) {
                if (y < 0) break;
                cur += a[x][y];
                y--;
            }
            y = j + 1;
            for (int x = i + 1; x < n; x++) {
                if (y >= m) break;
                cur += a[x][y];
                y++;
            }
            mx = max(mx, cur);
        }
    }
    printf("%lld\n", mx);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
