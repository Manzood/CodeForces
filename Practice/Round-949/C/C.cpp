#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int op(int cur) {
    if (cur > 1)
        cur /= 2;
    else
        cur *= 2;
    return cur;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), indices;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > 0) indices.push_back(i);
    }
    if (indices.size()) {
        for (int i = indices[0] - 1; i >= 0; i--) {
            a[i] = op(a[i + 1]);
        }
        for (int i = indices.back() + 1; i < n; i++) {
            a[i] = op(a[i - 1]);
        }
    }
    for (int i = 1; i < (int)indices.size(); i++) {
        // solve between two indices
        int left = indices[i - 1] + 1;
        int right = indices[i] - 1;
        while (left <= right) {
            if (a[left - 1] < a[right + 1]) {
                a[right] = op(a[right + 1]);
                right--;
            } else {
                a[left] = op(a[left - 1]);
                left++;
            }
        }
    }
    if (a[0] == -1) {
        a[0] = 1;
        for (int i = 1; i < n; i++) {
            a[i] = op(a[i - 1]);
        }
    }
    bool found = true;
    for (int i = 0; i < n - 1; i++) {
        if ((a[i + 1] / 2 != a[i]) && (a[i] / 2 != a[i + 1])) {
            found = false;
        }
    }
    if (!found) {
        printf("-1\n");
        return;
    }
    for (auto x : a) {
        printf("%lld ", x);
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
