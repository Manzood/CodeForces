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
    bool found = false;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (!found && s[i] == 'R') {
            found = true;
            r = i;
        }
        if (s[i] == 'L') l = i;
    }
    int ans = 0;
    if (r > l) {
        ans = r;
    }
    if (l == -1 || r == -1) {
        ans = -1;
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
