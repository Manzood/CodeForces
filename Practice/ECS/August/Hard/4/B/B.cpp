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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int low = 0, high = (int)1e6 + 5;
    while (low < high) {
        int mid = (low + high) / 2;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / mid + (a[i] % mid > 0);
        }

        if (cnt <= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    vector<pair<int, int>> b;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int pieces = a[i] / high + (a[i] % high > 0);
        b.push_back({a[i], pieces});
        cnt += pieces;
    }

    sort(b.begin(), b.end(), [](pair<int, int> x, pair<int, int> y) {
        int v1 = x.first / x.second + (x.first % x.second > 0);
        int v2 = y.first / y.second + (y.first % y.second > 0);
        return v1 < v2;
    });

    int diff = k - cnt;
    int ptr = (int)b.size() - 1;
    for (int i = 0; i < diff; i++) {
        b[ptr--].second++;
    }

    int ans = 0;
    for (auto x : b) {
        int pieces = x.second;
        int higher = x.first % x.second;
        int val = x.first / pieces;
        for (int i = 0; i < pieces - higher; i++) {
            ans += val * val;
        }
        val++;
        for (int i = 0; i < higher; i++) {
            ans += val * val;
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
