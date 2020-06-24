#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		bool ashish=false;
		int factor=1;
		bool two = (n==2);
		if (n%2==1 && n!=1) 
			ashish=true;
		while (n%2==0 && ashish==false) {
			n/=2;
			factor*=2;
		}
		if (factor > 2 && n%2==1 && n>1) {
			ashish=true;
		}
		else if (factor==2) {
			for (int i=3;i*i<=n;i++) {
				if (n%i==0) 
					ashish=true;
			}
		}	
		if (ashish || two) 
			printf("Ashishgup\n");
		else
			printf("FastestFinger\n");
	}
}
