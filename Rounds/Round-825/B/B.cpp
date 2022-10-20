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
    bool ans = true;
    vector<int> b(n + 1);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = a[i - 1] * a[i];
        b[i] /= __gcd(a[i], a[i - 1]);
    }
    b[n] = a[n - 1];
    for (int i = 1; i < n; i++) {
        int val = __gcd(b[i], b[i - 1]);
        if (val != a[i - 1]) ans = false;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
