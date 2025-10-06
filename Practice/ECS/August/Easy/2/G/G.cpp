#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& a, int val, int m) {
    int n = (int)a.size();
    int smallest = 0;

    for (int i = 0; i < n; i++) {
        int cur = a[i];

        if (cur < smallest) {
            if (cur + val >= smallest) cur = smallest;
        } else {
            if (cur + val >= m && (cur + val) % m >= smallest) cur = smallest;
        }

        if (cur < smallest) return false;
        smallest = cur;
    }

    return true;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int low = 0, high = m, ans = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(a, mid, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
