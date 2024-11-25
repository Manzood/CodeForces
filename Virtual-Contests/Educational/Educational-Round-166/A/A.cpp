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
    bool found = false, ans = true;
    string digits, letters;
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) {
            found = true;
            letters += s[i];
        } else {
            if (found) {
                ans = false;
            }
            digits += s[i];
        }
    }
    string x = letters, t = digits;
    sort(letters.begin(), letters.end());
    sort(digits.begin(), digits.end());
    if (x != letters || t != digits) {
        ans = false;
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
