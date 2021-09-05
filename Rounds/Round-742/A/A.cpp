#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        string out;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') out += 'D';
            else if (s[i] == 'D') out += 'U';
            else out += s[i];
        }
        cout << out << "\n";
    }
}
