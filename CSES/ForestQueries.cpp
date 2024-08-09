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
	vector<vector<char>>ar(n, vector<char>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>ar[i][j];

	vector<vector<int>>prefixSum(n+1, vector<int>(n+1, 0));
	for(int i=1; i<=n; i++){
		int count=0;
		for(int j=1; j<=n; j++){
			if(ar[i-1][j-1]=='*')
				count++;
			prefixSum[i][j]=count+prefixSum[i-1][j];
		}
	}
		
	while(q--){
		int y1, x1, y2, x2;
		cin>>x1>>y1>>x2>>y2;
		int ans= prefixSum[x2][y2]-prefixSum[x1-1][y2]-prefixSum[x2][y1-1]+prefixSum[x1-1][y1-1];
		cout<<ans<<endl;
	}
	return 0;

} 