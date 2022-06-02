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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i - 1; j >= 0 && a[j] <= a[i]; j--) {
            sum += a[j];
            if (sum > 0) ans = false;
        }
        sum = 0;
        for (int j = i + 1; j < n && a[j] <= a[i]; j++) {
            sum += a[j];
            if (sum > 0) ans = false;
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
