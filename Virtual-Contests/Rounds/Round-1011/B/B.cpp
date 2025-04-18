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
    vector<int> left(n, 0), right(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        left[i] = a[i] == 0;
        if (i > 0) left[i] += left[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = a[i] == 0;
        if (i < n - 1) right[i] += right[i + 1];
    }
    if (left[n - 1] == 0) {
        printf("%lld\n%lld %lld\n", 1LL, 1LL, n);
        return;
    } else if (left[n - 1] == n) {
        printf("3\n");
        printf("1 2\n");
        printf("2 %lld\n", n - 1);
        printf("1 2\n");
        return;
    }
    vector<pair<int, int>> ops;
    auto add = [&](int l, int r) {
        if (l >= 0 && l < n && r >= 0 && r < n && l < r) ops.push_back({l, r});
    };
    if (left[n - 1] > 1) {
        if (a[0] == 0 && a[n - 1] == 0) {
            add(0, 1);
            add(1, n - 2);
            add(0, 1);
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    if (i != 0) {
                        add(i, n - 1);
                        add(0, i);
                    } else {
                        add(0, n - 2);
                        add(0, 1);
                    }
                    break;
                }
            }
        }
    } else {
        if (a[0] == 0) {
            add(0, 1);
            add(0, n - 2);
        } else {
            add(1, n - 1);
            add(0, 1);
        }
    }
    printf("%lld\n", (int)ops.size());
    for (auto p : ops) {
        printf("%lld %lld\n", p.first + 1, p.second + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
