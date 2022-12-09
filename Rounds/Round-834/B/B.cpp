#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s;
    scanf("%lld%lld", &n, &s);
    vector<int> a(n);
    int sum = 0;
    vector<bool> found(50, false);
    int largest = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        found[a[i] - 1] = true;
        largest = max(a[i], largest);
    }
    int rem = 0;
    for (int i = 0; i < largest; i++) {
        if (!found[i]) {
            rem += i + 1;
        }
    }
    while (rem < s) {
        // sum += largest + 1;
        rem += largest++ + 1;
    }
    rem == s ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
