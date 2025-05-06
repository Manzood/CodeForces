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
vector<int> primespref;

const int N = (int)7e6;

void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    primes_list.clear();
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        primes_list.push_back(i);
    }

    primespref.assign((int)primes_list.size(), 2);
    for (int i = 1; i < (int)primes_list.size() - 1; i++) {
        primespref[i] = primespref[i - 1] + primes_list[i];
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    sort(a.begin(), a.end());
    int ans = n - 1;
    if (sum >= primespref[n - 1]) ans = 0;

    for (int i = 0; i < n - 1; i++) {
        sum -= a[i];
        if (sum >= primespref[n - i - 2]) {
            ans = min(ans, i + 1);
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
