#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int64_t> get_prime_factors(int64_t n) {
    vector<int64_t> prime_factors;
    int64_t tmp = n;
    while (tmp % 2 == 0) {
        if (!(int64_t)prime_factors.size()) prime_factors.push_back(2);
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
    return prime_factors;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> p(32);
    int val = 2, tmp = n;
    int cnt = 0;
    while (tmp % val == 0) {
        tmp /= val;
        cnt++;
    }
    for (int i = 1; i <= cnt; i++) {
        p[i].push_back(val);
    }
    for (int i = 3; i * i <= tmp; i += 2) {
        cnt = 0;
        while (tmp % i == 0) {
            tmp /= i;
            cnt++;
        }
        for (int j = 1; j <= cnt; j++) {
            p[j].push_back(i);
        }
    }
    if (tmp > 1) p[1].push_back(tmp);
    int ans = 0;
    for (int i = 1; i < 32; i++) {
        int cur = 1;
        for (auto x : p[i]) cur *= x;
        if (cur > 1) ans += cur;
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
