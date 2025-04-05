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
    if (!(n & 1)) {
        printf("-1\n");
        return;
    }
    vector<int> a;
    int cur = 1;
    while (cur <= n) {
        a.push_back(cur);
        cur += 2;
    }
    cur = 2;
    while (cur < n) {
        a.push_back(cur);
        cur += 2;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
