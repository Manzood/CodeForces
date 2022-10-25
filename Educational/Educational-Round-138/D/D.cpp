#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

vector<bool> prime;
void SieveOfEratosthenes(int n) {
    prime.assign(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> ans(n, 1);
    vector<int> cnt(n, 1);
    vector<int> pref(n, 1);
    for (int i = 0; i < n; i++) {
        if (i > 0) ans[i] = ans[i - 1];
        ans[i] = (ans[i] * (m % mod)) % mod;
        pref[i] = ans[i];
    }
    int prod = 1;
    int fin = 0;
    cnt[0] = m % mod;
    for (int i = 1; i < n; i++) {
        if (prod <= m) {
            if (prime[i + 1]) {
                prod *= (i + 1);
            }
        }
        cnt[i] = (cnt[i - 1] * ((m / prod) % mod)) % mod;
    }
    for (int i = 0; i < n; i++) {
        int val = ans[i] - cnt[i];
        if (val < 0) val += mod;
        fin = (fin + val) % mod;
    }
    printf("%lld\n", fin);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    SieveOfEratosthenes((int)3e5 + 7);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
