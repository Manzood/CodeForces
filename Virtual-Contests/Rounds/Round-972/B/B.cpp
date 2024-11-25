#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b.begin(), b.end());
    for (int query = 0; query < q; query++) {
        int cur;
        scanf("%lld", &cur);
        int ind = lower_bound(b.begin(), b.end(), cur) - b.begin();
        int ans = 0;
        if (ind == 0) {
            ans = b[ind] - 1;
        } else if (ind == m) {
            ans = n - b[ind - 1];
        } else {
            int right = b[ind];
            int left = b[ind - 1];
            int mid = (left + right) / 2;
            ans = min(mid - left, right - mid);
        }
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
