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

const int N = (int)1e6 + 5;

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
    // greedy
    int n;
    scanf("%lld", &n);
    int p = n / 3;
    while (!is_prime[p]) p++;
    vector<int> a, used(n + 1, false);
    a.push_back(p);
    used[p] = true;
    for (int i = 1; i < n / 3 - 1; i++) {
        int val = (i + 1) / 2;
        if (i & 1) {
            a.push_back(p - val);
            used[p - val] = true;
        } else {
            a.push_back(p + val);
            used[p + val] = true;
        }
    }
    int rem = n - (int)a.size();
    int cur = 1;
    for (int i = 0; i < rem; i++) {
        while (used[cur]) cur++;
        a.push_back(cur++);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    sieve(N);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
