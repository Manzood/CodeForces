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
    // go upto 2 * k
    int ans = 1;
    if (n % k == 0) ans = k;
    int jump = k;
    set<int> start = {0};
    while (jump > 1 && ans == 1) {
        set<int> other;
        for (auto cur : start) {
            if ((n - cur) % jump == 0) {
                ans = max(ans, jump);
            }
            int val = (n - cur) / jump;
            for (int i = 1; i <= val && i <= k; i++) {
                other.insert((cur + i) % k);
            }
            if (jump == 5) debug(other);
        }
        for (auto cur : other) {
            if (cur - jump + 1 >= 0) other.insert(cur - jump + 1);
        }
        if (jump == 5) debug(other);
        start = other;
        jump -= 2;
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
