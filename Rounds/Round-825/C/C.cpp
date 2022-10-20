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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> leftmost(n, n);
    int r = 0;
    int cnt = 0;
    for (int l = 0; l < n; l++) {
        int req = r - l + 1;
        while (r < n - 1 && a[r] >= req) {
            cnt += r - l + 1;
            leftmost[r] = min(l, leftmost[r]);
            r++;
            req = r - l + 1;
        }
        if (r == n - 1) {
            if (a[r] >= req) {
                leftmost[r] = min(l, leftmost[r]);
                cnt++;
            }
        }
    }
    vector<int> ind(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ind[i] = i;
        } else {
            if (a[i] < a[i + 1]) {
                ind[i] = i;
            } else {
                ind[i] = i + 1;
            }
        }
    }
    // make sure to double check the bottleneck
    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        int p, x;
        scanf("%lld%lld", &p, &x);
        p--;
        if (x < a[p]) {
            int val = a[p];
            int l = leftmost[p];
            val = min(val, p - l + 1);
            int diff = val - x;
            diff = max(0LL, diff);
            // int ans = (p - l + 1) * (p - l + 2) / 2;
            // diff = p - l + 1 - diff;
            // ans -= diff * (diff + 1) / 2;
            int ans = diff;
            ans = cnt - ans;
            printf("%lld\n", ans);
        } else if (x > a[p] && p != n - 1) {
            // do it for greater
            // find new bottlneck
            // then calculate from leftmost
            r = ind[p + 1];
            int l = leftmost[p];
            int l2;
            if (p >= 1) {
                l2 = leftmost[p - 1];
                l2 = max(l2, p - x + 1);
            } else
                l2 = leftmost[p];
            p = ind[p];
            // int val = (p - l + 1) * (p - l + 2) / 2;
            int val = p - l + 1;
            int val2 = p - l2 + 1;
            if (a[r] >= r - l2 + 1)
                r = n - 1;
            else
                r--;
            val2 += (r - l2 + 1) * (r - l2 + 2) / 2;
            val2 -= (p - l2 + 1) * (p - l2 + 2) / 2;
            int ans = (val2 - val);
            ans = max(ans, 0LL);
            ans += cnt;
            printf("%lld\n", ans);
        } else {
            printf("%lld\n", cnt);
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
