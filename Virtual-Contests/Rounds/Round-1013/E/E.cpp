#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> primes_list;
vector<bool> is_prime;

const int N = (int)1e7 + 5;

void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    primes_list.clear();
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
    int n;
    scanf("%lld", &n);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            ans += n / i;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    sieve(N);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
