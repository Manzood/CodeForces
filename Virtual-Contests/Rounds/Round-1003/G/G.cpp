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
    is_prime.resize(n + 1), is_prime.assign(n + 1, true);
    primes_list.clear();
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) is_prime[j] = false;
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
    vector<int> cnt(n + 1, 0);
    int primes_cnt = 0;
    int ans = 0;
    vector<int> semi_prime_cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (is_prime[a[i]]) {
            ans += primes_cnt - cnt[a[i]];
            ans += semi_prime_cnt[a[i]];
            primes_cnt++;
        } else {
            for (auto val : primes_list) {
                if (a[i] % val == 0) {
                    int other = a[i] / val;
                    if (is_prime[other]) {
                        if (other == val) {
                            ans += cnt[a[i]];
                            ans += cnt[val];
                            semi_prime_cnt[val]++;
                        } else {
                            ans += cnt[val];
                            ans += cnt[other];
                            ans += cnt[a[i]];
                            semi_prime_cnt[val]++;
                            semi_prime_cnt[other]++;
                        }
                        ans++;
                    }
                    break;
                }
            }
        }
        cnt[a[i]]++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    sieve(N);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
