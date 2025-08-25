#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int N = 253;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    // nxt[i][j] = nxt occurance of character j from position i or later
    // dp[i][j + 1][k] -> earliest point in the original string to find i, j,
    // and k
    string s;
    cin >> s;
    vector<vector<int>> nxt(n, vector<int>(26, n));
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    vector<vector<vector<int>>> dp(
        N, vector<vector<int>>(N, vector<int>(N, n + 1)));
    string s1, s2, s3;
    dp[0][0][0] = 0;
    int i = 0, j = 0, k = 0;
    vector<bool> ans;

    auto get = [&](int a, int b, int c, char x) {
        if (a < 0 || b < 0 || c < 0) return n + 1;
        if (dp[a][b][c] < n) {
            return nxt[dp[a][b][c]][x - 'a'] + 1;
        } else {
            return n + 1;
        }
    };
    auto getchr = [&](int which, int ind) {
        if (which == 1) {
            return ind < 0 || ind >= (int)s1.size() ? 'a' : s1[ind];
        } else if (which == 2) {
            return ind < 0 || ind >= (int)s2.size() ? 'a' : s2[ind];
        } else {
            return ind < 0 || ind >= (int)s3.size() ? 'a' : s3[ind];
        }
    };

    for (int query = 1; query <= q; query++) {
        char op;
        int choice;
        scanf("\n%c %lld", &op, &choice);

        if (op == '+') {
            char c;
            scanf(" %c", &c);
            if (choice == 1) {
                s1 += c;
                ++i;
                for (int x = 0; x <= j; x++) {
                    for (int y = 0; y <= k; y++) {
                        dp[i][x][y] = min({get(i - 1, x, y, c),
                                           get(i, x - 1, y, getchr(2, x - 1)),
                                           get(i, x, y - 1, getchr(3, y - 1))});
                    }
                }
            } else if (choice == 2) {
                s2 += c;
                ++j;
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= k; y++) {
                        dp[x][j][y] = min({get(x, j - 1, y, c),
                                           get(x - 1, j, y, getchr(1, x - 1)),
                                           get(x, j, y - 1, getchr(3, y - 1))});
                    }
                }
            } else {
                s3 += c;
                ++k;
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        dp[x][y][k] = min({get(x, y, k - 1, c),
                                           get(x - 1, y, k, getchr(1, x - 1)),
                                           get(x, y - 1, k, getchr(2, y - 1))});
                    }
                }
            }
        } else {
            if (choice == 1) {
                s1.pop_back();
                --i;
            } else if (choice == 2) {
                s2.pop_back();
                --j;
            } else {
                s3.pop_back();
                --k;
            }
        }

        if (dp[i][j][k] <= n) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }

    for (auto x : ans) {
        printf(x ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
