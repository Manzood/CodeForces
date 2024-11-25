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
    vector<int> get_gcd(n, 0);
    vector<bool> left(n, true), right(n, true);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 1) {
            left[i] = left[i - 1];
            left[i] =
                left[i] & (__gcd(a[i], a[i - 1]) >= __gcd(a[i - 1], a[i - 2]));
        }
    }
    for (int i = 0; i < n - 1; i++) get_gcd[i] = __gcd(a[i], a[i + 1]);
    for (int i = n - 3; i >= 0; i--) {
        right[i] = right[i + 1];
        right[i] =
            right[i] & (__gcd(a[i], a[i + 1]) <= __gcd(a[i + 1], a[i + 2]));
    }
    bool ans = false;
    if (n > 3) {
        ans = ans | right[1];
        ans = ans | left[n - 2];
        ans = ans | (right[2] && get_gcd[2] >= __gcd(a[0], a[2]));
        ans =
            ans | (left[n - 3] && get_gcd[n - 4] <= __gcd(a[n - 1], a[n - 3]));
    } else {
        ans = true;
    }
    for (int i = 2; i < n - 2; i++) {
        int cur = __gcd(a[i - 1], a[i + 1]);
        ans = ans | (left[i - 1] && right[i + 1] && get_gcd[i - 2] <= cur &&
                     get_gcd[i + 1] >= cur);
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
