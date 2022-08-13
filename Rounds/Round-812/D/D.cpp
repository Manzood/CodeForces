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
    return response;
}

int solve_four(vector<int>& a) {
    int winner = a[0];
    int response = query(a[0], a[2]);
    if (response == 0) {
        response = query(a[1], a[3]);
        if (response == 1)
            winner = a[1];
        else
            winner = a[3];
    } else if (response == 1) {
        response = query(a[0], a[3]);
        if (response == 1)
            winner = a[0];
        else
            winner = a[3];
    } else {
        response = query(a[2], a[1]);
        if (response == 1)
            winner = a[2];
        else
            winner = a[1];
    }
    return winner;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    if (n == 1) {
        int response = query(1, 2);
        cout << "! " << response << endl;
    } else {
        queue<int> q;
        for (int i = 0; i < (1LL << n); i++) {
            q.push(i + 1);
        }
        while ((int)q.size() >= 4) {
            vector<int> a(4);
            for (int i = 0; i < 4; i++) {
                a[i] = q.front();
                q.pop();
            }
            int winner = solve_four(a);
            q.push(winner);
        }
        int winner = q.front();
        if ((int)q.size() == 2) {
            int a = q.front();
            q.pop();
            int b = q.front();
            winner = query(a, b) == 1 ? a : b;
        }
        cout << "! " << winner << endl;
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
