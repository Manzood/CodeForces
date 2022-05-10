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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int ans = -1;
    int mxl = n, mxr = n;
    int l = n, r = n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i-1] == a[i]) {
            cnt++;
        } else if (i == 0) {
            cnt = 1;
        } else {
            if (cnt < k) {
                l = n;
            } else {
                l = min(l, i - 1);
                r = i - 1;
                if (l < n && r < n) {
                    if (a[r] - a[l] > ans) {
                        mxr = r;
                        mxl = l;
                        ans = a[r] - a[l];
                    }
                }
            }
            if (a[i] - a[i-1] > 1) l = n;
            cnt = 1;
        }
    }
    if (cnt >= k) {
        l = min(l, n - 1);
        r = n - 1;
        if (l < n && r < n) {
            if (a[r] - a[l] > ans) {
                mxr = r;
                mxl = l;
                ans = a[r] - a[l];
            }
        }
    }
    if (ans != -1) printf("%lld %lld\n", a[mxl], a[mxr]);
    else printf("-1\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
