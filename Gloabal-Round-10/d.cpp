#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        s += s;
        int ans = 0;
        bool flag = false;
        int i = 0;
        char last;
        int count;
        while (!flag) {
            if (i == 0) {
                last = s[i];
                count = 1;
            }
            else if (i >= n && s[i] != last) {
                flag = true;
            }
            else {
                if (s[i] == last) {
                    count++;
                    if (count % 3 == 0) {
                        if (s[i] == 'R') {
                            s[i] = 'L';
                        }
                        else {
                            s[i] = 'R';
                        }
                        last = s[i];
                        count = 1;
                        ans++;
                    }
                }
                else {
                    count = 1;
                    last = s[i];
                }
            }
            i++;
        }
        printf("%lld\n", ans);
    }
}