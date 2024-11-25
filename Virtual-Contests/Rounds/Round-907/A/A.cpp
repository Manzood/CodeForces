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
    int r = 0;
    int x = 0, y = 1;
    bool ans = true;
    while (y <= n) {
        for (int i = x + 1; i < y; i++) {
            if (a[i] < a[i - 1]) {
                ans = false;
            }
        }
        x = y;
        r++;
        y = (1LL << r);
    }
    for (int i = x + 1; i < y && i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans = false;
        }
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
