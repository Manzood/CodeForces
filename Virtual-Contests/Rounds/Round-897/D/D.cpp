#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    bool possible = true, found = false;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) possible = false;
        }
        printf(possible ? "YES\n" : "NO\n");
        return;
    }

    vector<bool> vis(n, false), done(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = a[cur] - 1;
            }

            int l = 1;
            int st = cur;
            cur = a[cur] - 1;
            while (cur != st) {
                l++;
                cur = a[cur] - 1;
            }

            if (l > k)
                possible = false;
            else if (l == k)
                found = true;
            else if (l == 1)
                possible = false;
        }
    }
    if (!found) possible = false;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
