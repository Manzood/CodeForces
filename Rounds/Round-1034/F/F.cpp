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
    int n;
    scanf("%lld", &n);
    vector<int> prev(n + 1, -1);
    vector<bool> taken(n + 1, false);
    for (int i = 2; i <= n; i++) {
        bool found = false;
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            if (!taken[j]) {
                found = true;
                prev[j] = i;
                taken[j] = true;
            }
        }

        if (!found) {
            if (i * 2 <= n) {
                prev[i * 2] = i;
            }
        }
    }

    vector<vector<int>> chains(n + 1);
    for (int i = 0; i < n + 1; i++) {
        if (prev[i] != -1) {
            chains[prev[i]].push_back(i);
        }
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);

    for (int i = 0; i < n + 1; i++) {
        if (chains[i].size()) {
            vector<int> cur = {i};
            for (auto x : chains[i]) cur.push_back(x);

            for (int j = 0; j < (int)cur.size() - 1; j++) {
                perm[cur[j] - 1] = cur[j + 1];
            }
            perm[cur.back() - 1] = cur[0];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", perm[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    sieve(N);

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
