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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == '0' && s[i] == '0') ans += 2;
    }
    for (int i = 2; i < n; i++) {
        if (s[i-2] == '0' && s[i-1] == '1' && s[i] == '0') ans += 1;
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
