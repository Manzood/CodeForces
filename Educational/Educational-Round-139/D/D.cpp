#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> primes_list;

void sieve(int n) {
    vector<bool> is_prime;
    is_prime.assign(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        primes_list.push_back(i);
    }
}

void solve([[maybe_unused]] int test) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    int diff = b - a;
    int f = -1;
    int ans = -1;
    for (auto x : primes_list) {
        if (x * x > diff) break;
        if (diff % x == 0) {
            f = x;
            if (ans == -1)
                ans = (f - (a % f)) % f;
            else
                ans = min(ans, (f - (a % f)) % f);
            while (diff % x == 0) diff /= x;
        }
    }
    if (diff > 1) {
        if (ans == -1)
            ans = (diff - (a % diff)) % diff;
        else
            ans = min(ans, (diff - (a % diff)) % diff);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    sieve(3163);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
