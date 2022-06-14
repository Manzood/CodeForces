#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a[4];
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < 4; i++) {
        if (a[i] > a[0]) cnt++;
    }
    printf("%lld\n", cnt);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
