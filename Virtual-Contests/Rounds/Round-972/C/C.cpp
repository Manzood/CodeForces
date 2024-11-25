#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

vector<int> getScore(string s) {
    int n = (int)s.size();
    string x = "narek";
    int cur = 0;
    vector<int> retval = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == x[cur]) {
            cur++;
        } else {
            bool found = false;
            for (int j = 0; j < 5; j++) {
                if (s[i] == x[j]) found = true;
            }
            if (found) retval[1]++;
        }
        if (cur == 5) {
            retval[0] += 5;
            cur = 0;
        }
    }
    retval[2] = cur;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(5, -INF));
    dp[0][0] = 0;
    vector<int> score = getScore(s[0]);
    dp[0][score[2]] = max(dp[0][score[2]], score[0] - score[1]);
    for (int i = 1; i < n; i++) {
        score = getScore(s[i]);
        for (int j = 0; j < 5; j++) {
            int ind = (j + score[2]) % 5;
            dp[i][ind] =
                max(dp[i - 1][ind], dp[i - 1][j] + score[0] - score[1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, dp[n - 1][i] - i);
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
