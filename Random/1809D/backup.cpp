#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mult = (int)1e12 + 1;

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        z += s[i] == '0';
        o += s[i] == '1';
    }
    int lo = 0, lz = 0;
    int ans = mult * z;
    for (int i = 0; i < n; i++) {
        lz += s[i] == '0';
        lo += s[i] == '1';
        int rz = z - lz;
        if (i < n - 1 && s[i] == '1' && s[i + 1] == '0')
            ans = min(ans, mult - 1 + (mult * (lo + rz - 2)));
        ans = min(ans, (lo + rz) * mult);
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
