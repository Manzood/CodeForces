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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int t = min(a[i], b[i]);
        a[i] -= t, b[i] -= t;
    }

    int ptr = 0;
    int cur = 0;
    int moves = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (a[ptr] > 0) {
            cur += a[ptr];
            a[ptr] = 0;
        }
        if (cur > 0) moves++;

        if (b[ptr] >= cur) {
            ans = max(ans, moves);
            moves = 0;
            b[ptr] -= cur;
            cur = 0;
        } else {
            cur -= b[ptr];
            b[ptr] = 0;
        }

        ptr++;
        if (ptr >= n) ptr = 0;
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
