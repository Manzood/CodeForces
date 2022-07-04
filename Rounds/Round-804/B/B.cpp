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
    vector<vector<int>> ans(n);
    vector<int> a = {0, 1, 1, 0};
    vector<int> b = {1, 0, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 4 == 0) {
                ans[i].push_back(a[j % 4]);
            } else if (i % 4 == 1) {
                ans[i].push_back(b[j % 4]);
            } else if (i % 4 == 2) {
                ans[i].push_back(b[j % 4]);
            } else {
                ans[i].push_back(a[j % 4]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
