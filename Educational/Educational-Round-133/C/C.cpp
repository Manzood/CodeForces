#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int m;
    scanf("%lld", &m);
    vector<vector<int>> a(2, vector<int>(m));
    vector<vector<int>> snake(2, vector<int>(m, 0));
    // vector<vector<int>> upper(2, vector<int>(m, 0));
    vector<int> upper(m, 0);
    vector<int> lower(m, 0);
    // vector<vector<int>> lower(2, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[0][i]);
        if (i > 0) a[0][i]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[1][i]);
        a[1][i]++;
    }
    int ans = (int)1e18 + 7;
    // calculate snake
    for (int i = 0; i < m; i++) {
        int cur = 0;
        if ((i + cur) % 2 == 0) cur++;
        int other = cur ^ 1;
        if (i > 0) {
            snake[other][i] = max(a[other][i], snake[other][i - 1] + 1);
        } else {
            snake[other][i] = a[other][i];
        }
        snake[cur][i] = max(a[cur][i], snake[other][i] + 1);
    }
    // calculate upper -> which is the upper to lower row
    for (int i = m - 1; i >= 0; i--) {
        if (i == m - 1) {
            upper[i] = a[0][i] + 1;
            upper[i] = max(upper[i], a[1][i]);
        } else {
            upper[i] = a[0][i] + 1 + 2 * (m - 1 - i);
            upper[i] = max(upper[i + 1] + 1, upper[i]);
            upper[i] = max(upper[i], a[1][i]);
        }
    }
    // same for lower
    for (int i = m - 1; i >= 0; i--) {
        if (i == m - 1) {
            lower[i] = a[1][i] + 1;
            lower[i] = max(lower[i], a[0][i]);
        } else {
            lower[i] = a[1][i] + 1 + 2 * (m - 1 - i);
            lower[i] = max(lower[i + 1] + 1, lower[i]);
            lower[i] = max(lower[i], a[0][i]);
        }
    }
    // get answer
    for (int i = 0; i < m; i++) {
        // upper and lower for each row
        int cur = 0;
        if ((i + cur) % 2 == 0) cur++;
        int other = cur ^ 1;
        int val = 0;
        if (i > 0) {
            val = snake[other][i - 1] + 2 * (m - i);  // verified
            if (other == 0) {
                // upper
                val = max(val, upper[i]);
            } else {
                val = max(val, lower[i]);
            }
        } else {
            val = upper[i];
        }
        ans = min(ans, val);
    }
    if (m & 1) {
        ans = min(ans, snake[1][m - 1]);
    } else {
        ans = min(ans, snake[0][m - 1]);
    }

    // for (int i = 0; i < m; i++) {
    //     printf("%lld ", upper[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < m; i++) {
    //     printf("%lld ", snake[1][i]);
    // }
    // printf("\n");
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
