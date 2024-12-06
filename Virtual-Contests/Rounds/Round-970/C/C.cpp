#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int sum = (r - l) * 2 + 1;
    int ans = 0;
    int low = 0, high = sum;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid - mid > sum) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
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