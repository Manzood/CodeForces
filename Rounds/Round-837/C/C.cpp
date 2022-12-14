#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

vector<int> primes_list;

void sieve(int n) {
    vector<bool> is_prime;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    // get prime_factors
    map<int, int> p;
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        for (auto x : primes_list) {
            if (x * x > a[i]) break;
            if (a[i] % x == 0) {
                if (p.count(x)) ans = true;
                p[x]++;
                while (a[i] % x == 0) a[i] /= x;
            }
        }
        if (a[i] > 1) {
            if (p.count(a[i])) ans = true;
            p[a[i]]++;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    sieve(31623);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
