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
    int a = 1, b = n;
    vector<int> out(n);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (i & 1) {
                out[j] = b--;
            } else {
                out[j] = a++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", out[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
