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
    bool other = true;
    if (s[0] == '9') other = false;
    string ans;
    if (other) {
        for (int i = 0; i < n; i++) {
            int val = s[i] - '0';
            val = 9 - val;
            ans += (char) val + '0';
        }
    } else {
        int prev = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] + prev > '1') {
                int val = 11 - (s[i] - '0' + prev);
                ans += (char) val + '0';
                prev = 1;
            } else {
                int val = 1 - (s[i] - '0' + prev);
                ans += (char) val + '0';
                prev = 0;
            }
        }
        reverse(ans.begin(), ans.end());
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
