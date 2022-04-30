#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int b[3], c[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &c[i]);
    }
    int val = c[1] / b[1];
    int ans = 0;
    int bright = b[0] + (b[2] - 1) * b[1];
    int cright = c[0] + (c[2] - 1) * c[1];
    bool possible = true;
    if ((c[0] - b[0]) % b[1] != 0) possible = false;
    if (c[1] % b[1] != 0) possible = false;
    if (c[0] < b[0] || cright > bright) possible = false;
    if (possible && (c[0] - c[1] < b[0] || cright + c[1] > bright)) {
        ans = -1;
    }
    int diff = val;
    if (ans != -1) {
        if (val > 1 && possible) {
            ans = 1;
            while (val < c[1] && val % b[1] != 0) {
                if (c[1] % val == 0) ans += (c[1] / val) * (c[1] / val);
                val += diff;
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
