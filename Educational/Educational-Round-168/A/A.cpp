#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int found = -1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) {
            found = i;
            break;
        }
    }
    string ans;
    if (found == -1) {
        ans = s;
        if (ans.back() == 'a')
            ans += 'b';
        else
            ans += 'a';
    } else {
        ans = s.substr(0, found);
        if (ans.back() == 'a')
            ans += 'b';
        else
            ans += 'a';
        ans += s.substr(found, (int)s.size() - found);
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
