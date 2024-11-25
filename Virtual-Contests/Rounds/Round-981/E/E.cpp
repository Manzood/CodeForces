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
        a[i]--;
    }
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cur = i;
            int len = 0;
            while (!vis[cur]) {
                len++;
                vis[cur] = true;
                cur = a[cur];
            }
            if (len - 2 > 0) {
                ans += (len - 1) / 2;
            }
        }
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
