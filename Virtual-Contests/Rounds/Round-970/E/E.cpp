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
    vector<vector<int>> left(n, vector<int>(26, n));
    vector<vector<int>> right(n, vector<int>(26, n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            char c = 'a' + (char)j;
            if (i >= 2) {
                left[i][j] = left[i - 2][j] + (s[i] != c);
            } else {
                left[i][j] = s[i] != c;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            char c = 'a' + (char)j;
            if (i < n - 2) {
                right[i][j] = right[i + 2][j] + (s[i] != c);
            } else {
                right[i][j] = s[i] != c;
            }
        }
    }
    int ans = n;
    if (n % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = min(ans, right[0][i] + (n > 1 ? right[1][j] : 0LL));
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < 26; x++) {
                for (int y = 0; y < 26; y++) {
                    int val = 1;
                    if (i >= 2) val += left[i - 2][x];
                    if (i < n - 1) val += right[i + 1][x];
                    if (i >= 1) val += left[i - 1][y];
                    if (i < n - 2) val += right[i + 2][y];
                    ans = min(ans, val);
                }
            }
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
