#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX_N = 20;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(MX_N, false));
    vector<vector<int>> prev(n + 1, vector<int>(MX_N, -1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < MX_N; k++) {
                if (dp[i][k]) {
                    dp[i + 1][k ^ a[i][j]] = true;
                    prev[i + 1][k ^ a[i][j]] = j;
                }
            }
        }
    }
    bool ans = false;
    vector<int> soln;
    for (int i = 1; i < MX_N; i++) {
        if (dp[n][i] == true) {
            ans = true;
            int ptr = prev[n][i];
            soln.push_back(ptr);
            debug(ptr);
            for (int j = n - 1; j > 0; j--) {
                debug(a[j][ptr] ^ ptr);
                ptr = prev[j][a[j][ptr] ^ ptr];
                debug(ptr);
                soln.push_back(ptr);
            }
            break;
        }
    }
    ans ? printf("TAK\n") : printf("NIE\n");
    if (ans) {
        reverse(soln.begin(), soln.end());
        for (int i = 0; i < n; i++) {
            printf("%lld ", soln[i] + 1);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
