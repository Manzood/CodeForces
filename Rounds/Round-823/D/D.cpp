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
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26, 0);
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    for (auto c : t) {
        cnt[c - 'a']++;
    }
    bool possible = true;
    for (auto x : cnt) {
        if (x & 1) possible = false;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 2) {
            // check if they're either in the same string, or not at the same
            // distance in opposite strings
            bool same = false;
            char c = 'a' + (char)i;
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == c) cnt1++;
                if (t[j] == c) cnt2++;
            }
            if (cnt1 == 2 || cnt2 == 2) same = true;
            if (!same) {
                for (int j = 0; j < n; j++) {
                    if (s[j] == c) {
                        if (t[n - j - 1] == c && (n - j - 1 != j)) {
                            possible = false;
                        }
                    }
                }
            }
        }
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
