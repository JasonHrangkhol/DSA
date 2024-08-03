#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int>segmentTree;
public:
	SegmentTree(int size){
		segmentTree.resize(4*size);
	}
	//build a segment tree where every node stores the minimum of the range represented by the node
	void build(int index, int low, int right, vector<int>&ar) {
		if(low==right){
			segmentTree[index]=ar[low];
			return;
		}
		int mid = low+(right-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, right, ar);
		segmentTree[index] = segmentTree[2*index+1]+segmentTree[2*index+2];
	}
	//query to find the sum of array elements from l to r
	int query(int index, int low, int right, int l, int r) {
		if(l>right || r<low)
			return 0;
		if(l<=low && r>=right)
			return segmentTree[index];
		int mid = low+(right-low)/2;
		return query(2*index+1, low, mid, l, r)+query(2*index+2, mid+1, right, l, r);


	}
	//point update -> to update a specific array index
	void update(int index, int low, int right, int i, int val) {
		if(low==right) {
			segmentTree[index]=val;
			return;
		}	
		int mid=low+(right-low)/2;
		if(i<=low)
			update(2*index+1, low, mid, i, val);
		else
			update(2*index+2, mid+1, right, i, val);
		segmentTree[index]=segmentTree[2*index+1]+segmentTree[2*index+2];
	}
};