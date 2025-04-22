#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(int tot, int l, int r) { return tot >= (r - l + 2) / 2; }

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    vector<int> l(n, 0), r(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] = a[i] <= k;
        l[i] = a[i];
        r[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        l[i] += l[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        r[i] += r[i + 1];
    }

    bool possible = false;
    vector<bool> has(n, false);
    for (int i = n - 1; i >= 0; i--) {
        if (check(r[i], i, n - 1)) {
            has[i] = true;
        }
        if (i < n - 1) {
            has[i] = (has[i + 1] || has[i]);
        }
    }

    for (int i = 0; i < n - 2; i++) {
        if (check(l[i], 0, i)) {
            if (has[i + 2]) possible = true;
        }
    }

    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (check(l[i], 0, i)) left.push_back(i);
            if (check(r[i], i, n - 1)) right.push_back(i);
        }
    }
    if ((int)left.size() > 1 || (int)right.size() > 1) possible = true;

    if (possible) {
        printf("YES\n");
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
