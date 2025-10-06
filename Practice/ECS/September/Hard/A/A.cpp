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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> up(n, vector<int>(m, 0)), left(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && s[i][j] == s[i - 1][j]) up[i][j] = up[i - 1][j] + 1;
            if (j > 0 && s[i][j] == s[i][j - 1])
                left[i][j] = left[i][j - 1] + 1;
        }
    }

    vector<vector<int>> pse(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        stack<int> st;

        for (int j = 0; j < m; j++) {
            while (!st.empty()) {
                if (up[i][j] <= up[i][st.top()])
                    st.pop();
                else
                    break;
            }

            if (!st.empty()) pse[i][j] = st.top();
            st.push(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 3 * (up[i][j] + 1) - 1) continue;
            int cur = pse[i][j] == -1 ? j : j - pse[i][j] - 1;
            cur = min(cur, left[i][j]);

            int ind = i - up[i][j] - 1;
            if (up[ind][j] != up[i][j]) continue;
            cur = min(cur, pse[ind][j] == -1 ? j : j - pse[ind][j] - 1);
            cur = min(cur, left[ind][j]);

            ind -= (up[i][j] + 1);
            if (up[ind][j] < up[i][j]) continue;
            int x = j;
            while (true) {
                if (pse[ind][x] > j - cur - 1) {
                    if (up[ind][pse[ind][x]] < up[i][j]) {
                        cur = min(cur,
                                  pse[ind][x] == -1 ? j : j - pse[ind][x] - 1);
                        break;
                    } else {
                        x = pse[ind][x];
                    }
                } else {
                    break;
                }
            }
            // if (i == 4 && j == 2) debug(cur, left[ind], up[ind], pse[ind]);
            cur = min(cur, left[ind][j]);

            ans += cur + 1;
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
