#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;

    vector<vector<int>> nxt(n, vector<int>(k, n));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            if (s[i + 1] == 'a' + j) {
                nxt[i][j] = i + 1;
            } else {
                nxt[i][j] = nxt[i + 1][j];
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(k, INF));
    vector<int> best(n, INF);
    for (int i = 0; i < k; i++) dp[n - 1][i] = 1;
    best[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            int ind = nxt[i][j];
            if (ind == n) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i][j], best[ind] + 1);
            }
        }
        for (int j = 0; j < k; j++) {
            best[i] = min(best[i], dp[i][j]);
        }
    }

    int q;
    scanf("%lld", &q);
    for (int query = 1; query <= q; query++) {
        string t;
        cin >> t;
        int m = (int)t.size();
        int ind = s[0] == t[0] ? 0 : nxt[0][t[0] - 'a'];
        for (int i = 1; i < m; i++) {
            if (ind == n) break;
            ind = nxt[ind][t[i] - 'a'];
        }
        if (ind == n) {
            printf("0\n");
            continue;
        }
        int ans = best[ind];
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
