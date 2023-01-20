#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getmoves(vector<int>& a, vector<bool>& correct, vector<int>& pos) {
    int n = (int)a.size();
    int retval = 0;
    int ind = 0;
    while (ind < n) {
        while (ind < n && correct[ind]) ind++;
        if (ind == n) break;
        swap(a[ind], a[pos[ind]]);
        debug(ind);
        debug(a, correct);
        retval++;
        correct[ind] = true;
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), pos(n);
    vector<bool> correct(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i] - 1] = i;
    }
    bool found_pair = false;
    int pair_ind = -1;
    bool found_one = false;
    int single_ind = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == i) correct[i] = true;
        if (i > 0 && a[i] == i && a[i - 1] == i + 1) {
            found_pair = true;
            pair_ind = i;
        } else if (a[i] == i) {
            found_one = true;
            single_ind = i;
        } else if (i == 0 && a[i] == 2) {
            single_ind = 0;
            found_one = true;
        }
    }
    int ans = 0;
    if (found_pair) {
        correct[pair_ind] = true;
        correct[pair_ind - 1] = true;
        ans = getmoves(a, correct, pos);
    } else if (found_one) {
        if (single_ind > 0) {
            correct[single_ind] = true;
            correct[single_ind - 1] = true;
            swap(a[single_ind - 1], a[pos[single_ind]]);
            ans = getmoves(a, correct, pos) + 1;
        } else {
            correct[single_ind] = true;
            correct[single_ind + 1] = true;
            swap(a[single_ind + 1], a[pos[0]]);
            ans = getmoves(a, correct, pos) + 1;
        }
    } else {
        bool d = false;
        bool s = false;
        // int d_ind = -1, s_ind = -1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && correct[i] && correct[i - 1]) {
                d = true;
                // d_ind = i;
            } else if (correct[i]) {
                s = true;
                // s_ind = i;
            }
        }
        if (d) {
            // swap(a[pos[d_ind - 1]], a[d_ind]);
            // swap(a[pos[d_ind]], a[d_ind - 1]);
            // correct[d_ind] = true;
            // correct[d_ind - 1] = true;
            // ans = getmoves(a, correct, pos) + 2;
            ans = getmoves(a, correct, pos) + 1;
        } else if (s) {
            // swap(a[pos[s_ind - 1]], a[s_ind]);
            // correct[s_ind] = true;
            ans = getmoves(a, correct, pos) + 1;
        } else {
            // check if already correct array
            bool in = true;
            for (int i = 0; i < n; i++) {
                if (a[i] - 1 != i) in = false;
            }
            if (in) {
                ans = 1;
            } else {
                ans = getmoves(a, correct, pos);
            }
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
