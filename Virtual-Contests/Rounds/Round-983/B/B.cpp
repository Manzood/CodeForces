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
    int median = n / 2 + 1;
    if (n > 1 && (k == 1 || k == n)) {
        printf("-1\n");
        return;
    }
    vector<int> ans;
    ans.push_back(1);
    if (k >= median) {
        int diff = k - median;
        int left = 2 + 2 * diff;
        while (left <= n) {
            ans.push_back(left);
            left++;
        }
    } else {
        int diff = median - k;
        int left = 2;
        while (left <= n - 2 * diff) {
            ans.push_back(left);
            left++;
        }
    }
    assert((int)ans.size() & 1);
    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld ", ans[i]);
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
