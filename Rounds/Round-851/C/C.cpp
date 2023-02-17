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
    if (n % 2 == 0) {
        printf("No\n");
        return;
    }
    vector<pair<int, int>> ans;
    int other = 2 * n;
    for (int i = 1; i <= n; i++) {
        if (other <= n) {
            other = 2 * n - 1;
        }
        ans.push_back({i, other});
        other -= 2;
    }
    printf("Yes\n");
    for (int i = 0; i < n; i++) {
        printf("%lld %lld\n", ans[i].first, ans[i].second);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
