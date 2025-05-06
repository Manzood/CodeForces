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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> mx(n, 0);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(a[i], mx[i - 1]);
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        printf("%lld ", sum + mx[i]);
        sum += a[i];
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
