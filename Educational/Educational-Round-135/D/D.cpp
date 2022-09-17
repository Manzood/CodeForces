#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// without memoization it TLEs
int dp(int l, int r, string& s, int turn, char previous,
       vector<vector<vector<char>>>& memo) {
    if ((int)memo[l][r][previous - 'a'] != 3) {
        return (int)(memo[l][r][previous - 'a']) - 1;
    }
    int retval = 0;
    if (turn == 1) {
        retval = dp(l + 1, r, s, -1, s[l], memo);
        retval = max(retval, dp(l, r - 1, s, -1, s[r], memo));
    } else {
        if (l == r) {
            if (s[l] > previous)
                retval = 1;
            else if (s[l] < previous)
                retval = -1;
            memo[l][r][previous - 'a'] = (char)(retval + 1);
            return retval;
        }
        retval = dp(l + 1, r, s, 1, s[l], memo);
        if (retval == 0) {
            if (s[l] < previous)
                retval = -1;
            else if (s[l] > previous)
                retval = 1;
        }
        int v = dp(l, r - 1, s, 1, s[r], memo);
        if (v == 0) {
            if (s[r] < previous)
                v = -1;
            else if (s[r] > previous)
                v = 1;
        }
        retval = min(retval, v);
    }
    memo[l][r][previous - 'a'] = (char)(retval + 1);
    return retval;
}

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n;
    n = (int)s.size();
    vector<vector<vector<char>>> memo(
        n, vector<vector<char>>(n, vector<char>(26, 3)));
    int ans = dp(0, n - 1, s, 1, 'a', memo);
    if (ans == 0) {
        printf("Draw\n");
    } else if (ans == 1) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
