#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
    }
    string s;
    cin >> s;
    vector<bool> vis(n, false);
    set<int> cur;
    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cur.clear();
            int x = i;
            int cnt = 0;
            while (!vis[x]) {
                vis[x] = true;
                cur.insert(x);
                cnt += s[x] == '0';
                x = a[x];
            }
            for (auto y : cur) {
                f[y] = cnt;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", f[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
