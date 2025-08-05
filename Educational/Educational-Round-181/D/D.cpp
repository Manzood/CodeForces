#include "atcoder/modint"
#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
using namespace atcoder;
#define int long long

constexpr int mod = 998244353;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &m, &n);
    vector<vector<int>> a(m, vector<int>(4));
    int overall = 1;
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        overall *= (1 - ((a[i][2] * inv(a[i][3], mod)) % mod) + mod) % mod;
        overall %= mod;
    }

    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
        return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
    });

    vector<int> prob(n + 1, 0);
    prob[0] = 1;
    for (int i = 0; i < m; i++) {
        int r = a[i][1], l = a[i][0];
        int cur = a[i][2] * inv(a[i][3], mod) % mod;
        int other = (1 - cur + mod) % mod;
        (prob[r] += (((inv(other, mod) * cur) % mod) * prob[l - 1]) % mod) %=
            mod;
    }

    printf("%lld\n", prob[n] * overall % mod);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
