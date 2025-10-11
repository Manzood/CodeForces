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
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%lld", &x);
        s.insert(x);
    }
    printf("%lld\n", (int)s.size());
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
