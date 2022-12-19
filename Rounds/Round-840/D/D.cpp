#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, f, s, x, y;
    scanf("%lld%lld%lld%lld%lld", &n, &f, &s, &x, &y);
    f--;
    s--;
    int ans = 0;
    if (x == n) {
        if (f == 0) {
            // not possible
        } else {
            // calculate number of ways
        }
    } else if (y == n) {
        if (s == 0) {
            // not possible
        } else {
            // calculate number of ways
        }
    } else {
        // normal
        // calculate number of ways before x;
        for (int i = 1; i < f; i++) {
            // ans += n - 3 C i
        }
        for (int i = s + 1; i < n; i++) {
            // ans += n - 3 C (n - i)
        }
        // in between
        if (s - f - 1 >= n - max(x, y)) {
            int val = 1;
            for (int i = n - 1; i > max(x, y); i--) {
                val *= 2;
            }
            ans += val;
            int diff = (s - f - 1) - (n - max(x, y));
            // max(x, y) - min(x, y) - 1 C diff

            // then
            // min(x, y) - 1 C f
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
