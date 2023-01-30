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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }
    pair<int, int> prev = {-2, 0};
    int ans = 0;
    for (auto x : mp) {
        if (x.first == prev.first + 1) {
            ans += max(prev.second - x.second, 0LL);
        } else {
            ans += prev.second;
        }
        prev = x;
    }
    ans += prev.second;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
