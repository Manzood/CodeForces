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
    }

    sort(a.begin(), a.end());
    int ptr = -1;
    while (ptr < n - 1 && a[ptr + 1] <= c) {
        ptr++;
    }

    int mult = 1;
    int cnt = 0;
    while (ptr >= 0) {
        while (ptr >= 0 && a[ptr] * mult > c) ptr--;
        if (ptr < 0) break;
        cnt++;
        mult *= 2;
        ptr--;
    }

    int ans = n - cnt;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
