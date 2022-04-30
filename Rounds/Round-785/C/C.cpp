#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

const int mod = (int) 1e9 + 7;
using namespace std;
#define int long long

vector <vector <int>> dp(40001, vector <int> (500, 0));
int num = 0;

void precompute(int n) {
    vector <int> palindromic;
    for (int i = 1; i <= 9; i++) {
        int val = i;
        if (val <= n) palindromic.push_back(val);
    }
    for (int i = 1; i <= 9; i++) {
        int val = 10 * i + i;
        if (val <= n) palindromic.push_back(val);
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int val = 100 * i + 10 * j + i;
            if (val <= n) palindromic.push_back(val);
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int val = 1000 * i + 100 * j + 10 * j + i;
            if (val <= n) palindromic.push_back(val);
        }
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                int val = 10000 * i + 1000 * j + 100 * k + 10 * j + i;
                if (val <= n) palindromic.push_back(val);
            }
        }
    }
    num = palindromic.size();
    for (int j = 0; j < num; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < num; j++) {
            if (j > 0) dp[i][j] = dp[i][j-1];
            if (i - palindromic[j] >= 0) {
                dp[i][j] += dp[i - palindromic[j]][j];
            }
            dp[i][j] %= mod;
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int ans = dp[n][num - 1];
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    precompute(40000);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
