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
    map<char, int> mp;
    bool possible = false;
    for (int i = 0; i < n; i++) {
        if (mp.count(s[i])) {
            if (i < n - 1) {
                possible = true;
            } else {
                if (mp[s[i]] > 0) possible = true;
            }
        }
        mp[s[i]] = i;
    }

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
