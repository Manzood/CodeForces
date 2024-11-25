#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		string res;
		for (int i=0;i<s.size();i++) {
			if (i==0 || i==s.size()-1)
				res+=s[i];
			else {
				if (i%2)
					res+=s[i];
			}
		}
		cout<<res<<endl;
	}
}