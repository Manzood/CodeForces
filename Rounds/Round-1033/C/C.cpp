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

    if ((m > n * (n + 1) / 2) || m < n) {
        printf("-1\n");
        return;
    }

    vector<int> ans;
    vector<bool> used(n, false);
    int cur = n * (n + 1) / 2;
    for (int i = n; i >= 1; i--) {
        if (cur - (i - 1) >= m) {
            cur -= i - 1;
        } else {
            ans.push_back(i);
            used[i - 1] = true;
        }
    }
    assert(cur == m);

    for (int i = 0; i < n; i++) {
        if (!used[i]) ans.push_back(i + 1);
    }

    printf("%lld\n", ans[0]);
    for (int i = 0; i < n - 1; i++) {
        printf("%lld %lld\n", ans[i], ans[i + 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
