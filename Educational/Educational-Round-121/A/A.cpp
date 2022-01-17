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
    map <char, int> cnt;
    for (int i = 0; i < (int) s.size(); i++) {
        cnt[s[i]]++;
    }
    string repeat;
    string other;
    for (auto x: cnt) {
        if (x.second == 2) {
            repeat.push_back (x.first);
        } else {
            other.push_back (x.first);
        }
    }
    string ans = repeat + other + repeat;
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
