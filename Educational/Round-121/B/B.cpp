#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    string s;
    cin >> s;
    string ans;
    bool found = false;
    int n = s.size();
    int ind = -1;
    for (int i = 1; i < n; i++) {
        int val = s[i] - '0' + s[i-1] - '0';
        if (val >= 10) {
            ind = i;
            found = true;
        }
    }
    if (found) {
        int i = ind;
        int val = s[i] - '0' + s[i-1] - '0';
        ans += s.substr(0, i - 1);
        int temp = val % 10;
        ans += (char) val / 10 + '0';
        ans += (char) temp + '0';
        ans += s.substr(i + 1, (n - i));
    } else {
        // debug (s[0] - '0' + s[1] - '0');
        ans += s[0] + s[1] - '0';
        ans += s.substr(2, n - 2);
    }
    // debug (ans);
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
