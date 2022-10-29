#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }
    vector<bool> found(k, false);
    int rem = n * m - 3;
    int searching = k - 1;
    bool ans = true;
    for (int i = 0; i < k; i++) {
        found[a[i] - 1] = true;
        rem--;
        while (searching >= 0 && found[searching]) {
            searching--;
            rem++;
        }
        if (rem == 0 && searching >= 0) {
            ans = false;
        }
    }
    ans ? printf("YA\n") : printf("TIDAK\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
