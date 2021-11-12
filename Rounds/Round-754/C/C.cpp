#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        // int len = 0;
        // int acount = 0, bcount = 0, ccount = 0;
        int ans = 1e9+7;
        string s2 = "aa";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "aba";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "aca";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "abca";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "acba";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "abbacca";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        s2 = "accabba";
        for (int i = 0; i < n; i++) {
            bool found = true;
            bool entered = false;
            for (int j = 0; j < (int) s2.size() && i + (int)s2.size() - 1 < n; j++) {
                entered = true;
                if (s[i + j] != s2[j]) {
                    found = false;
                }
            }
            if (!entered) found = false;
            if (found) {
                ans = min (ans, (int) s2.size());
            }
        }
        if (ans == (int) 1e9 + 7) {
            ans = -1;
        }
        printf("%lld\n", ans);
    }
}
