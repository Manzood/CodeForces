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
        string s1, s2;
        cin >> s1 >> s2;
        vector <int> s(n, 0);
        vector <bool> used(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            s[i] = s1[i] + s2[i] - '0' - '0';
            if (s[i] == 0) {
                if (i > 0 && s[i-1] == 2 && !used[i-1]) {
                    ans += 2;
                    used[i] = true;
                } else {
                    ans++;
                }
            } else if (s[i] == 1) {
                ans += 2;
            } else {
                if (i > 0 && s[i-1] == 0 && !used[i-1]) {
                    ans++;
                    used[i] = true;
                }
            }
            // printf("%lld %lld\n", i, ans);
        }
        printf("%lld\n", ans);
    }
}
