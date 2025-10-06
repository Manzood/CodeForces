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
    vector<int> a(n), b(n);
    vector<int> pos(n + 1, -1), have(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        have[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        pos[b[i]] = i;
    }

    int low = 0, high = n;
    int ans = 2 * n;
    while (low <= high) {
        int mid = (low + high) / 2;

        bool possible = true;
        for (int i = 1; i <= n; i++) {
            if (have[i] || pos[i] - mid - (i - 1) < 0) continue;
            possible = false;
        }

        if (possible) {
            ans = min(mid, ans);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    ans += n;

    bool possible = true;
    int val = 2;
    for (int i = pos[1] + 1; i < n; i++) {
        if (b[i] == val) {
            val++;
        } else {
            possible = false;
        }
    }
    while (val <= n) {
        if (!have[val] && pos[val] - (val - b[n - 1] - 1) >= 0) {
            possible = false;
        }
        val++;
    }
    if (possible) ans = min(ans, n - b[n - 1]);

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
