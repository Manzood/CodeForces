#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%lld", &a[i][j]);
    // prefix sum approach
    int low = 1, high = 1000, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<vector<int>> b(n, vector<int>(m, 0));
        vector<vector<int>> pref(n, vector<int>(m, 0));
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[i][j] >= mid;
                pref[i][j] = b[i][j];
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
                if (i >= mid - 1 && j >= mid - 1) {
                    int val = pref[i][j];
                    if (i >= mid) val -= pref[i - mid][j];
                    if (j >= mid) val -= pref[i][j - mid];
                    if (i >= mid && j >= mid) val += pref[i - mid][j - mid];
                    found |= val == mid * mid;
                }
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
