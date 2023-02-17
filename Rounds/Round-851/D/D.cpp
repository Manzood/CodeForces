#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

long long power(long long a, long long b, long long m) {
    long long result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result % m;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int dist = a[i] - a[j];
            int left = lower_bound(a.begin(), a.end(), a[j] - dist) - a.begin();
            int right =
                lower_bound(a.begin(), a.end(), a[i] + dist) - a.begin();
            right = n - right;
            ans += power(2, left + right, MOD);
            ans %= MOD;
        }
        for (int j = i + 1; j < n; j++) {
            int dist = a[j] - a[i];
            int left = lower_bound(a.begin(), a.end(), a[i] - dist) - a.begin();
            int right =
                lower_bound(a.begin(), a.end(), a[j] + dist) - a.begin();
            right = n - right;
            ans += power(2, left + right, MOD);
            ans %= MOD;
        }
    }
    (ans *= inv(2, MOD)) %= MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
