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
    int cnt = 0, ans = 0;
    int ptr = n - 1;
    bool zeroes = true;
    vector<bool> used(n, false);
    for (int i = n - 1; i >= 0; i--) {
        while (ptr >= i) ptr--;
        while (zeroes && ptr >= 0 && s[ptr] != '0') ptr--;
        if (ptr < 0) zeroes = false;
        if (s[i] == '1' && cnt < n / 2) {
            if (zeroes) {
                ptr--;
                cnt++;
            } else {
                while (ptr < 0) ptr++;
                while (ptr < i && (used[ptr] == true || s[ptr] == '0')) ptr++;
                if (!used[ptr] && ptr < i) {
                    used[ptr] = true;
                    cnt++;
                } else {
                    ans += i + 1;
                }
            }
        } else {
            ans += i + 1;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
