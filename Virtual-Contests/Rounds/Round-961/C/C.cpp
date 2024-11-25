#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int eps = (int)1e-8;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), cnt(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            if (a[i] == 1) {
                printf("-1\n");
                return;
            }
            int x = a[i - 1];
            int y = a[i];
            while (x > y) {
                y = y * y;
                cnt[i]++;
            }
            cnt[i] += cnt[i - 1];
        } else if (cnt[i - 1] > 0) {
            int d = 0;
            double x = a[i - 1];
            double y = a[i];
            while (y >= x) {
                x = x * x;
                d++;
            }
            if (d <= cnt[i - 1]) cnt[i] += cnt[i - 1] - d + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[i];
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
