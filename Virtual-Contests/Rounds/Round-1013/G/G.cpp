#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = 1;

void get(int n, int k, [[maybe_unused]] int test) {
    set<pair<int, int>> found;
    queue<pair<int, int>> q;
    for (int i = 0; i <= n; i += k) {
        q.push({i, k});
    }
    while (!q.empty()) {
        queue<pair<int, int>> prev = q;
        q = queue<pair<int, int>>();
        while (!prev.empty()) {
            pair<int, int> val = prev.front();
            prev.pop();
            if (val.first < 0 || val.first > n) continue;
            if (val.second == 1 || val.second < ans) return;
            if ((k - val.second) & 1) {
                if (val.first > val.second * val.second) {
                    ans = val.second - 1;
                    return;
                }
                for (int i = val.first + val.second - 1; i <= n;
                     i += val.second - 1) {
                    if (found.count({i, val.second - 1})) break;
                    q.push({i, val.second - 1});
                    found.insert({i, val.second - 1});
                }
            } else {
                if ((n - val.first) % val.second == 0) {
                    ans = val.second;
                    return;
                }
                if ((n - val.first) > val.second * val.second) {
                    ans = val.second - 2;
                }
                for (int i = val.first - val.second + 1; i >= 0;
                     i -= val.second - 1) {
                    if (found.count({i, val.second - 1})) break;
                    q.push({i, val.second - 1});
                    found.insert({i, val.second - 1});
                }
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, k;
    ans = 1;
    scanf("%lld%lld", &n, &k);

    if (n % k == 0) {
        printf("%lld\n", k);
        return;
    }
    if (n > k * k) {
        printf("%lld\n", max(k - 2, 1LL));
        return;
    }

    get(n, k, test);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
