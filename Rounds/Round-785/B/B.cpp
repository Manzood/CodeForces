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
    int n = s.size();
    vector <int> occurances(26, 0);
    vector <bool> present(26, false);
    for (int i = 0; i < n; i++) {
        occurances[s[i] - 'a']++;
        present[s[i] - 'a'] = true;
    }
    int f = 0, b = n - 1;
    bool ans = true;
    while (f <= b) {
        int mi = (int) 1e9 + 7;
        int mx = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) mi = min(mi, occurances[i]);
            mx = max(mx, occurances[i]);
        }
        if (abs(mi - mx) > 1) ans = false;
        if (mi < mx && (occurances[s[f] - 'a'] == mi || occurances[s[b] - 'a'] == mi)) ans = false;
        occurances[s[f] - 'a']--;
        occurances[s[b] - 'a']--;
        f++;
        b--;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
