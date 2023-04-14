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
    vector<pair<int, int>> a(n);
    bool ans = false;
    bool left = false, right = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        if (a[i].first == a[i].second && a[i].first == k)
            ans = true;
        else if (a[i].first == k)
            left = true;
        else if (a[i].second == k)
            right = true;
    }
    if (left && right) ans = true;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
