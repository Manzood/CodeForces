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
    string a, b;
    cin >> a >> b;
    vector<string> f = {"x.x", "..."};
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if ((a.substr(i, 3) == f[0] && b.substr(i, 3) == f[1]) ||
            (a.substr(i, 3) == f[1] && b.substr(i, 3) == f[0]))
            ans++;
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
