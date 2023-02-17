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
    vector<int> twos(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i == 0) {
            twos[i] = a[i] == 2;
        } else {
            twos[i] = twos[i - 1] + (a[i] == 2);
        }
    }
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
        if (twos[i] == twos[n - 1] - twos[i]) {
            ans = i + 1;
            break;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
