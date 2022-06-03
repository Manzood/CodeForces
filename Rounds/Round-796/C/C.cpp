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
    vector <string> t(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> t[i];
    string s; cin >> s;
    vector <int> cnt(26, 0);
    for (int i = 0; i < 2 * n; i++) {
        for (auto x: t[i]) cnt[x - 'a']++;
    }
    for (auto x: s) cnt[x - 'a']++;
    char ans = 'a';
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) ans = 'a' + (char) i;
    }
    printf("%c\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
