#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(int val, int req, vector<int>& a) {
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] >= val) cnt++;
    }
    return cnt >= req;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    int tot = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        tot += b[i];

        int low = 1, high = (int)1e9 + 7;
        int best = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid, tot, a)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (best == 0) break;
        ans = max(ans, best * (i + 1));
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
