#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int m = 0; 
        int goodlen = 0;
        char ch1, ch2;
        set <pair <char, char>> check;
        for (int i = 0; i < s.size(); i++) {
            if (goodlen == 0) {
                ch1 = s[i];
                goodlen++;
            }
            else if (goodlen == 1) {
                ch2 = s[i];
                goodlen++;
            }
            else {
                if (goodlen % 2 == 0) {
                    if (s[i] == ch1) 
                        goodlen++;
                    else {
                        if (check.count(make_pair(ch1, ch2))) 
                            m += goodlen;
                        else 
                            m = max(m, goodlen);
                        check.insert(make_pair(ch1, ch2));
                        goodlen = 0;
                    }
                }
                else {
                    if (s[i] == ch2) 
                        goodlen++;
                    else {
                        if (check.count(make_pair(ch1, ch2))) 
                            m += goodlen;
                        else 
                            m = max(m, goodlen);
                        check.insert(make_pair(ch1, ch2));
                        goodlen = 0;
                    }
                }
            }
        }
        if (check.count(make_pair(ch1, ch2))) 
            m += goodlen;
        else
            m = max(m, goodlen);
        printf("%d\n", (int)s.size() - m);
    }
}