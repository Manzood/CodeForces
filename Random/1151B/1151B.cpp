#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
// #define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<bool> dp(1024, false);
    vector<vector<int>> choice(n + 1, vector<int>(1024, -1));
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        vector<bool> new_dp(1024, false);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 1024; k++) {
                if (dp[k] == true) {
                    new_dp[a[i][j] ^ k] = true;
                    choice[i + 1][a[i][j] ^ k] = j;
                }
                // new_dp[a[i][j] ^ k] = new_dp[a[i][j] ^ k] | dp[k];
            }
        }
        dp = new_dp;
    }
    bool ans = false;
    int latest = 0;
    for (int i = 1; i < 1024; i++) {
        if (dp[i]) {
            ans = true;
            latest = i;
        }
    }
    if (ans) {
        vector<int> fin;
        printf("TAK\n");
        int i = n;
        while (i > 0) {
            int j = choice[i][latest];
            latest = latest ^ a[i - 1][j];
            i--;
            // printf("%d ", j + 1);
            fin.push_back(j + 1);
        }
        reverse(fin.begin(), fin.end());
        for (auto x : fin) {
            printf("%d ", x);
        }
        printf("\n");
    } else {
        printf("NIE\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
