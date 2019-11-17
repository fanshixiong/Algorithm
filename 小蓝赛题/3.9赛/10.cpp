#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<double> nums1(100000), nums2(100000),nums3(100000);
int main(){
	int m,n;
	cin >> m>> n;
	int k=0, mid=(m+n)/2;
	for(int i=0; i<m; i++)
		cin >> nums1[i];
	for(int i=0; i<n; i++)
		cin >> nums2[i];
	int i=0,j=0;	
	while(i<m && j<n){
		if(nums1[i]<nums2[j]){
			nums3[k++]=nums1[i++];
		}
		else
			nums3[k++]=nums2[j++];
		if(k>=mid+1)
			break;
	}
	if(k<mid+1){
		while(i<m && k<=mid){
			nums3[k++] = nums1[i++];
		}
		while(j<n && k<=mid)
			nums3[k++] = nums2[j++];  
	}
	if((m+n)%2==0)
		cout<< (nums3[mid-1]+nums3[mid])/2 << endl;
	else
		cout<< nums3[mid] <<endl;
	return 0;
} 
