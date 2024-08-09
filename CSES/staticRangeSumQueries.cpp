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
	for(int i=0;i<n;i++)
		cin>>ar[i];
	vector<long long>prefixSum(n+1, 0);
	prefixSum[0]=0;
	for(int i=1;i<=n;i++)
		prefixSum[i]=ar[i-1]+prefixSum[i-1];
	while(q--){
		int a,b;
		cin>>a>>b;
		long long ans = prefixSum[b]-prefixSum[a-1];
		cout<<ans<<endl;
	}
	
	return 0;

} 