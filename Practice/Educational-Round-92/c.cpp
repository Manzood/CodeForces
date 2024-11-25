#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int)x.size()

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int mx = 0;
        for (char i = '0'; i <= '9'; i++) {
            for (char j = '0'; j <= '9'; j++) {
                int count = 0;
                for (int ind = 0; ind < sz(s); ind++) {
                    if (count % 2 == 0 && s[ind] == i) {
                        count++;
                    }
                    else if (count % 2 == 1 && s[ind] == j) {
                        count++;
                    }
                }
                if (i != j && count % 2 == 1)
                    count--;
                mx = max(count, mx);
            }
        }
        printf("%d\n", sz(s)-mx);
    }
}