#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    if (k == 0) {
        printf("0\n");
        return;
    }
    int ans = 1;
    k -= n;
    int turn = 1;
    while (k > 0) {
        if (turn & 1) {
            n--;
        }
        k -= n;
        ans++;
        turn++;
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
