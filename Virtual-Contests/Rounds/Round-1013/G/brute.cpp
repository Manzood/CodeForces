#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = 1;
int cnt = 0;

void get(int n, int k, [[maybe_unused]] int test) {
    set<pair<int, int>> found;
    queue<pair<int, int>> q;
    q.push({0, k});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (found.count(cur)) {
            debug(test, ++cnt);
            continue;
        }
        found.insert(cur);
        int pos = cur.first, jump = cur.second;
        if (jump < k - 30 || jump == 1) continue;
        if (pos == n) {
            ans = max(ans, jump);
        }
        if ((k - jump) & 1) {
            if (pos - jump >= 0) {
                q.push({pos - jump, jump});
            }
            if (pos + jump - 1 <= n) {
                q.push({pos + jump - 1, jump - 1});
            }
        } else {
            if (pos + jump <= n) {
                q.push({pos + jump, jump});
            }
            if (pos - jump + 1 >= 0) {
                q.push({pos - jump + 1, jump - 1});
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, k;
    ans = 1;
    cnt = 0;
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
