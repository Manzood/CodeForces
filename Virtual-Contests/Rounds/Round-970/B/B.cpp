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
    string s;
    cin >> s;
    int val = 1;
    while (val * val <= n) {
        val++;
    }
    val--;
    bool ans = (val * val) == n;
    debug(n, val);
    if (ans) {
        for (int i = 0; i < val; i++) {
            string cur;
            if (i == 0 || i == val - 1) {
                for (int j = 0; j < val; j++) {
                    cur += '1';
                }
            } else {
                cur += '1';
                for (int j = 0; j < val - 2; j++) {
                    cur += '0';
                }
                cur += '1';
            }
            if (s.substr(i * val, val) != cur) ans = false;
        }
    }
    ans ? printf("Yes\n") : printf("No\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
