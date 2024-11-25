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
    string s = "aeiou";
    string ans;
    int extra = n % 5;
    int cnt = n / 5;
    for (int i = 0; i < 5; i++) {
        int tot = cnt + (i < extra);
        for (int j = 0; j < tot; j++) {
            ans += s[i];
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
