#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int dp[n][2][2]; // dp[i][0] means no carry created, dp[i][j][0] means no carry recieved
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
            dp[i][1][0] = 0;
            dp[i][1][1] = 0;
        }

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++){
            // recieved carry means compare with carry creation states two indices ago
            // otherwise compare with no carry states
            int val = s[i] - '0' + 1;
            // if (s[i] == '0') val = 10;
            // else val = s[i] - '0';

            // if ((int) s.size() == 0) val--;

            dp[i][0][0] = max(val, 0LL);
            dp[i][0][1] = max(val, 0LL);

            int cval = 0;

            val += 10;
            for (int j = 9; j >= 0; j--) {
                if (val - j > 9) break;
                cval++;
            }

            dp[i][1][0] = cval;
            dp[i][1][1] = cval;

            if (i > 1) {
                // carry could have been recieved

                // no carry creation state
                if (dp[i-2][0][0]) dp[i][0][0] *= dp[i-2][0][0];
                if (dp[i-2][0][1]) dp[i][0][0] *= dp[i-2][0][1];
                if (dp[i-2][1][0]) dp[i][0][1] *= dp[i-2][1][0];
                if (dp[i-2][1][1]) dp[i][0][1] *= dp[i-2][1][1];

                // carry creation state
                if (dp[i-2][0][0]) dp[i][1][0] *= dp[i-2][0][0];
                if (dp[i-2][0][1]) dp[i][1][0] *= dp[i-2][0][1];
                if (dp[i-2][1][0]) dp[i][1][1] *= dp[i-2][1][0];
                if (dp[i-2][1][1]) dp[i][1][1] *= dp[i-2][1][1];

                // if (s[i] == '1') {
                    // could have only recieved carry
                    // dp[i][0][1] = dp[i-2][1][0];
                // }
            } else {
                dp[i][0][1] = 0;
                dp[i][1][1] = 0;
            }

            debug (i);
            debug (dp[i][1][0]);
            // debug (val);
        }

        // add all states
        int ans = 0;
        ans += dp[n-1][0][0];
        ans += dp[n-1][0][1];
        if (n > 1) {
            // debug (ans)
            ans *= max(dp[n-2][0][0] + dp[n-2][0][1], 1LL);
            // ans += dp[n-2][0][1];
            // debug (dp[n-2][0][0] + dp[n-2][0][1]);
            debug (dp[n-1][0][0]);
            debug (dp[n-1][0][1]);
        }
        ans-=2;
        // ans += dp[n-1][1][0];
        // ans += dp[n-1][1][1];

        printf("%lld\n", ans);
    }
}
