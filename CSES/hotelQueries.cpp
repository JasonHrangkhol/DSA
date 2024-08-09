#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int>seg;
public:
	SegmentTree(int size){
		seg.resize(4*size);
	}
	void build(int index, int low, int high, vector<int>&ar){
		if(low==high){
			seg[index]=ar[low];
			return;
		}
		int mid = low+(high-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, high, ar);
		seg[index]= max(seg[2*index+1], seg[2*index+2]);
	}
	int query(int index, int low, int high, int x){
		if(x>seg[index])
			return -1;

		if(low==high){
			seg[index]-=x;
			return low;
		}
		int mid = low+(high-low)/2, ans;
		if(x<=seg[2*index+1]){
			ans = query(2*index+1, low, mid, x);
		}
		else{
			ans =  query(2*index+2, mid+1, high, x);
		}
		seg[index]=max(seg[2*index+1], seg[2*index+2]);
		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>freeRooms(n);
	for(int i=0; i<n; i++)
		cin>>freeRooms[i];
	SegmentTree segmentTree(n);
	segmentTree.build(0, 0, n-1, freeRooms);
	while(m--){
		int room;
		cin>>room;
		cout<<segmentTree.query(0, 0, n-1, room)+1<<" ";
	}
	return 0;

} 