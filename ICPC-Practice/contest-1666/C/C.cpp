#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int x[3];

bool cmp (int i, int j) {
    return x[i] < x[j];
}

void solve([[maybe_unused]] int test) {
    int y[3];
    int y_copy[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        y_copy[i] = y[i];
    }
    int indices[3] = {0, 1, 2};
    // sort (y, y + 3, cmp);
    sort (indices, indices + 3, cmp);
    sort (x, x + 3);
    for (int i = 0; i < 3; i++) {
        y[i] = y_copy[indices[i]];
    }
    // for (int i = 0; i < 3; i++) {
    //     printf("%lld ", x[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < 3; i++) {
    //     printf("%lld ", y[i]);
    // }
    // printf("\n");
    vector <vector <int>> ans;
    if (y[2] > y[0]) {
        ans.push_back({x[0], y[0], x[1], y[0]});
        if (y[1] > y[2]) {
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[2], x[2], y[2]});
        } else if (y[1] <= y[2] && y[1] >= y[0]){
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[1], x[2], y[1]});
            ans.push_back({x[2], y[1], x[2], y[2]});
        } else {
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[0], x[2], y[0]});
            ans.push_back({x[2], y[0], x[2], y[2]});
        }
    } else if (y[2] < y[0]){
        // rightmost is below
        ans.push_back({x[0], y[0], x[1], y[0]});
        if (y[1] < y[2]) {
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[2], x[2], y[2]});
        } else if (y[1] >= y[2] && y[1] <= y[0]) {
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[1], x[2], y[1]});
            ans.push_back({x[2], y[1], x[2], y[2]});
        } else {
            ans.push_back({x[1], y[0], x[1], y[1]});
            ans.push_back({x[1], y[0], x[2], y[0]});
            ans.push_back({x[2], y[0], x[2], y[2]});
        }
    } else {
        ans.push_back({x[0], y[0], x[2], y[2]});
        ans.push_back({x[1], y[0], x[1], y[1]});
    }
    printf("%lld\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        for (int j = 0; j < 4; j++) {
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
