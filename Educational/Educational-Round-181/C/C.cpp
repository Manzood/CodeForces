#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int prod = 2 * 3 * 5 * 7;
    int cnt = 0;
    for (int i = prod; i < 2 * prod; i++) {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            continue;
        }
        cnt++;
    }

    int cur = l, ans = 0;
    while (cur <= r && cur % cnt != 0) {
        if (!(cur % 2 == 0 || cur % 3 == 0 || cur % 5 == 0 || cur % 7 == 0)) {
            ans++;
        }
        cur++;
    }

    if (cur > r) {
        printf("%lld\n", ans);
        return;
    }

    int val = (r - cur + 1) / prod;
    ans += val * cnt;

    cur += val * prod;
    while (cur <= r) {
        if (!(cur % 2 == 0 || cur % 3 == 0 || cur % 5 == 0 || cur % 7 == 0)) {
            ans++;
        }
        cur++;
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
