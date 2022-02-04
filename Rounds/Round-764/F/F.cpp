#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

int query (int val) {
    cout << "+ " << val << endl;
    int answer;
    cin >> answer;
    return answer;
}

int32_t main() {
    int n;
    cin >> n;
    int low = 1;
    int high = n;
    int cnt = 0;
    int balance = 0;
    int mid;
    int diff = 0;
    while (low < high) {
        mid = (low + high) / 2;
        debug (low, high, mid);
        int rem = n - mid - 1;
        int response = query (rem + balance);
        diff += rem + balance;
        if (response > cnt) {
            low = mid + 1;
            cnt = response;
        } else {
            high = mid;
        }
        balance = n - rem - balance;
    }
    debug(mid);
    cout << "! " << mid + diff << endl;
}
