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
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &d[i]);
    }
    vector<bool> used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ind = d[i] - 1;
        if (used[ind]) {
            printf("%lld ", ans);
            continue;
        }
        ans++;
        used[ind] = true;
        int cur = a[ind] - 1;
        while (cur != ind) {
            used[cur] = true;
            ans++;
            cur = a[cur] - 1;
        }
        printf("%lld ", ans);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
