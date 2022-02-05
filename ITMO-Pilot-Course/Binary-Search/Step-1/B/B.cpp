#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        int target;
        scanf("%lld", &target);
        int left = 0;
        int right = n - 1;
        int mid;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (a[mid] > target) {
                right = mid - 1;
            } else if (a[mid] <= target) {
                left = mid;
            }
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
