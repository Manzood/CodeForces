#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, j, k;
    scanf("%lld%lld%lld", &n, &j, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    j--;

    if (k >= 2) {
        printf("YES\n");
        return;
    }

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (i == j) continue;
        if (a[i] > a[j]) {
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
