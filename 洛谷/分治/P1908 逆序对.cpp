#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio> 
using namespace std;
int n;
long long nums[50000010], tmp[50000010];
long long Reverse(int left, int right){
    if(right==left)
        return 0;
    int mid=(right-left)/2+left;
    long long beg=Reverse(left, mid);
    long long end=Reverse(mid+1, right);
    long long cnt=0;
	int k=left, i=left, j=mid+1;
    while(i<=mid && j<=right){
        if(nums[i]>nums[j]){
            tmp[k++]=nums[j++];
			cnt+=mid-i+1;
        }
        else{
			tmp[k++]=nums[i++];
		}
    }

	while(i<=mid){
        tmp[k++]=nums[i++];
    }
    while(j<=right){
        tmp[k++]=nums[j++];
    }
    for(int t=left; t<=right; t++)
        nums[t]=tmp[t];
    return beg+end+cnt;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> nums[i];
    cout << Reverse(0, n-1) << endl;
    return 0;
} 
