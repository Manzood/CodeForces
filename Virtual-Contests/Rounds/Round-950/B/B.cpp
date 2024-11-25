#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, f, k;
    scanf("%lld%lld%lld", &n, &f, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int val = a[f - 1];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (a[k - 1] > val) {
        printf("NO\n");
    } else if (a[k - 1] == val && (k < n && a[k] == val)) {
        printf("MAYBE\n");
    } else {
        printf("YES\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
