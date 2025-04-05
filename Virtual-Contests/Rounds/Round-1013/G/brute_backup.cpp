#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = 1;

set<vector<int>> found;
queue<int> q;
void get(int x, int n, int jump, int dir) {
    if (x > n || x < 0) return;
    if (x == n) {
        ans = max(ans, jump);
        return;
    }
    if (found.count({x, jump, dir})) return;
    found.insert({x, jump, dir});
    if (dir == 1) {
        get(x + jump, n, jump, dir);
        get(x - jump + 1, n, jump - 1, !dir);
    } else {
        get(x + jump - 1, n, jump - 1, !dir);
        get(x - jump, n, jump, dir);
    }
}

void solve([[maybe_unused]] int test) {
    int n, k;
    found.clear();
    q = queue<int>();
    ans = 1;
    scanf("%lld%lld", &n, &k);
    if (n % k == 0) {
        printf("%lld\n", k);
        return;
    }
    if (n > k * k) {
        printf("%lld\n", k - 2);
        return;
    }
    get(0, n, k, 1);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
