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
    vector<pair<bool, bool>> a(26);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (i & 1) {
            a[c].second = true;
        } else {
            a[c].first = true;
        }
    }
    bool ans = true;
    for (int i = 0; i < 26; i++) {
        if (a[i].first && a[i].second) ans = false;
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
