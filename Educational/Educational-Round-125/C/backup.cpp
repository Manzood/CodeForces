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
    int rbs = -1;
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            val++;
        } else {
            val--;
        }
        if (val < 0) break;
        else if (val == 0) rbs = i;
    }
    int pal = -1;
    char p = s[0];
    for (int i = 0; i < n; i++) {
        if (i == pal + 1) {
            p = s[i];
        } else {
            if (s[i] == p) {
                pal = i;
            }
        }
    }
    int len = max(rbs, pal);
    int ans = n - 1 - len;
    int ops = 0;
    if (ans < n) ops = 1;
    printf("%lld %lld\n", ops, ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
