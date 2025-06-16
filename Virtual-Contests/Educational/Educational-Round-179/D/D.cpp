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
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());
    vector<vector<int>> ans(n);
    int val = -1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            val++;
            ans[i].push_back(a[val]);
            ans[i].push_back(a[m - val - 1]);
            ans[i].push_back(a[val]);
            ans[i].push_back(a[m - val - 1]);
            ans[i].push_back(a[val]);
            ans[i].push_back(a[m - val - 1]);
        } else {
            ans[i].push_back(a[m - val - 1]);
            ans[i].push_back(a[val]);
            ans[i].push_back(a[m - val - 1]);
            ans[i].push_back(a[val]);
            ans[i].push_back(a[m - val - 1]);
            ans[i].push_back(a[val]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
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
