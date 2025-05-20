#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(string s, int y) {
    cout << s << y << endl;
    int response;
    cin >> response;
    if (response == -1) exit(0);
    return response;
}

int add(int y) { return query("add ", y); }
int mul(int y) { return query("mul ", y); }
int div(int y) { return query("div ", y); }
void digit() {
    cout << "digit" << endl;
    int response;
    cin >> response;
    if (response == -1) exit(0);
    assert(response == 1);
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;

    digit();
    digit();
    add(-8);
    add(-4);
    add(-2);
    add(-1);
    add(n - 1);

    cout << "!" << endl;
    int response;
    cin >> response;
    if (response == -1) exit(0);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
