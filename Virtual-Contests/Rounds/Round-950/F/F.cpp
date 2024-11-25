#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool custom_comparator(vector<int>& a, vector<int>& b) {
    return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
}

void coordinate_compression(vector<int>& a, map<int, int>& mp,
                            map<int, int>& inv) {
    int n = (int)a.size();
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        mp[a[i]] = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
        inv[mp[a[i]]] = a[i];
    }
}

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> coordinates;
    vector<vector<int>> a(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        coordinates.push_back(a[i][0]);
        coordinates.push_back(a[i][1]);
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), custom_comparator);
    map<int, int> mp, inv;
    sort(coordinates.begin(), coordinates.end());
    coordinates.resize(unique(coordinates.begin(), coordinates.end()) -
                       coordinates.begin());
    coordinate_compression(coordinates, mp, inv);
    int x = 2 * (int)coordinates.size();
    vector<vector<int>> dp(x, vector<int>(x, 0));
    vector<vector<bool>> marked(x, vector<bool>(x, false));
    for (int i = 0; i < k; i++) {
        marked[mp[a[i][0]]][mp[a[i][1]]] = true;
    }
    // alter the logic to fit the grid properly
    for (int i = x - 2; i >= 0; i--) {
        for (int j = x - 2; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            if (marked[i][j]) {
                dp[i][j] = (x - i) * (x - j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (marked[i][j]) {
                break;
            }
            ans++;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
