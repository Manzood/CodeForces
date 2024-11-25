#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    string s;
    cin >> s;
    vector <int> left;
    vector <int> right;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'l') {
            left.push_back(i+1);
        }
        else {
            right.push_back(i+1);
        }
    }
    int leftptr = 0, rightptr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'l') 
            printf("%d\n", left[leftptr++]);
        else 
            printf("%d\n", right[rightptr++]);
    }
}