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
        scanf("%lld\n", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    vector<int> m = {2, 2, 3};
    int cur = h;
    int ind = 0;
    for (int i = 0; i < n; i++) {
        while (cur <= a[i] && ind < 3) {
            cur *= m[ind++];
        }
        if (cur <= a[i]) {
            break;
        }
        cur += a[i] / 2;
        ans = max(ans, i + 1);
    }
    m = {3, 2, 2};
    cur = h;
    ind = 0;
    for (int i = 0; i < n; i++) {
        while (cur <= a[i] && ind < 3) {
            cur *= m[ind++];
        }
        if (cur <= a[i]) {
            break;
        }
        cur += a[i] / 2;
        ans = max(ans, i + 1);
    }
    m = {2, 3, 2};
    cur = h;
    ind = 0;
    for (int i = 0; i < n; i++) {
        while (cur <= a[i] && ind < 3) {
            cur *= m[ind++];
        }
        if (cur <= a[i]) {
            break;
        }
        cur += a[i] / 2;
        ans = max(ans, i + 1);
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
