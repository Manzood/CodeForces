#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 3;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    pair<int, int> diff;
    bool f = false, s = false;
    for (int i = 1; i < 4; i++) {
        diff.first = a[i % 3].first - a[i - 1].first;
        diff.second = a[i % 3].second - a[i - 1].second;
        if (diff.first == 0) f = true;
        if (diff.second == 0) s = true;
    }
    if (f && s) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
