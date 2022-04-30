#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i] - 'a' + 1;
    }
    int mi = s[0] - 'a' + 1;
    mi = min(mi, (int) s[n - 1] - 'a' + 1);
    if (n & 1) ans -= 2 * mi;
    if (ans < 0) {
        printf("Bob ");
    } else {
        printf("Alice ");
    }
    ans = abs(ans);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
