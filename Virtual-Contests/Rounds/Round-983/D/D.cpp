#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int response;
    cin >> response;
    assert(response != -1);
    if (response == -1) exit(0);
    return response;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<int> p(n, -1);
    p[1] = 0;
    // try to attach things to zero
    int cur = 2;
    vector<int> layer = {1};
    while (cur < n && query(1, cur) == 1) {
        p[cur] = 0;
        layer.push_back(cur);
        cur++;
    }

    vector<int> next_layer = {cur};
    p[cur++] = 1;
    int ind = 1;
    while (cur < n - 1 && (int)layer.size() > 1) {
        int response = query(cur, layer[ind]);
        if (response == 0) {
            p[cur] = layer[ind];
            next_layer.push_back(cur++);
        }
        ind++;
        if (ind >= (int)layer.size()) {
            layer = next_layer;
            next_layer.clear();
            ind = 0;
        }
    }

    if ((int)layer.size() == 1) {
        int val = layer[0];
        if (val == 1) val = 2;
        for (int i = cur; i < n; i++) {
            p[i] = val;
            val = i;
        }
    } else {
        if ((int)next_layer.size() > 0) {
            while (p[cur] == -1 && ind < (int)layer.size()) {
                int response = query(cur, layer[ind]);
                if (response == 0) {
                    p[cur] = layer[ind];
                }
                ind++;
            }
            ind = 0;
            while (p[cur] == -1 && ind < (int)next_layer.size() - 1) {
                int response = query(cur, next_layer[ind]);
                if (response == 0) {
                    p[cur] = next_layer[ind];
                }
                ind++;
            }
            if (p[cur] == -1) p[cur] = next_layer[ind];
        } else {
            while (ind < (int)layer.size() - 1) {
                int response = query(cur, layer[ind]);
                if (response == 0) {
                    p[cur] = layer[ind];
                    break;
                }
                ind++;
            }
            if (p[cur] == -1) p[cur] = layer[ind];
        }
    }
    cout << "! ";
    for (int i = 1; i < n; i++) {
        assert(p[i] != -1);
        cout << p[i] << " ";
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
