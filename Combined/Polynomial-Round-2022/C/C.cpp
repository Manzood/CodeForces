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
    int ans = 1;
    printf("%lld ", ans);
    int cnt = 3;
    int sub = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i - 1]) {
            sub = 1;
        } else {
            sub++;
        }
        ans = cnt - sub;
        printf("%lld ", ans);
        cnt++;
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
