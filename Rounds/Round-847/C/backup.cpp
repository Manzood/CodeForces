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
    vector<vector<int>> a(n, vector<int>(n - 1));
    vector<int> missing(n), sum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            scanf("%lld", &a[i][j]);
            sum[i] += a[i][j];
        }
        missing[i] = n * (n + 1) / 2 - sum[i];
    }
    vector<int> ans(n);
    vector<int> cnt(n, 0);
    int mx = 0, ind = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i][0] - 1]++;
        if (cnt[a[i][0] - 1] > mx) {
            mx = cnt[a[i][0] - 1];
            ind = a[i][0] - 1;
        }
    }
    ans[0] = ind + 1;
    int prev = ind;
    for (int i = 1; i < n; i++) {
        // find current value
        cnt.assign(n, 0);
        for (int j = 0; j < n; j++) {
            int index = n;
            for (int x = 0; x < n - 1; x++) {
                if (a[j][x] - 1 == prev) {
                    index = x;
                }
            }
            if (index == n) {
                cnt[a[j][i - 1] - 1]++;
            } else if (index < n - 2) {
                cnt[a[j][index + 1] - 1]++;
            } else {
                cnt[missing[j] - 1]++;
            }
        }
        mx = 0;
        ind = 0;
        for (int j = 0; j < n; j++) {
            if (cnt[j] > mx) {
                mx = cnt[j];
                ind = j;
            }
        }
        ans[i] = ind + 1;
        prev = ind;
    }
    for (auto x : ans) {
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
