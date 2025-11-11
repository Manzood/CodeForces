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

bool check(int low, int high, vector<vector<int>>& a) {
    int n = (int)a[0].size();
    vector<vector<bool>> pos(2, vector<bool>(n, false));
    pos[0][0] = a[0][0] >= low && a[0][0] <= high;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            bool found = false;
            if (ok(i - 1, j, 2, n) && pos[i - 1][j]) {
                found = true;
            }
            if (ok(i, j - 1, 2, n) && pos[i][j - 1]) {
                found = true;
            }
            if (found && a[i][j] >= low && a[i][j] <= high) {
                pos[i][j] = true;
            }
        }
    }

    return pos[1][n - 1];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int low = i, high = 2 * n;
        int best = 2 * n + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(i, mid, a)) {
                best = min(best, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best <= 2 * n) {
            ans += 2 * n - best + 1;
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
