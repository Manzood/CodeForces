#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, p;
    scanf("%lld%lld", &n, &p);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    set<int> larger, smaller;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[n - 1]) {
            larger.insert(a[i]);
        } else if (a[i] < a[n - 1]) {
            smaller.insert(a[i]);
        }
    }
    int ans = 0;
    int cur = a[n - 1];
    if ((int)larger.size() < (p - a[n - 1] - 1)) {
        // gotta increase
        cur = p - 1;
        while (cur > a[n - 1] && larger.count(cur)) {
            cur--;
        }
        ans += cur - a[n - 1];
    }
    // if (test == 9) debug(cur);
    if ((int)smaller.size() < a[n - 1]) {
        // get to zero
        if (cur != 0) {
            ans += p - cur;
            cur = 0;
            smaller.insert(0);
        }
        // if (test == 1) debug(ans);
        // update elements
        int carry = 1;
        for (int i = n - 2; i >= 0; i--) {
            int val = a[i] + carry;
            if (val >= p) {
                carry = 1;
                val = 0;
            } else {
                carry = 0;
            }
            if (val < a[n - 1]) smaller.insert(val);
            if (i == 0 && carry == 1) {
                if (a[n - 1] > 1) smaller.insert(1);
            }
        }
        if (n == 1) {
            if (a[0] > 1) smaller.insert(1);
        }
        int target = a[n - 1] - 1;
        if (target > 0) {
            while (target > 0 && smaller.count(target)) {
                target--;
            }
            ans += target;
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
