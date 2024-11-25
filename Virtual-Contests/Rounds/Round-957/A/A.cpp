#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 5; i++) {
        sort(a.begin(), a.end());
        a[0]++;
    }
    printf("%lld\n", a[0] * a[1] * a[2]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
