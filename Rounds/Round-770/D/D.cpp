#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query (int i, int j, int k) {
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int response; cin >> response;
    if (response == -1) exit(1);
    return response;
}

// There has to be a better way to implement this
pair <int, int> find_four (int a, int b, int c, int d) {
    vector <int> original = {a, b, c, d};
    pair <int, int> retval = {a, b};
    int v1 = query (b, c, d);
    int v2 = query (a, c, d);
    if (v1 > v2) swap (retval.first, retval.second);
    int v3 = query (a, b, d);
    int v4 = query (a, b, c);
    if (v3 > max(v1, v2)) {
        retval = {c, d};
    } else {
        if (v3 > min(v1, v2)) {
            swap (retval.first, c);
        }
        if (v4 > max (v3, min(v1, v2))) {
            swap (retval.first, d);
        }
    }
    vector <int> temp = {retval.first, retval.second};
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < 4; i++) {
        if (original[i] == retval.first) ind1 = i;
    }
    original.erase(original.begin() + ind1);
    for (int i = 0; i < 3; i++) {
        if (original[i] == retval.second) ind2 = i;
    }
    original.erase(original.begin() + ind2);
    retval.first = original[0];
    retval.second = original[1];
    return retval;
}

// significantly better implementation
pair <int, int> better_find_four (int a, int b, int c, int d) {
    pair <int, int> retval;
    vector <int> original = {a, b, c, d};
    vector <vector <int>> x;
    for (int i = 0; i < 4; i++) {
        vector <int> temp = original;
        temp.erase (temp.begin() + i);
        x.push_back ({query (temp[0], temp[1], temp[2]), original[i]});
    }
    sort (x.begin(), x.end());
    retval = {x[0][1], x[1][1]};
    return retval;
}

void solve() {
    int n;
    cin >> n;
    int a, b;
    pair <int, int> temp = better_find_four (0, 1, 2, 3);
    a = temp.first;
    b = temp.second;
    debug (a, b);
    for (int i = 4; i + 1 < n; i += 2) {
        temp = better_find_four(a, b, i, i + 1);
        a = temp.first;
        b = temp.second;
        debug (a, b);
    }
    if (n & 1) {
        int lastind = n - 1;
        while (lastind == a || lastind == b) lastind--;
        int secind = n - 1;
        while (secind == a || secind == b || secind == lastind) secind--;
        temp = better_find_four (a, b, lastind, secind);
        a = temp.first, b = temp.second;
        debug (a, b);
    }
    cout << "! " << a + 1 << " " << b + 1 << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
