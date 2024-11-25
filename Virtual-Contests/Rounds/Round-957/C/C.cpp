#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> ans;
    for (int i = n; i >= k; i--) {
        ans.push_back(i);
    }
    for (int i = m + 1; i < k; i++) {
        ans.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        ans.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", ans[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
