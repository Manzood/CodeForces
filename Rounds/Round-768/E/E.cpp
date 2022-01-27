#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> last(n + 1, -1);
    for (int i = 0; i < n; i++) {
        last[a[i]] = i;
    }
    int cur_end = -1;
    int start = -1;
    int next_end = -1;
    int ans = 0;
    // weird, inelegant logic
    for (int i = 0; i < n; i++) {
        // debug(i, cur_end, next_end);
        if (last[a[i]] > next_end && last[a[i]] > cur_end && last[a[i]] > i) {
            if (cur_end == -1) {
                cur_end = last[a[i]];
                start = i;
            } else {
                next_end = last[a[i]];
            }
        }
        if (i == cur_end) {
            if (next_end == -1) {
                ans += cur_end - start - 1;
                cur_end = -1;
            } else {
                ans += cur_end - start - 2;
                cur_end = next_end;
                next_end = -1;
                start = i - 1;
            }
        }
        // debug (i, a[i], cur_end, next_end, start, ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
