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
    sort(a.begin(), a.end());

    if ((a[0] + a.back()) % 2 == 0) {
        printf("0\n");
        return;
    }

    int ans = n - 1;
    for (int i = 1; i < n; i++) {
        if ((a[0] + a[i]) % 2 != 0) {
            ans = min(ans, i);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if ((a[n - 1] + a[i]) % 2 != 0) {
            ans = min(ans, n - 1 - i);
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
