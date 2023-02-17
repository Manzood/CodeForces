#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, c;
    scanf("%lld%lld", &n, &c);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] += i + 1;
    }
    sort(a.begin(), a.end());
    if (test == 1) debug(a);
    int ans = 0;
    int ptr = 0;
    while (ptr < n && c >= a[ptr]) {
        c -= a[ptr++];
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
