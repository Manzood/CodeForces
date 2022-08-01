#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string t;
    cin >> t;
    int len = t.size();
    int n;
    scanf("%lld", &n);
    vector<string> s(n);
    vector<int> from(len, len);
    vector<int> which(len, -1);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            int tlen = s[j].size();
            string copy = t.substr(i, tlen);
            if (copy == s[j]) {
                bool required = false;
                for (int k = 0; k < tlen; k++) {
                    if (from[i + k] == len) {
                        // important change
                        required = true;
                    }
                }
                for (int k = 0; k < tlen && required; k++) {
                    // from[i + k] = min(from[i + k], i);
                    if (i <= from[i + k]) {
                        from[i + k] = i;
                        which[i + k] = j;
                    }
                }
            }
        }
    }
    bool possible = true;
    set<int> val;
    for (int i = 0; i < len; i++) {
        if (from[i] == len) possible = false;
        val.insert(from[i]);
    }
    debug(from, which);
    int ans = val.size();
    if (!possible) ans = -1;
    printf("%lld\n", ans);
    if (possible) {
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                if (from[i] != from[i - 1]) {
                    printf("%lld %lld\n", which[i] + 1, from[i] + 1);
                }
            } else {
                printf("%lld %lld\n", which[i] + 1, i + 1);
            }
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
