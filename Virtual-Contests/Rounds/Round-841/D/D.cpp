#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;
constexpr int LOG = 10;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%lld", &a[i][j]);
    vector<vector<vector<int>>> sparse_table(
        n, vector<vector<int>>(m, vector<int>(LOG + 1, INF)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) sparse_table[i][j][0] = a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= LOG; k++) {
                int val = (1LL << (k - 1));
                if (i >= val * 2 - 1 && j >= val * 2 - 1) {
                    sparse_table[i][j][k] =
                        min({sparse_table[i][j][k - 1],
                             sparse_table[i - val][j - val][k - 1],
                             sparse_table[i][j - val][k - 1],
                             sparse_table[i - val][j][k - 1]});
                }
            }
        }
    }
    int low = 1, high = 1000, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool found = false;
        for (int i = mid - 1; i < n; i++) {
            for (int j = mid - 1; j < m; j++) {
                int largest = 0;
                while ((1LL << (largest + 1)) <= mid) largest++;
                int val = 1LL << largest;
                int cur =
                    min({sparse_table[i][j][largest],
                         sparse_table[i - mid + val][j][largest],
                         sparse_table[i][j - mid + val][largest],
                         sparse_table[i - mid + val][j - mid + val][largest]});
                found |= cur >= mid;
            }
        }
        if (found) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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
