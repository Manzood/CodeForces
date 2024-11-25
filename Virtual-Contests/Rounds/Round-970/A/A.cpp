#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    swap(a, b);
    bool ans = true;
    if ((a & 1) && b < 2) {
        ans = false;
    }
    if (b & 1) ans = false;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
