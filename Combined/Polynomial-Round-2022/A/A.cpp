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
    int ones = s[0] == '1';
    string ans;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            ans += '+';
        } else {
            if (ones & 1) {
                ans += '-';
            } else {
                ans += '+';
            }
            ones++;
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
