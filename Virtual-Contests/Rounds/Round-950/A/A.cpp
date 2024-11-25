#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string a;
    cin >> a;
    int ans = 0;
    vector<int> cnt(7, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i] - 'A']++;
    }
    for (int i = 0; i < 7; i++) {
        ans += max(0LL, m - cnt[i]);
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
