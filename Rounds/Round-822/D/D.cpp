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
    k--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    // left to right
    bool ans = false;
    int curleft = k - 1;
    int cur = 0, sum = 0, best = 0, lsum = 0;
    for (int i = k; i < n; i++) {
        if (i == n - 1) {
            ans = true;
            break;
        }
        sum += a[i];
        while (curleft >= 0 && a[curleft] + lsum + sum >= 0) {
            lsum += a[curleft--];
            best = max(best, lsum);
        }
        cur = sum + best;
        if (i < n - 1 && cur + a[i + 1] < 0) {
            break;
        }
    }
    // right to left
    int curright = k + 1, rsum = 0;
    cur = 0, sum = 0, best = 0;
    for (int i = k; i >= 0; i--) {
        if (i == 0) {
            ans = true;
            break;
        }
        sum += a[i];
        while (curright < n && a[curright] + rsum + sum >= 0) {
            rsum += a[curright++];
            best = max(best, rsum);
        }
        cur = sum + best;
        if (i > 0 && cur + a[i - 1] < 0) {
            break;
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
