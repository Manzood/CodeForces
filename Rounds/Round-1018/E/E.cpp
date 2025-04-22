#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<int> dp(n, 0);
    int cnt = 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int val = cnt / 2 + (cnt & 1);
        if (s[i] == 'P') {
            dp[i] = dp[i - 1];
            cnt++;
        } else {
            dp[i] = dp[i - 1] + val;
        }
    }
    // printf("%lld\n", dp[n - 1]);
    // what if it's a 2D vector:
    vector<vector<set<int>>> a = {{{1, 2}, {1, 2}, {1, 2}},
                                  {{2, 3}, {2, 3}, {2, 3}},
                                  {{3, 1}, {3, 1}, {3, 1}}};
    unordered_map<int, int> mp = {{1, 2}, {2, 3}};
    set<int> x = {1, 2, 3};
    debug(1, 2, 3, x, a);
    debug(mp);
    debug(a);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
