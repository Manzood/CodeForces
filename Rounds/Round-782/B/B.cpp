#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    vector <int> a(n);
    int zeroes = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        zeroes += a[i] == 0;
        ones += a[i] == 1;
    }
    vector <int> f(n, 0);
    int cnt = 0;
    bool not_flipped = false;
    for (int i = 0; i < n && cnt < k; i++) {
        if (k % 2 == 0) {
            // flip an even number of zeroes like this
            if (a[i] == 0) {
                f[i] = 1;
                cnt++;
            }
            if (zeroes % 2 == 1) not_flipped = true;
        } else {
            // check here if WA
            if (a[i] == 1) {
                if (ones % 2 == 1) {
                    f[i] = 1;
                    cnt++;
                } else {
                    f[i] = 1;
                    cnt++;
                }
            }
            if (ones % 2 == 0) not_flipped = true;
        }
    }
    if (not_flipped && cnt < k) {
        f[n-1] += 1;
        cnt++;
    }
    f[0] += k - cnt;
    string ans;
    for (int i = 0; i < n; i++) {
        if ((k - f[i]) % 2 == 1) a[i] ^= 1;
        ans += (char) (a[i] + '0');
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        printf("%lld ", f[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
