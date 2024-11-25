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
    vector<int> mp(n + 1);
    iota(mp.begin(), mp.end(), 0);
    int ans = 0;
    set<int> gt;
    for (int i = 0; i < n - 1; i++) {
        if (mp[a[i]] > mp[a[i + 1]]) {
            gt.insert(a[i]);
            ans += (int)gt.size();
            for (auto x : gt) {
                mp[x] = 0;
            }
            gt.clear();
            mp[a[i]] = 0;
        }
        if (mp[a[i]] > 0) gt.insert(a[i]);
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
