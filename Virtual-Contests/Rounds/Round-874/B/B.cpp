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
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i].first);
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].second] = b[i].first;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
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
