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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }
    map<pair<int, int>, int> mp[4];
    for (int i = 0; i < n; i++) mp[0][{0, a[i].second}]++;
    for (int i = 0; i < n; i++) mp[1][{a[i].first, 0}]++;
    for (int i = 0; i < n; i++) mp[2][{0, a[i].second - a[i].first}]++;
    for (int i = 0; i < n; i++) mp[3][{0, a[i].second + a[i].first}]++;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (auto x : mp[i]) {
            ans += x.second * (x.second - 1) / 2;
        }
    }
    printf("%lld\n", ans * 2);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
