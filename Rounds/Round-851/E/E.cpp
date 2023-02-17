#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int search(int* searchspace, int s, int e, int key) {
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (searchspace[mid] - key >= 0) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

vector<int> longestSubarray(vector<int> a) {
    int n = (int)a.size();
    int SuffixSum[n + 1];
    SuffixSum[n] = 0;
    for (int i = n - 1; i >= 0; --i) SuffixSum[i] = SuffixSum[i + 1] + a[i];
    int searchspace[n];
    vector<int> val(n, 0);
    int index[n];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j == 0 || SuffixSum[i] > searchspace[j - 1]) {
            searchspace[j] = SuffixSum[i];
            index[j] = i;
            j++;
        }
        int idx = search(searchspace, 0, j - 1, SuffixSum[i + 1]);
        if (idx != -1)
            val[i] = i - index[idx] + 1;
        else
            val[i] = 0;
    }
    return val;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> f = longestSubarray(a);
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = dp[0][1] = f[0];
    for (int i = 1; i < n; i++) {
        int len = f[i];
        dp[i][0] = len;
        if (i - len >= 0) dp[i][0] += max(dp[i - len][0], dp[i - len][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (a[i] >= 0);
    }
    printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
