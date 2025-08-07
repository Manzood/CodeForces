#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].second);
    }

    for (int i = 0; i < n; i++) {
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end());

    bool found = false;
    for (int i = 1; i < n; i++) {
        if (a[i].first <= a[i - 1].second) found = true;
    }

    int val = 0;
    if (!found) {
        val = (int)1e18 + 7;
        for (int i = 1; i < n; i++) {
            val = min(val, abs(a[i].first - a[i - 1].second) * 2);
        }
    }

    int ans = val;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i].first - a[i].second);
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
