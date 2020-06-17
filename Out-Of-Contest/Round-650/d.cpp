#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
//loop through all the found indexes to check sum

bool check (char a, char b) {
	if (a>b) return true;
	else return false;
}

int main() {
	int q;
	cin>>q;
	while (q--) {
		string s;
		cin>>s;
		int m;
		scanf("%d",&m);
		vector <int> b(m);
		for (int i=0;i<m;i++) {
			scanf("%d",&b[i]);
		}
		sort (s.begin(),s.end(),check);
		int index=0;
		vector <char> res(m);
		set <int> occupied;
		
		for (int i=0;i<m;i++) {
			if (b[i]==0 && occupied.count(i)==0) {
				//debug(s[index]);
				res[i]=s[index++];
				occupied.insert(i);
				for (int j=0;j<m;j++) {
					if (b[j]>0)
						b[j]-=(abs(i-j));
				}
			}
		}
		for (char x: res) 
			cout<<x;
		cout<<endl;
	}
}