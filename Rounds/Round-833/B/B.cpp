#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<int>& cnt, int num) {
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > num) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    int ans = 0;
    for (int j = 1; j <= 150 && j <= n; j++) {
        vector<int> cnt(10, 0);
        int num = 0;
        for (int i = 0; i < j; i++) {
            if (cnt[s[i] - '0'] == 0) num++;
            cnt[s[i] - '0']++;
        }
        ans += check(cnt, num);
        for (int i = j; i < n; i++) {
            if (cnt[s[i] - '0'] == 0) num++;
            cnt[s[i] - '0']++;
            cnt[s[i - j] - '0']--;
            if (cnt[s[i - j] - '0'] == 0) num--;
            ans += check(cnt, num);
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
