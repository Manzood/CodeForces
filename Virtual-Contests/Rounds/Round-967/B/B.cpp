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
    if ((n & 1) == 0) {
        printf("-1\n");
        return;
    }
    vector<int> a(n);
    int val = 2;
    for (int i = n / 2 + 1; i < n; i++) {
        a[i] = val;
        val += 2;
    }
    val = 1;
    for (int i = n / 2; i >= 0; i--) {
        a[i] = val;
        val += 2;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
