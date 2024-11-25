#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 10;
    string s;
    cin >> s;
    string t = "codeforces";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ans++;
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
