#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    vector<int> lower(26, 0), upper(26, 0);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            lower[s[i] - 'a']++;
        } else {
            upper[s[i] - 'A']++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += min(lower[i], upper[i]);
        int diff = abs(lower[i] - upper[i]);
        int val = min(diff / 2, k);
        ans += val;
        k -= val;
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
