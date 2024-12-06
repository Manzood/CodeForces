#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(int ind, int n) {
    if (ind < 0 || ind >= n) return false;
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(3));
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i][j]);
        }
    }
    int tot = 0;
    for (int i = 0; i < n; i++) tot += a[i][0];
    int target = (tot + 2) / 3;
    vector<vector<int>> orders = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                                  {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    vector<pair<int, int>> indices(3);
    bool found = false;
    for (int i = 0; i < 6; i++) {
        vector<int> order = orders[i];
        int x = 0;
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            int ind = order[j];
            int sum = 0;
            int start = x;
            while (x < n && sum < target) {
                sum += a[x][ind];
                x++;
            }
            if (sum >= target) cnt++;
            indices[ind] = {start, x - 1};
        }
        if (cnt == 3) {
            found = true;
            break;
        }
    }
    if (found) {
        printf("%lld %lld %lld %lld %lld %lld\n", indices[0].first + 1,
               indices[0].second + 1, indices[1].first + 1,
               indices[1].second + 1, indices[2].first + 1,
               indices[2].second + 1);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
