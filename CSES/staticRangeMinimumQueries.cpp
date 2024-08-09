#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int>segmentTree;
public:
	SegmentTree(int size){
		segmentTree.resize(4*size);
	}
	void build(int index, int low, int high, vector<int>&ar){
		if(low==high){
			segmentTree[index]=ar[low];
			return;
		}
		int mid = low+(high-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, high, ar);
		segmentTree[index]=min(segmentTree[2*index+1], segmentTree[2*index+2]);
	}
	int query(int index, int low, int high, int l, int r){
		if(r<low || l>high)
			return INT_MAX;
		if(l<=low && high<=r)
			return segmentTree[index];
		int mid = low+(high-low)/2;
		return min(query(2*index+1, low, mid, l, r), query(2*index+2, mid+1, high, l, r));
	}

};

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n,q;
	cin>>n>>q;
	cout<<n<<endl;
	vector<int>ar(n);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	for(int i=0; i<n; i++)
		cout<<ar[i]<<endl;

	SegmentTree segmentTree(n);
	segmentTree.build(0, 0, n-1, ar);
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = segmentTree.query(0, 0, n-1, a-1, b-1);
		cout<<ans<<endl;
	}
	return 0;

} 