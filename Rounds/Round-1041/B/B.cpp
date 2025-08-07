#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    string s;
    cin >> s;

    x--;
    int lbest = 0, rbest = n - 1;
    for (int i = x; i >= 0; i--) {
        if (s[i] == '#') {
            lbest = i;
            break;
        }
    }
    for (int i = x; i < n; i++) {
        if (s[i] == '#') {
            rbest = i;
            break;
        }
    }

    int rdist = n - rbest;
    int ldist = lbest + 1;
    if (lbest == 0 && s[0] == '.') ldist = 0;
    if (rbest == n - 1 && s[n - 1] == '.') rdist = 0;

    int ans = (int)1e9 + 7;
    if (x == 0 || x == n - 1)
        ans = 1;
    else {
        if (s[x - 1] == '#' || s[x + 1] == '#') {
            ans = min(x + 1, n - x);
        } else {
            ans = max(ldist + 1, rdist + 1);
            ans = min(ans, min(x + 1, n - x));
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
