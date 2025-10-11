#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> ans, val;
vector<pair<int, int>> swaps;

int throwat(int x) {
    cout << "throw " << x + 1 << endl;
    int response;
    cin >> response;
    return response;
}

int swapat(int x) {
    cout << "swap " << x + 1 << endl;
    int res = throwat(x + 1);
    int n = (int)ans.size();

    swap(ans[x], ans[x + 1]);
    swap(val[x], val[x + 1]);
    ans[x + 1] = res;
    ans[x] = x + val[x] < n ? ans[x + val[x]] + 1 : 1;
    swaps.push_back({x, x + 1});

    return res;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    ans.assign(n, -1);
    val.assign(n, -1);
    swaps.clear();

    ans[n - 2] = throwat(n - 2);
    val[n - 2] = ans[n - 2] == 2 ? 1 : 2;

    cout << "swap " << n - 1 << endl;
    swaps.push_back({n - 2, n - 1});
    swap(ans[n - 2], ans[n - 1]);
    swap(val[n - 2], val[n - 1]);
    int res = throwat(n - 2);
    ans[n - 2] = res;
    val[n - 2] = ans[n - 2] == 2 ? 1 : 2;
    ans[n - 1] = 1;

    debug(val, ans);
    for (int i = n - 3; i >= 0; i--) {
        if (ans[i + 1] != ans[i + 2]) {
            res = throwat(i);
            ans[i] = res;
            if (res == ans[i + 1] + 1) {
                val[i] = 1;
            } else {
                val[i] = 2;
            }
        } else {
            int cur = ans[i + 1];
            res = swapat(i);
            if (res == cur + 1) {
                val[i + 1] = 1;
            } else {
                val[i + 1] = 2;
            }
        }
        debug(val, ans);
    }

    while (swaps.size()) {
        pair<int, int> cur = swaps.back();
        swap(val[cur.first], val[cur.second]);
        swaps.pop_back();
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
