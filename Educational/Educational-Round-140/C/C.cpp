#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(n));
    bool possible = true;
    int rightmost1 = -1;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n - i; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 2) found = true;
            if (a[i][j] == 1 && found) possible = false;
            if (j == 0 && a[i][j] == 2) possible = false;
            if (a[i][j] == 1) {
                rightmost1 = max(rightmost1, i + j);
            } else if (a[i][j] == 2) {
                if (rightmost1 >= i + j) {
                    possible = false;
                }
            }
        }
    }
    int ans = 1;
    vector<int> same(n, -1);
    vector<int> index(n, -1);
    for (int i = 0; i < n; i++) {
        same[i] = i;
    }
    int sub = 0;
    for (int i = 0; i < n; i++) {
        bool found_two = false;
        for (int j = 0; j < n - i; j++) {
            if (a[i][j] == 1) {
                for (int k = i + j; k >= i; k--) {
                    same[k] = i + j;
                }
            } else if (a[i][j] == 2 && !found_two) {
                found_two = true;
                index[i + j] = max(index[i + j], i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (index[i] > -1) {
            int components = 0;
            int highest = -1;
            for (int j = i; j < n; j++) {
                int cur = j;
                while (same[cur] != cur) {
                    cur = same[cur];
                }
                if (cur > highest) components++;
                highest = max(highest, cur);
            }
            int rem = components;
            int val = 1;
            while (rem--) {
                val = (val * 2) % mod;
            }
            sub = (sub + val) % mod;
        }
    }
    int components = 0;
    int highest = -1;
    for (int i = 0; i < n; i++) {
        int cur = i;
        while (same[cur] != cur) {
            cur = same[cur];
        }
        if (cur > highest) components++;
        highest = max(highest, cur);
    }
    while (components--) ans = (ans * 2) % mod;
    ans -= sub;
    if (ans < 0) ans += mod;
    if (!possible) ans = 0;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
