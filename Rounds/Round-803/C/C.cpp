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
    vector <int> a(n);
    set <int> nums;
    int nonzeroes = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != 0) nonzeroes++;
        nums.insert(a[i]);
    }
    bool ans = false;
    if (n == 3) {
        if (nums.count(a[0] + a[1] + a[2])) {
            ans = true;
        }
    } else {
        if (nonzeroes <= 1) ans = true;
        if (nonzeroes == 2) {
            int sum = 0;
            for (auto x: nums) {
                sum += x;
            }
            if (sum == 0) {
                ans = true;
            }
        } else if (nonzeroes == 4 && n == 4) {
            sort (a.begin(), a.end());
            if (a[0] == -a[3] && a[1] == -a[2]) ans = true;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
