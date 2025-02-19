#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    char x = '0', y = '1';
    if (n < m) {
        swap(n, m);
        swap(x, y);
    }
    if (n - m > k || n < k) {  // TODO check second condition
        printf("-1\n");
        return;
    }
    string ans;
    while (m >= 0) {
        for (int i = 0; i < min(n, k); i++) {
            ans += x;
        }
        for (int i = 0; i < min(k, m); i++) {
            ans += y;
        }
        n -= k;
        m -= k;
    }
    for (int i = 0; i < n; i++) {
        ans += x;
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
