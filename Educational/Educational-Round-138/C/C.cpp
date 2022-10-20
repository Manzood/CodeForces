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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        // alice picks the first from end
        int cur = k;
        int left = 0;
        int right = n - 1;
        int moves = 0;
        while (cur > 0) {
            while (right >= left && a[right] > cur) {
                right--;
            }
            if (right < left) break;
            moves++;
            cur--;
            right--;
            left++;
        }
        if (moves >= k) {
            ans = k;
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
