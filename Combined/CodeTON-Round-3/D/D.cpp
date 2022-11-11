#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

namespace number_theory {

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

// gets the number of prime factors of each element in the vector
void count_prime_factors(vector<int>& prime_factors) {
    int n = (int)prime_factors.size();
    prime_factors.assign(n, 0);
    for (int i = 2; i <= n; i++) {
        if (prime_factors[i] == 0) {
            for (int j = i; j <= n; j += i) {
                prime_factors[j]++;
            }
        }
    }
}

// gets the number of divisors for each element upto n
void get_divisors(vector<int>& divisors) {
    int n = (int)divisors.size();
    divisors.assign(n, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }
}

// returns the number of integers coprime to n until m using PIE
// time complexity: O((2 ** (k) * k) where k -> number of prime factors of n)
int64_t coprime(int64_t n, int64_t m) {
    vector<int> prime_factors;
    int tmp = n;
    while (tmp % 2 == 0) {
        if (!(int)prime_factors.size()) prime_factors.push_back(2);
        tmp /= 2;
    }
    for (int j = 3; j * j <= tmp; j += 2) {
        while (tmp % j == 0) {
            if (!(int)prime_factors.size() || prime_factors.back() != j)
                prime_factors.push_back(j);
            tmp /= j;
        }
    }
    if (tmp > 1) prime_factors.push_back(tmp);
    // using PIE
    int len = (int)prime_factors.size();
    int64_t num = (1LL << len);
    int64_t common = 0;
    for (int j = 1; j < num; j++) {
        int cnt = __builtin_popcountll(j);
        tmp = cnt & 1 ? 1 : -1;
        int prod = 1;
        for (int k = 0; k < (int)prime_factors.size(); k++) {
            if ((1LL << k) & j) {
                prod *= prime_factors[k];
            }
        }
        common += (m / prod) * tmp;
        common %= mod;
    }
    return m - common;
}
}  // namespace number_theory

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i] != 0) {
            ans = 0;
            break;
        }
        if (a[i] == a[i - 1]) {
            // any multiple of a[i]
            ans *= (m / a[i]) % mod;
            ans %= mod;
        } else {
            int x = a[i - 1] / a[i];
            int fin = number_theory::coprime(x, m / a[i]);
            fin %= mod;
            ans *= fin;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
