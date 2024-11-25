#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool get(int n, int m) {
    if (n == m) return true;
    if (n % 3 != 0) return false;
    return get(n / 3, m) || get(n * 2 / 3, m);
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    bool ans = get(n, m);
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
