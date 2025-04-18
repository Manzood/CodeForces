#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    int ans = 0, possible = true;
    for (int i = 0; i < 50; i++) {
        int val = (1LL << i);
        if ((x & val) && (y & val)) {
            if (i == 49) {
                possible = false;
                break;
            }
            bool found = false;
            int ind = 0;
            for (int j = i - 1; j >= 0; j--) {
                int other = (1LL << j);
                if ((x & other) != (y & other)) {
                    found = true;
                    ind = j;
                    break;
                }
            }
            if (!found) {
                ans += (1LL << i);
                x += (1LL << i);
                y += (1LL << i);
            } else {
                for (int j = ind; j < i; j++) {
                    ans += (1LL << j);
                    x += (1LL << j);
                    y += (1LL << j);
                    // if (test == 5) debug("here", i, ans);
                }
            }
        }
    }
    if (!possible) {
        printf("-1\n");
        return;
    }
    assert((x + y) == (x ^ y));
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

// 100100100100100100100
// 010010010010010010100
// 000000000000000011100
