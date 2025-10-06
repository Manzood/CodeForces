#include <algorithm>

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int response;
    cin >> response;
    return response;
}

void solve([[maybe_unused]] int test) {
    int n = 6;
    vector<int> a = {4, 8, 15, 16, 23, 42};

    int prod = 1;
    for (int i = 0; i < n; i++) prod *= a[i];

    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[a[i] * a[j]] = {a[i], a[j]};
        }
    }

    vector<int> ans(6), tmp;
    int p1, p2, p3;

    pair<int, int> val = mp[p1 = query(1, 2)];
    tmp.push_back(val.first), tmp.push_back(val.second);
    p2 = query(2, 3);
    val = mp[p3 = query(3, 4)];
    tmp.push_back(val.first), tmp.push_back(val.second);

    sort(tmp.begin(), tmp.end());
    do {
        if (p1 == tmp[0] * tmp[1] && p2 == tmp[1] * tmp[2] &&
            p3 == tmp[2] * tmp[3]) {
            for (int i = 0; i < 4; i++) {
                ans[i] = tmp[i];
            }
            break;
        }
    } while (next_permutation(tmp.begin(), tmp.end()));

    ans[4] = (int)(sqrt(query(5, 5)) + 1e-6);
    ans[5] = prod;
    for (int i = 0; i < 5; i++) {
        ans[5] /= ans[i];
    }

    cout << "! ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
