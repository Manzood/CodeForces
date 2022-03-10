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
    vector <int> ans(n);
    ans[0] = 1;
    bool possible = true;
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i-1] * 3;
        if (ans[i] > (int) 1e9) {
            possible = false;
            break;
        }
    }
    if (possible) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
