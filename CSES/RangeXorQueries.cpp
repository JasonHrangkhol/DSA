#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n,q;
	cin>>n>>q;
	vector<int>ar(n);
	for(int i=0; i<n; i++)
		cin>>ar[i];
	vector<int>prefixXor(n+1);
	prefixXor[0]=0;
	for(int i=1;i<=n;i++)
		prefixXor[i]=ar[i-1]^prefixXor[i-1];
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = prefixXor[b]^prefixXor[a-1];
		cout<<ans<<endl;

	}

	return 0;

} 