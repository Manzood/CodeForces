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
    }
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    int best = 2 * n;
    int cur = n;
    for (int i = n; i >= 1; i--) {
        if (!have[i]) cur = max(cur, n - pos[i] - (n - i) + i);
        debug(i, pos[i], cur);
    }
    best = min(best, cur);

    bool possible = true;
    for (int i = pos[n] - 1; i >= 0; i--) {
        if (b[i] != n - (pos[n] - i)) {
            possible = false;
        }
    }

    for (int i = b[0] - 1; i >= 1; i--) {
        if (have[i]) continue;
        if (pos[i] < n - 1 - (b[i] - i)) continue;
        possible = false;
    }

    if (possible) best = min(best, b[0] - 1);

    printf("%lld\n", best);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
