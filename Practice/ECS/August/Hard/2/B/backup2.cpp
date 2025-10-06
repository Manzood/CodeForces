#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void modify(int ind, int val, bool f, vector<vector<bool>>& vis, string& a,
            string& b, string& s, int len) {
    if (vis[ind][f]) {
        if (f) {
            if (b[ind] != '?') return;
        } else {
            if (a[ind] != '?') return;
        }
    }
    vis[ind][f] = true;  // TODO check if this is correct

    int n = (int)a.size();
    if (!f && ind < n - len) return;

    if (f) {
        b[ind] = (char)val + '0';
    } else {
        a[ind] = (char)val + '0';
    }

    if (s[ind] == '0') {
        modify(ind, val, !f, vis, a, b, s, len);
    } else if (s[ind] == '1') {
        modify(ind, !val, !f, vis, a, b, s, len);
    }

    if (f) {
        modify(n - ind - 1, val, f, vis, a, b, s, len);
    } else {
        int cur = ind - (n - len);
        cur = len - cur - 1;
        cur += n - len;

        modify(cur, val, f, vis, a, b, s, len);
    }
}

bool check(string& a, string& b, string& s, int len) {
    int n = (int)a.size();
    for (int i = 0; i < n - len; i++) {
        if (a[i] != '0') return false;
        if (s[i] != '?' && b[i] != s[i]) return false;
    }

    for (int i = 0; i < n / 2; i++) {
        if (b[i] != b[n - i - 1]) return false;
    }
    for (int i = n - len; i < n; i++) {
        int other = i - (n - len);
        other = len - other - 1;
        other += n - len;

        if (a[i] != a[other]) return false;
    }

    for (int i = n - len; i < n; i++) {
        if (s[i] == '?')
            continue;
        else if (s[i] == '0') {
            if (a[i] != '?' && b[i] != '?') {
                if (a[i] != b[i]) {
                    return false;
                }
            }
        } else {
            if (a[i] != '?' && b[i] != '?') {
                if (a[i] == b[i]) {
                    return false;
                }
            }
        }
    }

    if (b[0] != '1' || b[n - 1] != '1' || a[n - len] != '1' || a[n - 1] != '1')
        return false;

    return true;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = (int)s.size();

    if (s[n - 1] == '1') {
        printf("0\n");
        return;
    }
    s[n - 1] = '0';

    int ans = 0;
    for (int len = 1; len < n; len++) {
        string a(n, '?'), b(n, '?');
        for (int i = 0; i < n - len; i++) {
            a[i] = '0';
        }

        vector<vector<bool>> vis(n, vector<bool>(2, false));

        for (int i = 0; i < n - len; i++) {
            if (s[i] == '?') continue;
            modify(i, (int)(s[i] - '0'), true, vis, a, b, s, len);
        }

        if (check(a, b, s, len)) {
            int cur = 1;
            for (int i = 0; i < n; i++) {
                if (a[i] != '?' && b[i] != '?') continue;

                if (s[i] == '?') {
                    if (a[i] == '?' && b[i] == '?')
                        cur *= 4;
                    else if (a[i] == '?' || b[i] == '?')
                        cur *= 2;
                } else {
                    if (a[i] == '?' && b[i] == '?') {
                        cur *= 2;
                    }
                }
            }

            ans += cur;
        }

        debug(len, a, b, check(a, b, s, len), ans);
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
