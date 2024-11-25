#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int N = (int)1e6 + 5;
vector<vector<int>> dp(10000);
vector<int> ans(N);

void precompute() {
    int row = 0;
    int cur = 1;
    while (cur < N) {
        if ((int)dp[row].size() == row + 1) {
            row++;
        }
        int ind = dp[row].size();
        if (row > 0) {
            int val = cur * cur;
            if ((int)dp[row - 1].size() > ind) val += dp[row - 1][ind];
            if (ind - 1 >= 0) val += dp[row - 1][ind - 1];
            if (row - 2 >= 0) {
                if ((int)dp[row - 2].size() > ind - 1 && ind > 0)
                    val -= dp[row - 2][ind - 1];
            }
            dp[row].push_back(val);
        } else {
            dp[row].push_back(1);
        }
        ans[cur] = dp[row].back();
        cur++;
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    printf("%lld\n", ans[n]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
