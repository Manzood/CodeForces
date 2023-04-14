#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;
// constexpr int MX = (int)1e6 + 7;
constexpr int MX = 8;

vector<int> is_prime;
void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
}

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> fact(2 * n + 1, 1);
    for (int i = 2; i <= 2 * n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    vector<int> occ(MX, 0);
    int primes_count = 0;
    for (int i = 0; i < 2 * n; i++) {
        occ[a[i]]++;
        if (is_prime[a[i]] && occ[a[i]] == 1) primes_count++;
    }
    if (primes_count < n) {
        printf("0\n");
        return;
    }
    int ans = (fact[primes_count] * inv(fact[primes_count - n], MOD)) % MOD;
    for (int i = 0; i < 2 * n; i++) {
        if (is_prime[a[i]]) {
            int val = fact[primes_count - 1];
            (val *= inv(fact[n - 1], MOD)) %= MOD;
            (val *= inv(fact[primes_count - n], MOD)) %= MOD;
            (val *= fact[occ[a[i] - 1]]) %= MOD;
            ans *= inv(val, MOD);
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    sieve(MX);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
