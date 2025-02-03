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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<vector<bool>> possible(n + 1, vector<bool>(1024, false));
    vector<vector<int>> choice(n + 1, vector<int>(1024, -1));
    possible[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 1024; k++) {
                if (possible[i][a[i][j] ^ k]) {
                    possible[i + 1][k] = true;
                    choice[i + 1][k] = j;
                }
            }
        }
    }
    vector<int> ans;
    bool found = false;
    for (int i = 1; i < 1024; i++) {
        if (possible[n][i]) {
            found = true;
            int row = n;
            int cur = i;
            while (row > 0) {
                assert(cur != -1);
                ans.push_back(choice[row][cur] + 1);
                cur ^= a[row - 1][choice[row][cur]];
                row--;
            }
            break;
        }
    }
    if (!found) {
        printf("NIE\n");
        return;
    }
    printf("TAK\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%lld ", ans[i]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
