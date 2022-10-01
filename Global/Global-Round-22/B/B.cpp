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
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &s[i]);
    }
    int diff = (int)1e18 + 7;
    bool possible = true;
    for (int i = k - 2; i >= 0; i--) {
        int cur = s[i + 1] - s[i];
        if (diff < cur) possible = false;
        diff = min(diff, cur);
    }
    if (s[0] > diff * (n - k + 1)) possible = false;
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
