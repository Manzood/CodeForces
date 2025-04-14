#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = (int)1e5 + 5;

vector<vector<int>> divisors(N);
void precompute() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

vector<vector<int>> occ(N);
void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]].push_back(i);
    }

    for (int query = 1; query <= q; query++) {
        int k, l, r;
        scanf("%lld%lld%lld", &k, &l, &r);
        l--, r--;

        set<int> pos;
        for (auto d : divisors[k]) {
            if (occ[d].size()) {
                int ind = lower_bound(occ[d].begin(), occ[d].end(), l) -
                          occ[d].begin();
                if (ind == (int)occ[d].size() || occ[d][ind] > r) continue;
                pos.insert(occ[d][ind]);
            }
        }

        int last = l - 1;
        int ans = 0;
        for (auto x : pos) {
            ans += k * (x - 1 - last);
            last = x - 1;
            while (k > 1 && k % a[x] == 0) {
                k /= a[x];
            }
        }
        ans += k * (r - last);

        printf("%lld\n", ans);
    }
    for (int x : a) occ[x].clear();
}

int32_t main() {
    int t = 1;
    cin >> t;

    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
