#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string res;
		int n0,n1,n2;
		cin>>n0>>n1>>n2;
		int odd=false;
		int lim=n1/2;
		for (int i=0;i<lim;i++) {
			res+="10";
		}
		if(lim==0) res+='0';
		for (int i=0;i<n0;i++) {
			res+='0';
		}
		for (int i=0;i<=n2;i++) {
			res+='1';
		}
		if (n1%2==1 && n1>1) {
			res+='0';
		}
		cout<<res<<endl;
	}
}
