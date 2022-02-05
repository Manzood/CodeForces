#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int k;
    scanf("%lld", &k);
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        int ansl = n;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] >= l) {
                ansl = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int ansr = n;
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] >= r + 1) {
                ansr = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // debug (a, l, r, ansr, ansl);
        printf("%lld ", ansr - ansl);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
