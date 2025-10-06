#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, h;
    scanf("%lld%lld", &n, &h);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;

        vector<int> b;
        for (int i = 0; i < mid; i++) b.push_back(a[i]);
        sort(b.begin(), b.end());

        int cur = 0;
        for (int i = mid - 1; i >= 0; i -= 2) {
            cur += b[i];
        }

        if (cur <= h) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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
