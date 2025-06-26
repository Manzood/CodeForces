#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 6;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if (a[0] < a[1]) {
        swap(a[0], a[1]);
        swap(a[2], a[3]);
        swap(a[4], a[5]);
    }

    bool possible = false;
    if (a[0] == a[2] + a[4] && a[3] == a[5] && a[1] + a[3] == a[0])
        possible = true;
    if (a[0] == a[2] && a[0] == a[4] && a[1] + a[3] + a[5] == a[0])
        possible = true;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
